//AC
#include<cstdio>

using namespace std;

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int n;
		scanf("%d",&n);
		int max = 0, min = 100;
		while(n--)
		{
			int x;
			scanf("%d",&x);
			if(x > max)
				max = x;
			if(x < min)
				min = x;
		}
		printf("%d\n",2*(max - min));
	}
	return 0;
}