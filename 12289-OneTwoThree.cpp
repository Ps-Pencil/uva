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
		char word[10];
		scanf("%s",word);
		int l = strlen(word);
		if(l == 5)
			printf("3\n");
		else
		{
			int mis = 0;
			if(word[0] != 'o')
				mis ++;
			if(word[1] != 'n')
				mis ++;
			if(word[2] != 'e')
				mis ++;
			if(mis <= 1)
				printf("1\n");
			else
				printf("2\n");
		}
	}
	return 0;
}