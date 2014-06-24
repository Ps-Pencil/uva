#include<cstdio>
#include<vector>
#include<cstring>
#include<set>
#include<map>
#define LEFT(p) p<<1
#define RIGHT(p) (p<<1)+1
#define N 1025000
using namespace std;

struct Node
{
	int start,end,sum;
}ST[N<<2],ST2[60000];

struct query
{
	char c;
	int l,r;
}q[2000];

bool pirate[N+1];
int qn,tot,tot_interval,tot_node;
int hashtable[N+1];
bool bound[N+1];
int state[60000];   // 0 - normal, 1 - set , 2 - clear , 3 flip

int split()
{
	tot_interval = 0;
	int last = 0;
	int count = 0;
	for(int i=0;i<tot;i++)
	{
		if(bound[i]==1)
		{
				if(last!=0 && last != i)
				{
					Node y;
					y.start = last;
					y.end = i-1;
					y.sum = count;
					ST2[tot_interval++] = y;
				}
				Node x;
				x.start = x.end = i;
				x.sum = pirate[i];
				ST2[tot_interval++] = x;
				last = i+1;
				count = 0;
		}
		else if(pirate[i]==1)
			count++;
	}
	return 0;
}

int build(int p,int L,int R)
{
	tot_node++;
	if(L==R)
		ST[p] = ST2[L];
	else
	{
		build(LEFT(p),L,(L+R)/2);
		build(RIGHT(p),(L+R)/2+1,R);
		ST[p].start = ST[LEFT(p)].start;
		ST[p].end = ST[RIGHT(p)].end;
		ST[p].sum = ST[LEFT(p)].sum + ST[RIGHT(p)].sum;
	}
	return 0;
}
int propagate(int p)
{
	if(state[p]==0) return 0;
	if(state[p] == 1||state[p]==2)
	{
		ST[p].sum = (state[p]==1)?ST[p].end-ST[p].start+1:0;
		state[LEFT(p)] = state[RIGHT(p)] = state[p];
	}
	else if(state[p]==3){
		ST[p].sum = ST[p].end - ST[p].start + 1 - ST[p].sum;
		state[LEFT(p)] = 3 - state[LEFT(p)];
		state[RIGHT(p)] = 3 - state[RIGHT(p)];
	}
	state[p] = 0;
	return 0;
}
int update(int p, int i,int j,int k)
{
	propagate(p);
	if(ST[p].start > j || ST[p].end < i) return 0;
	if(ST[p].start >=i && ST[p].end <= j) {
		if(k == 1 || k == 2)
		{
			ST[p].sum = (k==1)?ST[p].end-ST[p].start+1:0;
			state[LEFT(p)] = state[RIGHT(p)] = k;
		}
		else if(k==3)
		{
			ST[p].sum = ST[p].end - ST[p].start + 1 - ST[p].sum;
			state[LEFT(p)] = 3 - state[LEFT(p)];
			state[RIGHT(p)] = 3 - state[RIGHT(p)];
		}
		return 0;
	}
	update(LEFT(p),i,j,k);
	update(RIGHT(p),i,j,k);
	ST[p].sum = ST[LEFT(p)].sum+ST[RIGHT(p)].sum;
	return 0;
}
int rsq(int p,int i,int j)
{
	propagate(p);
	if(ST[p].start > j || ST[p].end <i) return 0;
	if(ST[p].start >= i && ST[p].end <= j){
		return ST[p].sum;
	}
	else
	{
		return rsq(LEFT(p),i,j) + rsq(RIGHT(p),i,j);
	}
	return 0;
}
int debug(int p)
{
	printf("%d %d %d %d (%d)\n",p,ST[p].start,ST[p].end,ST[p].sum,state[p]);
	if(LEFT(p)<tot_node)
	debug(LEFT(p));
	if(RIGHT(p)<tot_node)
	debug(RIGHT(p));
	return 0;
}
int main()
{
	int TC;
	scanf("%d",&TC);
	for(int TCC = 1;TCC<=TC;TCC++)
	{
		memset(hashtable,0,sizeof(hashtable));
		memset(bound,0,sizeof(bound));
		memset(state,0,sizeof(state));
		tot = 0;tot_node = 0;
		printf("Case %d:\n",TCC);
		int M;
		scanf("%d",&M);
		for(int i=0;i<M;i++)
		{
			int T;
			char str[100];
			scanf("%d%s",&T,str);
			for(int j=0;j<T;j++)
				for(int k = 0;str[k]!='\0';k++)
					pirate[tot++] = str[k]-'0';
		}
		scanf("%d",&qn);
		for(int i=0;i<qn;i++)
		{
			char str[100];
			int a,b;
			scanf("%s %d %d",str,&a,&b);
			q[i].c = str[0];
			q[i].l = a;
			q[i].r = b;
			bound[a] = bound[b] = 1;
		}
		split();
		build(1,0,tot_interval-1);
		int querynumber = 0;
		for(int i=0;i<qn;i++)
		{
			if(q[i].c == 'F')
				update(1,q[i].l,q[i].r,1);
			else if(q[i].c == 'E')
				update(1,q[i].l,q[i].r,2);
			else if(q[i].c == 'I')
				update(1,q[i].l,q[i].r,3);
			else if(q[i].c == 'S')
				printf("Q%d: %d\n",++querynumber,rsq(1,q[i].l,q[i].r));
			//debug(1);
		//	printf("\n");
		}
	}
	return 0;
}