//AC
#include<cstdio>

using namespace std;

int main()
{
	for(int i=1;;i++)
	{
		
		int n,m,c,a[300];
		scanf("%d %d %d",&n,&m,&c);
		if(n==0)
			break;
			printf("Sequence %d\n",i);
		for(int j=0;j<n;j++)
			scanf("%d",&a[j]);
		int max = 0;
		int bm = 0;
		int cur = 0;
		for(int j=0;j<m;j++)
		{
			int x;
			scanf("%d",&x);
			if(bm&(1<<x))
			{
				bm -= 1<<x;
				cur -= a[x-1];
			}
			else
			{
				cur += a[x-1];
				bm += 1<<x;
				if(cur>max)
					max = cur;
			}
		}
		if(max > c)
			printf("Fuse was blown.\n");
		else
			printf("Fuse was not blown.\nMaximal power consumption was %d amperes.\n",max);
		printf("\n");

	}
	return 0;
}