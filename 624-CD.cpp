#include<cstdio>

using namespace std;

int main()
{
	int N;
	while(scanf("%d",&N)!=EOF)
	{
		int m,track[40];
		scanf("%d",&m);
		for(int i=0;i<m;i++)
		{
			scanf("%d",&track[i]);
		}
		int best = 0, sum = 0;
		for(int i=1;i<(1<<m);i++)
		{
			int s = 0;
			for(int j=0;j<m;j++)
				if(i&(1<<j))
					s+=track[j];
			if(s>sum && s<=N)
			{
				sum = s;
				best = i;
			}
		}
		for(int i=0;i<m;i++)
		{
			if((1<<i)&best)
				printf("%d ",track[i]);
		}
		printf("sum:%d\n",sum);
	}
	return 0;
}