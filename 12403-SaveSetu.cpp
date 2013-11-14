//AC
#include<cstdio>

using namespace std;

int main()
{
	int T;
	scanf("%d",&T);
	int tot = 0;
	while(T--)
	{
		char word[10];
		int amount;
		scanf("%s",word);
		if(word[0] == 'd')
		{
			scanf("%d",&amount);
			tot += amount;
		}
		else
			printf("%d\n",tot);
	}
	return 0;
}