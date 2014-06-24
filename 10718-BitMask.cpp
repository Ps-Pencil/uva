#include<cstdio>

using namespace std;

int main()
{
	long long n,l,u;
	while(scanf("%lld %lld %lld",&n,&l,&u)!=EOF)
	{
		if(l==u) {printf("%lld\n",l);continue;}
		long long result = 0;
		for(int i=31;i>=0;i--)
			if((result|(1LL<<i))<=(n&(1LL<<i)?l:u))
				result|=(1LL<<i);
		printf("%lld\n",result);

	}
	return 0;
}