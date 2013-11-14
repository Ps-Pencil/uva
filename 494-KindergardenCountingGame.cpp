#include<cstdio>

using namespace std;

int main()
{
	char c;
	int count = 0;
	bool pre = false;
	while((c = getchar())!=EOF)
	{
		if((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
		{
			if(pre == false)
			{
				count++;
				pre = true;
			}
		}
		else
		{
			pre = false;
		}
		if(c == '\n')
		{
			printf("%d\n",count);
			count = 0;
		}
	}
	return 0;
}