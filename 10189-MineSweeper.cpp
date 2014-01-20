#include<cstdio>
#include<cstring>
using namespace std;

int main()
{
	int m,n;
	int f = 1;
	while(scanf("%d %d\n",&m,&n),m)
	{
		if(f!=1)
		putchar('\n');
		int field[102][102];
		memset(field,0,sizeof(field));
		for(int i=1;i<=m;i++)
		{
			for(int j=1;j<=n;j++)
			{
				char c = getchar();
				if(c == '*')
				{
					field[i][j] = -1000;
					field[i-1][j-1]++;
					field[i-1][j]++;
					field[i-1][j+1]++;
					field[i][j-1]++;
					field[i][j+1]++;
					field[i+1][j-1]++;
					field[i+1][j]++;
					field[i+1][j+1]++;
				}
			}
			getchar();
		}
		printf("Field #%d:\n",f++);
		for(int i=1;i<=m;i++)
		{
			for(int j=1;j<=n;j++)
			{
				if(field[i][j]<0)
					putchar('*');
				else
					putchar('0'+field[i][j]);
			}
			putchar('\n');
		}
		
	}
	return 0;

}