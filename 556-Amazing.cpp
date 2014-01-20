#include<cstdio>
#include<cstring>
using namespace std;
int m,n;
int maze[1000][1000];
bool check(int row, int col)
{
	if(row<m and row >= 0 and col < n and col >= 0 and maze[row][col] == 0)
		return true;
	else
		return false;
}
int main()
{
	
	while(scanf("%d %d\n",&m,&n),m)
	{
		
		for(int i=0;i<m;i++)
		{
			for(int j=0;j<n;j++)
			{
				maze[i][j] = getchar()-'0';
			}
			getchar();
		}
		int visit[100][100];
		memset(visit,0,sizeof(visit));
		int x = m-1,y = 0, dir = 0;
		do{
			//printf("%d %d %d\n",x,y,dir);
			int rx,ry,sx,sy,lx,ly;
			switch(dir){
				case 0:
				rx = 1;ry = 0; sx = 0;sy = 1;lx = -1;ly=0;break;
				case 1:
				rx = 0;ry=1;sx=-1;sy=0;lx=0;ly=-1;break;
				case 2:
				rx = -1;ry=0;sx=0;sy=-1;lx=1;ly=0;break;
				case 3:
				rx = 0;ry=-1;sx=1;sy=0;lx=0;ly=1;break;
			}
			if(check(x+rx,y+ry)){
				dir = (dir+4-1)%4;
				visit[x][y]++;
				x = x+rx; y=y+ry; 
				continue;
			}
			else if(check(x+sx,y+sy)){
				//dir = (dir-1)%4;
				visit[x][y]++;
				x = x+sx; y=y+sy; 
				continue;
			}
			else if(check(x+lx,y+ly)){
				dir = (dir+1)%4;
				visit[x][y]++;
				x = x+lx; y=y+ly; 
				continue;
			}
			else
			{
				dir = (dir+2)%4;
				visit[x][y]++;
				x = x-sx; y = y-sy;
				continue;
			}
		}while(not(x==m-1 && y==0));
		visit[m-1][0] = 1;
		int number[5];
		memset(number,0,sizeof(number));
		for(int i=0;i<m;i++)
		{
			for(int j=0;j<n;j++)
				if(maze[i][j]==0)
					number[visit[i][j]]++;
		}
		for(int i=0;i<5;i++)
		printf("%3d",number[i]);
		printf("\n");
	}
	return 0;
}