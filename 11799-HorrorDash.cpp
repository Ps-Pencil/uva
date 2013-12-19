//AC
#include<cstdio>

using namespace std;

int main()
{
	int T;
	scanf("%d",&T);
	for(int i=0;i<T;i++)
	{
		int x;
		int max = 0;
		scanf("%d",&x);
		for(int j=0;j<x;j++)
		{
			int y;
			scanf("%d",&y);
			if(y>max)
				max = y;
		}
		printf("Case %d: %d\n",i+1,max);
	}
	return 0;
}