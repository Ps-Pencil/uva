//AC
#include<cstdio>
#include<cstring>

using namespace std;

int main()
{
	int n;
	while(scanf("%d\n",&n),n)
	{
		char s[2000001];
		scanf("%s",s);
		int min=n;
		int pos=-9999999, ch = 'R';
		for(int i=0;i<n;i++)
		{
			if(s[i]=='Z')
			{
				min=0;
				break;
			}
			if(s[i]=='.') continue;
			if(s[i]==ch)
			{
				pos = i;
			}
			else
			{
				if(i-pos<min)
					min = i-pos;
				pos = i;
				ch = s[i];
			}
		}
		printf("%d\n",min);


	}
	return 0;
}