//AC
#include<cstdio>

using namespace std;

int main()
{
	int N;
	int index = 1;
	while(scanf("%d",&N),N){
		int sum = 0;
		for(int i=0;i<N;i++)
		{
			int x;
			scanf("%d",&x);
			if(x == 0)
				sum -= 1;
			else
				sum += 1;
		}
		printf("Case %d: %d\n",index++,sum);
	}
	return 0;
}