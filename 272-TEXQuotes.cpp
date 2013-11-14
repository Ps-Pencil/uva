#include<cstdio>

using namespace std;

int main()
{
	char c;
	int n = 0;
	while((c = getchar())!= EOF)
	{
		if(c == '"')
		{
			if(n % 2 == 0)
			{
				printf("``");
			}
			else
			{
				printf("\'\'");
			}
			n++;
		}
		else
			putchar(c);
	}
	return 0;
}