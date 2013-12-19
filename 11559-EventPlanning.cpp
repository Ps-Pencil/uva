//AC
#include<cstdio>

using namespace std;

int main()
{
	int n;
	while(scanf("%d",&n)!= EOF)
	{
		int b,h,w;
		scanf("%d %d %d",&b,&h,&w);
		int lowest = b + 1;
		for(int i=0;i<h;i++)
		{
			int cost = 9999999;
			int price;
			scanf("%d",&price);
			for(int j = 0 ; j < w ; j++)
			{
				int x;
				scanf("%d",&x);
				if(x>=n)
					cost = price * n;
			}
			if(cost < lowest)
				lowest = cost;
		}
		if(lowest > b){
			printf("stay home\n");
		}
		else{
			printf("%d\n",lowest);
		}
	}
	return 0;
}