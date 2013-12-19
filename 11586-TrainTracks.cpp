//AC
#include<cstdio>

using namespace std;

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int n = 0,m = 0,f = 0;
		while(true){
		
		char piece[3];
		scanf("%s",piece);
		n++;
		char end;
		scanf("%c",&end);
		m+=(piece[0]=='M')+(piece[1]=='M');
		f+=(piece[0]=='F')+(piece[1]=='F');
		if(end=='\n')
			break;
		}
		if(n==1 or m!=f)
			printf("NO LOOP\n");
		else
			printf("LOOP\n");


	}
	return 0;
}