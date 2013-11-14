//AC
#include<cstdio>
#include<cstring>

using namespace std;

int main()
{
	int T;
	while(scanf("%d",&T))
	{
		if(T == 0)
			break;
		int x,y;
		scanf("%d %d",&x,&y);
		while(T--)
		{
			int m,n;
			scanf("%d %d",&m,&n);
			m -= x;
			n -= y;
			char str[2];
			if(m == 0 or n == 0)
			{
				printf("divisa\n");
				continue;
			}
			if(n > 0)
				str[0] = 'N';
			else
				str[0] = 'S';
			if(m > 0)
				str[1] = 'E';
			else
				str[1] = 'O';
			printf("%c%c\n",str[0],str[1]);
		}
	}
	return 0;
}