//AC
#include<cstdio>

using namespace std;

int main()
{

	int n;
	scanf("%d",&n);
	char names[200][101];
	for(int i=0;i<n;i++)
		scanf("%s",names[i]);
	int line = (n/16 + 1) * 16;
	for(int i=0,j=0;i<line;i++)
	{
		printf("%s: ", names[j]);
		j++;
		if(j == n)
			j = 0;
		if(i%4 == 0)
			printf("Happy\n");
		else if(i%4 == 1)
			printf("birthday\n");
		else if(i%4 == 2)
			printf("to\n");
		else if(i%16 == 11)
			printf("Rujia\n");
		else
			printf("you\n");

	}
	return 0;
}