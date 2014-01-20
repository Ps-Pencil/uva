#include<cstdio>
#include<algorithm>
using namespace std;

int main()
{
	int T;
	scanf("%d\n",&T);
	while(T--)
	{
		char c;
		int col,row;
		scanf("%c %d %d\n",&c,&col,&row);
		switch(c)
		{
			case 'r':
			printf("%d\n",min(col,row));
			break;

			case 'k':
			printf("%d\n",(col*row+1)/2);
			break;

			case 'Q':
			printf("%d\n",min(col,row));
			break;

			case 'K':
			col = (col + 1) / 2;
			row = (row + 1) / 2;
			printf("%d\n",col*row);
			break;

			default:
			printf("Unknown %c\n",c);
			break;
		}
	}
	return 0;
}