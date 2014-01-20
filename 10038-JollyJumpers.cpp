#include<cstdio>
#include<cstring>
using namespace std;

int main()
{
	int n;
	while(scanf("%d",&n)!=EOF)
	{
		bool diff[4000],fail = false;
		memset(diff,0,sizeof(diff));
		int total = 0,prev;
		scanf("%d",&prev);
		for(int i=1;i<n;i++)
		{
			int x;
			scanf("%d",&x);
			if(fail) continue;
			int d = x - prev;
			if(d<0) d = -d;
			if(diff[d]==1 or d >= n)
				fail = true;
			else
				diff[d] = 1;
			prev = x;
		}
		if(fail)
			printf("Not jolly\n");
		else
			printf("Jolly\n");
	}
	return 0;
}