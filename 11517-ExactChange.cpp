#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
#define INF 1000

int n,price,coin[110];
int dp[30000];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		for(int i=0;i<20000;i++) dp[i]=INF;
		dp[0] = 0;
		scanf("%d",&price);
		scanf("%d",&n);
		for(int i=0;i<n;i++)
			scanf("%d",&coin[i]);
		for(int i=0;i<n;i++)
			for(int k=price;k>=0;k--)
			{

				if(dp[k]!=INF)
					dp[k+coin[i]] = min(dp[k+coin[i]],dp[k]+1);
			}
		int i = price;
		while(dp[i]==INF)
			i++;
		printf("%d %d\n",i,dp[i]);
	}
}