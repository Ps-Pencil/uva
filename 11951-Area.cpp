#include<cstdio>
#include<cstring>
using namespace std;
long long s[110][110];
long long s1[110];
int main()
{
	int T;
	scanf("%d",&T);
	for(int TC=1;TC<=T;TC++)
	{
		memset(s,0,sizeof(s));
		printf("Case #%d: ",TC);
		long long m,n,k;
		scanf("%lld %lld %lld",&m,&n,&k);
		int longest = 0;
		long long min_sum = 1000000000;
		for(int i=1;i<=m;i++)
		{
			for(int j=1;j<=n;j++)
				{
					long long x;
					scanf("%lld",&x);
					s[i][j] = s[i-1][j]+s[i][j-1]-s[i-1][j-1]+x;
				}
		}
		for(int i1=1;i1<=m;i1++)
		{
			memset(s1,0,sizeof(s1));
			for(int i2=i1;i2<=m;i2++)
			{
				long long startj = 1;
				for(int j=1;j<=n;j++)
				{
					long long sum = s[i2][j]-s[i1-1][j]-s[i2][startj-1]+s[i1-1][startj-1];
					while(sum>k)
					{
						sum-=(s[i2][startj]-s[i1-1][startj])-(s[i2][startj-1]-s[i1-1][startj-1]);
						startj++;
					}
					long long len = (j-startj+1)*(i2-i1+1);
					if(len>longest)
					{
						longest = len;
						min_sum = sum;
					}
					else if(len==longest && sum < min_sum)
						min_sum = sum;

				}
			}
		}
		printf("%d %lld\n",longest,min_sum);
	}
}