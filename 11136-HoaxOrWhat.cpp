#include<cstdio>
#include<set>

using namespace std;

int main()
{
	int d;
	while(scanf("%d",&d),d)
	{
		multiset<long long int> urn;
		long long int sum = 0;
		multiset<long long int>::iterator it;
		for(int i=0;i<d;i++)
		{
			long long int x;
			scanf("%lld",&x);
			for(int j=0;j<x;j++)
			{
				long long int y;
				scanf("%lld",&y);
				urn.insert(y);
			}
			long long int b;
			it = urn.begin();
			b = *it;
			urn.erase(it);
			it = urn.end();
			it--;
			sum += *it - b;
			urn.erase(it);
		}
		printf("%lld\n",sum);
	}
	return 0;
}