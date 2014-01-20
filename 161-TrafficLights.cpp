#include<cstdio>
#include<vector>
#include<cstring>
#include<algorithm>
using namespace std;

int main()
{
	vector<int> cycle;
	int m,maxm = 1000, m1=1,m2=1;
	while(scanf("%d",&m)!=EOF)
	{
		if(m==0 && m1==0 && m2==0)
			break;
		if(m==0 && cycle.size()!=0)
		{
			bool t[20000];
			memset(t,1,sizeof(t));
			bool correct = false;
				for(int x = 0;x<=5*60*60;x++)
				{
					correct = true;
					for(int i=0;i<cycle.size();i++)
					{
					if(x%(2*cycle[i])>=cycle[i]-5)
					{
						correct = false;
						break;
					}
					}
					if(correct&&x>=maxm)
					{
						int h = x/3600;
						int m = (x%3600)/60;
						int s = x%60;
						printf("%02d:%02d:%02d\n",h,m,s);
						break;
					}
				}
			if(!correct)
				printf("Signals fail to synchronise in 5 hours\n");
			cycle.clear();
			maxm = 1000;
			continue;
		}
		else if(m==0) {
			m1 = m;
			m2 = m1;
			continue;
		}
		m1 = m;
		m2 = m1;
		cycle.push_back(m);
		if(m!=0&&m<maxm)
			maxm = m;
		
	}
	return 0;
}