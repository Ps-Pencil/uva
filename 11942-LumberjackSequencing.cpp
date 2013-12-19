//AC
#include<cstdio>

using namespace std;

int main()
{
	int T;
	scanf("%d",&T);
	printf("Lumberjacks:\n");
	for(int i=0;i<T;i++)
	{
		int a[11];
		for(int j=0;j<10;j++)
			scanf("%d",&a[j]);
		bool up = true, down = true;
		for(int j=1;j<10;j++)
		{
			if(a[j-1] <= a[j])
				down = false;
			if(a[j-1] >= a[j])
				up = false;
		}
		if(up||down)
			printf("Ordered\n");
		else
			printf("Unordered\n");
	}
	return 0;
}