#include<cstdio>

int main()
{
	int h,m;
	while(scanf("%d:%d",&h,&m))
	{
		if(m==0&&h==0)
			break;
		double angleM = 6.0*m;
		double angleH = 30.0*h + 0.5 * m;
		double angle = angleH - angleM;
		if(angle<0)
			angle = -angle;
		if(angle>180.0)
			angle = 360.0-angle;
		printf("%.3f\n",angle);
	}
	return 0;
}