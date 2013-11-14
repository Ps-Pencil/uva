//AC
#include<cstdio>
#include<cstring>

using namespace std;

int main()
{
	
	for(int i=1;;i++)	
	{
		char words[10];
		scanf("%s",words);
		if(words[0] == '*')
			break;
		if(strcmp(words,"Hajj") == 0)
			printf("Case %d: Hajj-e-Akbar\n",i);
		else
			printf("Case %d: Hajj-e-Asghar\n",i);
	}
	return 0;
}