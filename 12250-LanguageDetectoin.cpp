//AC
#include<cstdio>
#include<cstring>

using namespace std;
char* words[6] = {"HELLO","HOLA","HALLO","BONJOUR","CIAO","ZDRAVSTVUJTE"};
char* lang[6] = {"ENGLISH","SPANISH","GERMAN","FRENCH","ITALIAN","RUSSIAN"};
int main()
{
	char str[100];
	int x = 1;
	while(scanf("%s",str))
	{
		if(str[0]=='#')
			break;
		bool match = false;
		for(int i=0;i<6;i++)
		{
			if(strcmp(str,words[i]) == 0)
			{
				printf("Case %d: %s\n",x++,lang[i]);
				match = true;
				break;
			}
		}
		if(not match){
			printf("Case %d: UNKNOWN\n",x++);
		}
	}
	return 0;
}