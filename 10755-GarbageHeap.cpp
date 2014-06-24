#include<cstdio>
#include<cstring>
using namespace std;

long long sumrect[30][30][30];
long long sum2[30][30];
long long sum3[30];

int main()
{
	int T,first = true;
	scanf("%d",&T);
	while(T--)
	{
		if(not first)
			printf("\n");
		first = false;
		int a,b,c;
		long long m = -2147483648LL;
		scanf("%d %d %d",&a,&b,&c);
		memset(sumrect,0,sizeof(sumrect));
		for(int i=1;i<=a;i++)
			for(int j=1;j<=b;j++)
				for(int k=1;k<=c;k++)
					scanf("%lld",&sumrect[i][j][k]);
		for(int i1=1;i1<=a;i1++)
		{
			memset(sum2,0,sizeof(sum2));
			for(int i2=i1;i2<=a;i2++)
			{
				for(int j=1;j<=b;j++)
					for(int k=1;k<=c;k++)
						sum2[j][k]+=sumrect[i2][j][k];
				for(int j1=1;j1<=b;j1++)
				{
					memset(sum3,0,sizeof(sum3));
					for(int j2=j1;j2<=b;j2++)
					{
						for(int k=1;k<=c;k++)
							{sum3[k]+=sum2[j2][k];}
						long long s = 0;
						for(int k=1;k<=c;k++)
						{
							s+=sum3[k];
							if(s>m) m = s;
							if(s<0) s = 0;
						}
					}
				}
			}
		}
		printf("%lld\n",m);
	}
	return 0;
}