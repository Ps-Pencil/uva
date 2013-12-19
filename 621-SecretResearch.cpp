//AC
#include<cstdio>
#include<cstring>
using namespace std;

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		char c[2000];
		scanf("%s",c);
		if(strcmp(c,"1") == 0 or strcmp(c,"4") == 0 or strcmp(c,"78") == 0)
			printf("+\n");
		else if(c[strlen(c) - 1] == '5' or c[strlen(c) - 2] == '3')
			printf("-\n");
		else if(c[0] == '9' and c[strlen(c) - 1] == '4')
			printf("*\n");
		else 
			printf("?\n");
	}
	return 0;
}