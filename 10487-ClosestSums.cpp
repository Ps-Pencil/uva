#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;

int main()
{
	int n,TC=1;
	while(scanf("%d",&n),n)
	{
		printf("Case %d:\n",TC++);
		int seq[1001];
		vector<int> s;
		for(int i=0;i<n;i++)
		{
			scanf("%d",&seq[i]);
		}
		int m;
		scanf("%d",&m);
		int q[30];
		for(int i=0;i<m;i++)
		{
			scanf("%d",&q[i]);
			//s.push_back(q[i]);
		}
		for(int i=0;i<n-1;i++)
			for(int j=i+1;j<n;j++)
			{
				s.push_back(seq[i]+seq[j]);
			}
		sort(s.begin(),s.end());
		for(int i=0;i<m;i++)
		{
			int low = lower_bound(s.begin(),s.end(),q[i])-s.begin();
			int ans;
			if(q[i]==s[low])
				ans = s[low];
			else if(low==0)
				ans = s[low];
			else if(low == s.size())
				ans = s[low-1];
			else
				ans = (s[low]-q[i]<q[i]-s[low-1])?s[low]:s[low-1];
			printf("Closest sum to %d is %d.\n",q[i],ans);
		}

	}
	return 0;
}