#include<cstdio>
#include<cstring>
using namespace std;

void rotate(char a[1000][1000],int n)
{
	char b[1000][1000];
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			b[j][n-1-i] = a[i][j];
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			a[i][j] = b[i][j];
	return ;
}
int main()
{
	int n,N;
	while(scanf("%d %d\n",&N,&n),N)
	{
		char big[1000][1000], small[1000][1000];
		for(int i=0;i<N;i++)
		{
			for(int j=0;j<N;j++)
				big[i][j] = getchar();
			getchar();
		}
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
				small[i][j] = getchar();
			getchar();
		}
		int occ[4];
		memset(occ,0,sizeof(occ));
		for(int rotation = 0; rotation < 4; rotation ++)
		{
			for(int i=0;i<=N-n;i++)
			for(int j=0;j<=N-n;j++)
			{
				bool match = true;
				for(int k=0;k<n;k++)
				{
					for(int l=0;l<n;l++)
						if(small[k][l]!=big[i+k][j+l])
						{
							match = false;
							break;
						}
					if(!match)
						break;
				}
				if(match) occ[rotation]++;
			}
			rotate(small,n);
		}
		for(int i=0;i<4;i++)
		{
			if(i!=0) putchar(' ');
			printf("%d",occ[i]);
		}
		putchar('\n');
	}
	return 0;
}