#include<cstdio>
#include<cstring>
#include<bitset>
using namespace std;
int MIS;
bitset<101> best;
int n,k;
bool adj[200][200];
int find(bitset<101> bm,int k)
{
	if(k>MIS)
		{
			MIS = k;
			best = bm;
		}
	int last;
	for(last=n ;last>=0&&bm[last]!=1;last--)
		;
	for(int i=last+1;i<n;i++)
		if(!bm[i])
		{
			bool ok = true;
			for(int j=0;j<n;j++)
			if(bm[j] && adj[i][j])
				{
					ok = false;
					break;
				}
			if(ok)
			{
				bm[i] = 1;
				find(bm,k+1);
				bm[i] = 0;
			}
		}
	return 0;
	
}
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		best.reset();
		MIS = 0;
		memset(adj,0,sizeof(adj));
		scanf("%d %d",&n,&k);
		for(int i=0;i<k;i++)
		{
			int a,b;
			scanf("%d %d",&a,&b);

			adj[a-1][b-1] = adj[b-1][a-1] = 1;
		}
		bitset<101> x;
		find(x,0);
		printf("%d\n",MIS);
		bool first = true;
		for(int i=0;i<n;i++)
			if(best[i]&&first)
				{printf("%d",i+1);first = false;}
			else if(best[i])
				printf(" %d",i+1);
		printf("\n");
	}
	return 0;
}