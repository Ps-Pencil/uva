//AC
#include<cstdio>
#include<cstring>

using namespace std;

int main()
{
	char c[1000002];
	while(scanf("%s",c))
	{
		if(strcmp(c,"END")==0)break;
		if(strlen(c)==1 and c[0] == '1')
			printf("1\n");
		else if(strlen(c)==1)
			printf("2\n");
		else if(strlen(c)<=9)
			printf("3\n");
		else
			printf("4\n");
	}
	return 0;
}