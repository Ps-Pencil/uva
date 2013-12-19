//AC
#include<cstdio>
#include<algorithm>
using namespace std;

int main()
{
	int a,b;
	while(scanf("%d %d",&a,&b))
	{
		if(a > b)
		{
			int t = a;
			a = b;
			b = t;
		}
		if(a==-1)
			break;
		printf("%d\n",min(100+a-b,b-a));
	}
	return 0;
}