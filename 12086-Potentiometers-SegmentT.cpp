#include<cstdio>
#include<vector>
#include<cstring>
#include<algorithm>
#define LEFT(p) p<<1
#define RIGHT(p) (p<<1)+1
using namespace std;

typedef vector<int> vi;

int hm[200001],resistance[200001], st[801000];
int N;

int build(int p, int L, int R)
{
	if(L==R)
	{
		st[p] = resistance[L];
		hm[L] = p;
	}
	else
	{
		build(LEFT(p),L,(L+R)/2);
		build(RIGHT(p),(L+R)/2+1,R);
		st[p] = st[LEFT(p)]+st[RIGHT(p)];
	}
	return 0;
}

int update(int index,int value)
{
	int a = hm[index];
	st[a] = value;
	while(true){
		a = a/2;
		st[a] = st[LEFT(a)] + st[RIGHT(a)];
		if(a==1)
			break;
	}
	return 0;
}
int rsq(int p, int L,int R,int i,int j)
{
	if(L>j||R<i)
		return 0;
	if(L>=i&&R<=j)
		return st[p];
	int s1 = rsq(LEFT(p),L,(L+R)/2,i,j);
	int s2 = rsq(RIGHT(p),(L+R)/2+1,R,i,j);
	return s1+s2;
}
int main()
{
	int TC = 1;
	while(scanf("%d",&N),N)
	{
		if(TC!=1)
			printf("\n");
		printf("Case %d:\n",TC++);
		memset(hm,0,sizeof(hm));
		memset(resistance,0,sizeof(resistance));
		memset(st,0,sizeof(st));
		for(int i=1;i<=N;i++)
		{
			int x;
			scanf("%d",&x);
			resistance[i] = x;
		}
		build(1,1,N);
		char str[10];
		while(scanf("%s",str))
		{
			if(str[0]=='E')
				break;
			int a,b;
			scanf("%d %d",&a,&b);
			if(str[0] == 'M')
			{
				printf("%d\n",rsq(1,1,N,a,b));
				continue;
			}
			if(str[0] == 'S')
				update(a,b);
		}
	}
	return 0;
}