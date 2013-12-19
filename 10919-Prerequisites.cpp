//AC
#include<cstdio>
#include<cstring>
using namespace std;

int main()
{
	int k,m;
	while(scanf("%d",&k),k)
	{
		scanf("%d",&m);
		bool course[10000];
		memset(course,0,sizeof(course));
		for(int i=0;i<k;i++)
			{
				int x;
				scanf("%d",&x);
				course[x] = 1;
			}
		bool pass = true;
		for(int i=0;i<m;i++)
		{
			int c , r;
			scanf("%d %d",&c,&r);
			int n = 0;
			for(int j=0;j<c;j++)
			{
				int x;
				scanf("%d",&x);
				if(course[x])
					n++;
			}
			if(n<r)
				pass=false;
		}
		if(not pass)
			printf("no\n");
		else
			printf("yes\n");
	}
}