#include<cstdio>
#include<algorithm>
using namespace std;


int main()
{
	int n,d,r;
	while(scanf("%d %d %d",&n,&d,&r),n)
	{
		int morn[200],aft[200];
		for(int i=0;i<n;i++)
			scanf("%d",&morn[i]);
		for(int i=0;i<n;i++)
			scanf("%d",&aft[i]);
		sort(morn,morn+n);
		sort(aft,aft+n);
		int tot = 0;
		for(int i=0,j=n-1;i<n;i++,j--)
		{
			tot+=(morn[i]+aft[j]-d>0?morn[i]+aft[j]-d:0)*r;
		}
		printf("%d\n",tot);
	}
	return 0;
}