#include<cstdio>
#include<algorithm>
using namespace std;

int main()
{
	int a[5];
	while(scanf("%d",&a[0]),a[0])
	{
		bool taken[53] = {0};
		taken[a[0]] = 1;
		for(int i=1;i<5;i++)
			{
				scanf("%d",&a[i]);
				taken[a[i]] = 1;
			}
		int larger[2] = {0};
		sort(&a[0],&a[3]);
		for(int i=0;i<3;i++)
		{
			if(a[i]>a[3])
				larger[0]++;
			if(a[i]>a[4])
				larger[1]++;
		}
		int ini = 0;
		sort(larger,larger+2);
		if(larger[0]+larger[1]>2)
		{
			if(larger[0]!=0)
			{
				printf("-1\n");
				continue;
			}
			else
				ini = a[2]+1;
		}
		else
		{
			if(larger[1] == 0)
				ini = 1;
			else if(larger[1] == 1)
				ini = a[1]+1;
			else
				ini = a[2]+1;
		}
		for(;ini<=52;ini++)
			if(taken[ini] == 0)
				break;
		if(ini==53)
			printf("-1\n");
		else
			printf("%d\n",ini);

	}
	return 0;
}