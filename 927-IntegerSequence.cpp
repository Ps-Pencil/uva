#include<cstdio>

using namespace std;
int main()
{
	long long C;
	scanf("%lld",&C);
	while(C--)
	{
		long long deg, co[30];
		scanf("%lld",&deg);
		for(long long i=0;i<deg+1;i++)
			scanf("%lld",&(co[i]));
		long long d,k;
		scanf("%lld\n%lld",&d,&k);
		long long x=1;
		for(long long i=1;i<k;i++)
			if(i*(i+1)/2*d>=k)
			{
				x = i;
				break;
			}
		long long sum = 0;
		for(long long i=deg;i>=0;i--)
		{
			sum += co[i];
			if(i!=0)
			sum*=x;
		}
		printf("%lld\n",sum);
	}
	return 0;
}