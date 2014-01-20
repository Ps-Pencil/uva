#include<cstdio>
#include<cstring>
using namespace std;


int main()
{
	int T;
	scanf("%d\n",&T);
	for(int x=0;x<T;x++)
	{
		if(x!=0)
			putchar('\n');
		int m,n,d;
		scanf("%d %d %d\n",&m,&n,&d);
		char grid[102][102];
		memset(grid,0,sizeof(grid));
		for(int i=1;i<=m;i++)
			{
				for(int j=1;j<=n;j++)
					grid[i][j] = getchar();
				getchar();
			}
		int beat[200];
		beat['R'] = 'P';
		beat['P'] = 'S';
		beat['S'] = 'R';
		char new_grid[102][102];
		for(int k=0;k<d;k++)
		{
			for(int i=1;i<=m;i++)
				for(int j=1;j<=n;j++)
				{
					if(grid[i-1][j] == beat[grid[i][j]] or grid[i+1][j] == beat[grid[i][j]] or grid[i][j-1] == beat[grid[i][j]] or grid[i][j+1] == beat[grid[i][j]])
						new_grid[i][j] = beat[grid[i][j]];
					else
						new_grid[i][j] = grid[i][j];
				}
			for(int i=1;i<=m;i++)
				for(int j=1;j<=n;j++)
					grid[i][j] = new_grid[i][j];
		}
		for(int i=1;i<=m;i++)
		{
			for(int j=1;j<=n;j++)
				putchar(grid[i][j]);
			putchar('\n');
		}
	}
	return 0;
}