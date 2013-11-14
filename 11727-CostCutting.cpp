//AC
#include<cstdio>
#include<algorithm>
using namespace std;

int main()
{
	int T;
	scanf("%d",&T);
	for(int i=0;i<T;i++)
	{
		int a[3];
		scanf("%d %d %d",a,a+1,a+2);
		sort(a,a+3);
		printf("Case %d: %d\n",i+1,a[1]);
	}
	return 0;
}