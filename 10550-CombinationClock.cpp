//AC
#include<cstdio>

using namespace std;

int main()
{
	int a,b,c,d;
	while(scanf("%d %d %d %d",&a,&b,&c,&d))
	{
		if(a+b+c+d == 0)
			break;
		int deg = 1080;
		if(a > b)
			deg += (a - b) * 9;
		else
			deg += (a + 40 - b) * 9;
		if(c > b)
			deg += (c - b) * 9;
		else
			deg += (c + 40 - b) * 9;
		if(c > d)
			deg += (c - d) * 9;
		else
			deg += (c + 40 - d) * 9;
		printf("%d\n",deg);
	}
	return 0;
}