//AC
#include<cstdio>

using namespace std;

int main()
{
	int T;
	scanf("%d",&T);
	for(int i=0;i<T;i++)
	{
		int n;
		scanf("%d",&n);
		int m=0,j=0;
		for(int k=0;k<n;k++){
			int x;
			scanf("%d",&x);
			m += (x/30 + 1)*10;
			j += (x/60 + 1)*15;
		}
		printf("Case %d: ",i+1);
		if(m < j)
			printf("Mile %d\n",m);
		if(j < m)
			printf("Juice %d\n",j);
		if(m == j)
			printf("Mile Juice %d\n",m);
	}
	return 0;
}