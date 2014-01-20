#include<cstdio>
#include<cstring>
using namespace std;

int main()
{
	char c,str[1000],len = 0;
	while((c=getchar())!=EOF)
	{
		if(c == '\n')
		{
			str[len] = '\0';
			if(strcmp(str,"done") == 0)
				break;
			bool p = true;
			for(int i=0;i<len-i-1;i++)
			{
				if(str[i]!=str[len-i-1])
				{
					p = false;
					break;
				}
			}
			if(p)
				printf("You won't be eaten!\n");
			else
				printf("Uh oh..\n");
			len = 0;
		}
		if(c>='a' && c<='z')
			str[len++] = c;
		if(c>='A' && c<='Z')
			str[len++] = c-'A' + 'a';
	}
	return 0;
}