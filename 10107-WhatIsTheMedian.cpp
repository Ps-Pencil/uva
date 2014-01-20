#include<cstdio>
#include<algorithm>
#include<vector>

using namespace std;

int main()
{
	vector<long long> l;
	long long a;
	while(scanf("%lld",&a)!=EOF)
	{
		l.push_back(a);
		if(l.size()%2==1)
		{
			nth_element(l.begin(),l.begin()+l.size()/2,l.end());
			printf("%lld\n",l[l.size()/2]);
		}
		else
		{
			nth_element(l.begin(),l.begin()+l.size()/2-1,l.end());
			long long n1 = l[l.size()/2-1];
			nth_element(l.begin(),l.begin()+l.size()/2,l.end());
			long long n2 = l[l.size()/2];
			printf("%lld\n",(n1+n2)/2);
		}
	}
	return 0;
}