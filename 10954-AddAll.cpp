#include<queue>
#include<cstdio>

using namespace std;

int main()
{
	int n;
	while(scanf("%d",&n),n)
	{
		long long cost = 0;
		priority_queue<int,vector<int>, greater<int> > a;
		int x;
		for(int i=0;i<n;i++)
		{
			scanf("%d",&x);
			a.push(x);
		}
		while(a.size()>1)
		{
			x = a.top();
			a.pop();
			int y = a.top();
			a.pop();
			cost += x+y;
			a.push(x+y);
		}
		printf("%lld\n",cost);

	}
	return 0;
}