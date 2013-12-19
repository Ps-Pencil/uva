//AC
#include<cstdio>
#include<cstring>
using namespace std;

int main()
{
	for(int ix=1;;ix++)
	{
		char c,prev;
		int map[1000001];
		map[0] = 0;
		if(scanf("%c",&prev)==EOF)
			break;
		for(int i=1;;i++)
		{
			scanf("%c",&c);
			if(c=='\n')
				break;
			if(c==prev)
				map[i] = map[i-1];
			else
			{
				map[i] = map[i-1] + 1;
			}
			prev = c;

		}
		int n;
		scanf("%d\n",&n);
		printf("Case %d:\n",ix);
		for(int i=0;i<n;i++)
		{
			int a,b;
			scanf("%d %d\n",&a,&b);
			if(map[a]==map[b])
				printf("Yes\n");
			else
				printf("No\n");
		}
	}
	return 0;
}