//AC
#include<cstdio>

using namespace std;

int main()
{
	int T;
	scanf("%d",&T);
	for(int i=0;i<T;i++)
	{
		int a,b,c;
		scanf("%d %d %d",&a,&b,&c);
		if(a > 20 || b > 20 || c > 20)
		{
			printf("Case %d: bad\n",i+1);
		}
		else
			printf("Case %d: good\n",i+1);
	}
	return 0;
}