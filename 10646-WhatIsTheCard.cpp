//AC
#include<cstdio>
#include<cstring>
using namespace std;

int main()
{
	int T;
	scanf("%d",&T);
	for(int x = 0;x < T; x++)
	{
		printf("Case %d: ",x+1);
		char cards[60][5];
		for(int i=0;i<52;i++)
			scanf("%s",cards[51-i]);
		int Y = 0, top = 25;
		for(int i=0;i<3;i++)
		{
			if(top > 51)
				{
					top = 52;
					break;
				}
			int X;
			char c = cards[top][0];
			if('2'<=c and c<='9')
				X = c - '0';
			else
				X = 10;
			Y += X;
			top += 10-X+1;
		}
		//printf("%d ",Y);
		if(51-top+1 >= Y)
			printf("%s\n", cards[51-Y+1]);
		else
			printf("%s\n", cards[25-(Y-(51-top+1))]);
	}
	return 0;
}