#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

int memo[15000][101],happy[101],cost[101],m,n;

int find(int num,int w)
{
	if(w>m and m<1800) return -1000;
	if(w>m+200) return -1000;
	if(num == n) {if(w > m and w <= 2000) return -1000;return 0;}
	if(memo[w][num]!=-1) return memo[w][num];
	//if(cost[num]>left) return memo[left][num] = find(num+1,left);
	return memo[w][num] = max(find(num+1,w),happy[num]+find(num+1,w+cost[num]));
}
int main()
{
	while(scanf("%d %d",&m,&n)!=EOF)
	{
		memset(memo,-1,sizeof(memo));
		for(int i=0;i<n;i++)
			scanf("%d %d",&cost[i],&happy[i]);
		printf("%d\n",find(0,0));
	}
}