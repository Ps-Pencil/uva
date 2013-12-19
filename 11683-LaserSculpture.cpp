//AC
#include<cstdio>

using namespace std;

int main()
{
	int l,w;
	while(scanf("%d",&l),l)
	{
		scanf("%d",&w);
		int up=0,down=0,prev = l;
		for(int i=0;i<w;i++)
		{
			int h;
			scanf("%d",&h);
			if(h>prev)
				up+=h-prev;
			else
				down += prev - h;
			prev = h;
		}
		up+=l-prev;
		printf("%d\n",up>down?up:down);
	}
	return 0;
}