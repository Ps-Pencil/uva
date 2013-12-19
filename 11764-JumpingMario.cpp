//AC
#include<cstdio>

using namespace std;

int main()
{
	int T;
	scanf("%d",&T);
	for(int i=0;i<T;i++)
	{
		int w;
		scanf("%d",&w);
		int h=0,l=0;
		int prev;
		for(int j=0;j<w;j++)
		{
			int x;
			scanf("%d",&x);
			if(j!=0)
			{
				if(x > prev)
					h++;
				if(x < prev)
					l++;
			}
			prev = x;
		}
		printf("Case %d: %d %d\n",i+1,h,l);
	}
	return 0;
}