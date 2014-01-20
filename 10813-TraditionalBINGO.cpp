#include<cstdio>
#include<cstring>
using namespace std;

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int card[76][3];
		memset(card,0,sizeof(card));
		int line[13];
		memset(line,0,sizeof(line));
		line[3] = line[8] = line[11] = line[12] = 1;
		for(int i=1;i<=5;i++)
			for(int j=1;j<=5;j++)
			{
				if(i==3&&j==3)continue;
				int x;
				scanf("%d",&x);
				card[x][0] = i;
				card[x][1] = 5+j;
				if(i == j)
					card[x][2] = 11;
				else if(i+j ==6)
					card[x][2] = 12;
			}
		bool bingo = false;
		for(int i=0;i<75;i++)
		{
			int x;
			scanf("%d",&x);
			if(bingo)
				continue;

			for(int j=0;j<3;j++)
			if(card[x][j]!=0)
			{
				line[card[x][j]]++;
				if(line[card[x][j]]==5)
				{

					printf("BINGO after %d numbers announced\n",i+1);
					bingo = true;
					break;
				}
			}

		}
	}
	return 0;
}