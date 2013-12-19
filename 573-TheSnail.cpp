//AC
#include<cstdio>
#include<algorithm>
using namespace std;

int main()
{
	int h,u,d,f;
	while(scanf("%d %d %d %d",&h,&u,&d,&f),h)
	{
		double fatigue = (double)u * double(f) / 100.0;
		double height[500][4];
		int day = 1;
		height[1][0] = 0;
		height[1][1] = u;
		height[1][2] = u;
		height[1][3] = height[1][2] - d;
		while(true)
		{
			if(height[day][2] > h)
			{
				printf("success on day %d\n",day);
				break;
			}
			if(height[day][3] < 0)
			{
				printf("failure on day %d\n",day);
				break;
			}
			day++;
			height[day][0] = height[day-1][3];
			height[day][1] = max(height[day-1][1] - fatigue,0.0);
			height[day][2] = height[day][0] + height[day][1];
			height[day][3] = height[day][2] -d;


		}
	}
	return 0;
}