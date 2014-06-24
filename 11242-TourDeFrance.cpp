#include<cstdio>
#include<algorithm>
using namespace std;

struct drive_ratio{
	int n,m;
}total[10001];

bool cmp(drive_ratio a, drive_ratio b)
{
	return a.n*b.m < b.n*a.m;
}
int main()
{
	int f,r;
	while(scanf("%d",&f),f)
	{
		scanf("%d",&r);
		int front[101],rear[101];
		for(int i = 0 ; i < f ; i ++)
			scanf("%d",&front[i]);
		for(int i=0;i<r;i++)
			scanf("%d",&rear[i]);
		int count = 0;
		for(int i=0;i<f;i++)
			for(int j=0;j<r;j++)
			{
				total[count].n = rear[j];
				total[count].m = front[i];
				count++;
			}
		sort(total,total+count,cmp);
		double max = 0;
		for(int i=0;i<count-1;i++)
		{
			double sp = ((double)total[i+1].n/(double)total[i+1].m)/((double)total[i].n/(double)total[i].m);
			if(sp>max)
				max = sp;
		}
		printf("%.2f\n",max);
	}
	return 0;
}