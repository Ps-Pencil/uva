#include<cstdio>
#include<algorithm>
using namespace std;

int main()
{
	int n,first = 1;;
	while(scanf("%d",&n),n)
	{
		if(!first)
			printf("\n");
		first = 0;
		int s[10001];
		for(int i=0;i<n;i++)
			scanf("%d",&s[i]);
		sort(s,s+n);
		int sum = 1, ans = 0;
		for(int i=1;i<n;i++)
		{
			if(s[i]!=s[i-1])
			{
				if(sum>ans)
					ans = sum;
				sum = 0;
			}
			sum++;
		}
		if(sum>ans) ans = sum;
		printf("%d\n",ans);
		for(int i=0;i<ans;i++)
		{
			bool f = true;
			for(int j=i;j<n;j+=ans)
			{
				if(!f) printf(" ");
				f = false;
				printf("%d",s[j]);
			}
			printf("\n");
		}
	}
	return 0;
}