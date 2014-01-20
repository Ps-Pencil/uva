#include<cstdio>

using namespace std;

int main()
{
	long long n;
	while(scanf("%lld",&n),n)
	{
		long long a[2];
		a[0] = a[1] = 0;
		int i = 0;
		while(n!=0)
		{
			a[i] += (n&(-n));
			i = 1-i;
			n&=n-1;
		}
		printf("%lld %lld\n",a[0],a[1]);
	}
	return 0;
}