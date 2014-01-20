#include<cstdio>
using namespace std;

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a,b,c;
		scanf("%d %d %d",&a,&b,&c);
		int board[101] = {0};
		for(int i=0;i<b;i++)
		{
			int x,y;
			scanf("%d %d",&x,&y);
			board[x] = y;
		}
		int position[1000000] = {0};
		for(int i=0;i<a;i++)
			position[i] = 1;
		int end = false;
		for(int i=0;i<c;i++)
		{
			
			int move;
			scanf("%d",&move);
			if(end)
				continue;
			position[i%a]+=move;
			
			if(board[position[i%a]]!=0)
				position[i%a] = board[position[i%a]];
			if(position[i%a] >= 100)
			{
				position[i%a] = 100;
				end = true;
			}
		}
		for(int i=0;i<a;i++)
		{
			printf("Position of player %d is %d.\n",i+1,position[i]);
		}
	}
	return 0;
}