#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>

using namespace std;

//输入数据 
char  C[ 1005 ];
int   X[ 1005 ];
int   Y[ 1005 ];

//操作区间端点 
int   S[ 2005 ];

//离散化节点数据 
int   L[ 4005 ];
int   R[ 4005 ];
int   Sum0[ 4005 ];
int   Sum1[ 4005 ];

//segment_tree__begin
typedef struct tnode
{
	tnode* Lchild;
	tnode* Rchild;
	int    Lvalue;
	int    Rvalue;
	int    Color;//记录节点颜操作：0.置0；1.置1；2.取反；-1.无操作 
	int    Sum[2];
}tnode;
tnode Node[ 8008 ];

tnode* Root;
int    Count;
tnode* buildtree( int a, int b ) {
	tnode* np = &Node[ Count ++ ];
	np->Lvalue = L[a];
	np->Rvalue = R[b];
	np->Color  = -1;
	if ( a < b ) {
		np->Lchild = buildtree( a, (a+b)/2 );
		np->Rchild = buildtree( (a+b)/2+1, b );
		np->Sum[0] = np->Lchild->Sum[0]+np->Rchild->Sum[0];
		np->Sum[1] = np->Lchild->Sum[1]+np->Rchild->Sum[1];
	}else {
		np->Lchild = NULL;
		np->Rchild = NULL;
		np->Sum[0] = Sum0[a];
		np->Sum[1] = Sum1[a];
	}
	return np;
} 
void segment_tree( int a, int b ) {
	Count = 0;
	Root = buildtree( a, b );
}
void Deal( tnode* r, int v ) {
	/* 核心操作，节点状态更新 */ 
	if ( v == 2 ) {
		r->Color = 1 - r->Color;//相反的操作编号加和为1 
		swap( r->Sum[0], r->Sum[1] );
	}else {
		r->Color = v;
		r->Sum[v] = r->Rvalue-r->Lvalue+1;
		r->Sum[!v] = 0;
	}
}
void Insert( tnode*r, int a, int b, int v ) {
	if ( r->Lvalue == a && r->Rvalue == b ) {
		Deal( r, v );return;
	}
	if ( r->Color != -1 ) {
		Deal( r->Lchild, r->Color );
		Deal( r->Rchild, r->Color );
		r->Color = -1;
	}
	if ( b <= r->Lchild->Rvalue ) 
		Insert( r->Lchild, a, b, v );
	else if ( a >= r->Rchild->Lvalue ) 
		Insert( r->Rchild, a, b, v );
	else {
		Insert( r->Lchild, a, r->Lchild->Rvalue, v );
		Insert( r->Rchild, r->Rchild->Lvalue, b, v );
	}
	r->Sum[0] = r->Lchild->Sum[0]+r->Rchild->Sum[0];
	r->Sum[1] = r->Lchild->Sum[1]+r->Rchild->Sum[1];
}
int Query( tnode* r, int a, int b ) {
	if ( r->Color == 1 || r->Color == 0 ) 
		return (b-a+1)*r->Color;
	if ( r->Lvalue == a && r->Rvalue == b )
		return r->Sum[1];
	int v = 0;
	if ( b <= r->Lchild->Rvalue ) 
		v = Query( r->Lchild, a, b );
	else if ( a >= r->Rchild->Lvalue ) 
		v = Query( r->Rchild, a, b );
	else
		v = Query( r->Lchild, a, r->Lchild->Rvalue )+
			Query( r->Rchild, r->Rchild->Lvalue, b );
	if ( r->Color == -1 ) return v; 
	else return b-a+1-v;
}
void Insert( int a, int b, int v ) {
	Insert( Root, a, b ,v );
}
int Query( int a, int b ) {
	return Query( Root, a, b );
}
//segment_tree__end 

char data[ 1024005 ];
char save[ 1000 ];
int  number;

//统计每个区间中0、1个数 
int count01( int x, int y, char c ) 
{
	int sum = 0;
	for ( int i = x ; i <= y ; ++ i )
		if ( data[i] == c )
			sum ++;
	return sum;
}

//建立离散化区间 
int addsegment( int left, int now ) 
{
	if ( left < now ) {
		L[number] = left;
		R[number] = now-1;
		number ++;
	}
	L[number] = R[number] = now;
	number ++;
	return now+1;
}

int cmp( const void *a, const void *b )
{
	return *((int *)a) - *((int *)b);
}

int main()
{
	int  T,N,M,Q;
	while ( scanf("%d",&T) != EOF ) 
	for ( int t = 1 ; t <= T ; ++ t ) {
		int count = 0;
		scanf("%d",&N);
		for ( int i = 0 ; i < N ; ++ i ) {
			scanf("%d%s",&M,save);
			int len = strlen(save);
			for ( int j = 0 ; j < M ; ++ j ) {
				strcpy( &data[count], save );
				count += len;
			}
		}
		
		scanf("%d",&Q);
		for ( int i = 0 ; i < Q ; ++ i ) {
			scanf("%s%d%d",&C[i],&X[i],&Y[i]);
			if ( X[i] >= count ) X[i] = count-1;
			if ( Y[i] >= count ) Y[i] = count-1;
		}
		
		//离散化 
		for ( int i = 0 ; i < Q ; ++ i ) {
			S[i+0] = X[i]; 
			S[i+Q] = Y[i];
		}
		qsort( S, 2*Q, sizeof( int ), cmp );

		int s = 0; number = 0;
		//最左区间
		if ( S[0] != 0 ) 					 
			s = addsegment( s, S[0] );
		else s = addsegment( 0, 0 );
		//中间区间 
		for ( int i = 1 ; i < 2*Q ; ++ i ) {
			if ( S[i] == S[i-1] ) continue;
			s = addsegment( s, S[i] );
		}
		//最右区间
		if ( S[2*Q-1] != count-1 )			 
			s = addsegment( s, count-1 );
		
		//统计每个区间中0、1个数 
		for ( int i = 0 ; i < number ; ++ i ) {
			Sum0[i] = count01( L[i], R[i], '0' );
			Sum1[i] = count01( L[i], R[i], '1' );
		}
		
		//建立离散化线段树 
		segment_tree( 0, number-1 );

		printf("Case %d:\n",t);
		int query = 1;
		for ( int i = 0 ; i < Q ; ++ i ) {
			if ( C[i] == 'F' ) Insert( X[i], Y[i], 1 );
			if ( C[i] == 'E' ) Insert( X[i], Y[i], 0 );
			if ( C[i] == 'I' ) Insert( X[i], Y[i], 2 );
			if ( C[i] == 'S' ) printf("Q%d: %d\n",query++,Query( X[i], Y[i] ));
		}
	}
	return 0;
}
