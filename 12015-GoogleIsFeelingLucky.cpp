//AC
#include<cstdio>

using namespace std;

int main()
{
	int T;
	scanf("%d",&T);
	for(int i=0;i<T;i++)
	{
		char web[20][200];
		int rank[20];
		int highest = 0;
		for(int j=0;j<10;j++)
		{
			scanf("%s %d",web[j],&rank[j]);
			if(rank[j] > highest)
				highest = rank[j];
		}
		printf("Case #%d:\n",i+1);
		for(int j=0;j<10;j++)
		{
			if(rank[j] == highest)
				printf("%s\n",web[j]);
		}
	}
	return 0;
}