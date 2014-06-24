#include<cstdio>
#include<cstring>
#include<vector>

using namespace std;
int n,height[100010];

bool can(int x)
{
	if(height[0]>x)
		return false;

	if(height[0]==x)
		x--;
	for(int i=1;i<n;i++)
	{
		if(height[i]-height[i-1]>x)
			return false;
		if(height[i]-height[i-1]==x)
			x--;
	}
	return true;
}
int main()
{
	int T,TC=1;
	scanf("%d",&T);
	while(T--)
	{
		printf("Case %d: ",TC++);
		int m = 0;
		scanf("%d",&n);
		for(int i=0;i<n;i++)
			{
				scanf("%d",&height[i]);
				if(height[i]>m) m = height[i];
			}
		int left = 1,right = m*2;
		int ans = 0;
		while(left<right)
		{
			//printf("%d %d\n",left,right );
			int mid = (left+right)/2;
			if(can(mid)){ans=mid;right=mid-1;}
			else left = mid+1;
		}
		if(can(ans-1)) ans--;
		printf("%d\n",ans);
	}
	return 0;
}