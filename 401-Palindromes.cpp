#include<cstdio>
#include<cstring>
using namespace std;

int main()
{
	char str[100];
	while(scanf("%s",str)!=EOF)
	{
		int len = strlen(str);
		bool m = true,p = true;
		char mirror[200];
		memset(mirror,0,sizeof(mirror));
		mirror['A'] = 'A';
		mirror['E'] = '3';
		mirror['H'] = 'H';
		mirror['I'] = 'I';
		mirror['J'] = 'L';
		mirror['L'] = 'J';
		mirror['M'] = 'M';
		mirror['O'] = 'O';
		mirror['S'] = '2';
		mirror['T'] = 'T';
		mirror['U'] = 'U';
		mirror['V'] = 'V';
		mirror['W'] = 'W';
		mirror['X'] = 'X';
		mirror['Y'] = 'Y';
		mirror['Z'] = '5';
		mirror['1'] = '1';
		mirror['2'] = 'S';
		mirror['3'] = 'E';
		mirror['5'] = 'Z';
		mirror['8'] = '8';
		for(int i=0;i<=len-i-1;i++)
		{
			if(!m and !p)
				break;
			if(p and str[i] != str[len-i-1])
				p = false;
			if(m and str[i] != mirror[str[len-i-1]])
				m = false;
		}
		if(m and p)
			printf("%s -- is a mirrored palindrome.\n\n",str);
		else if(m)
			printf("%s -- is a mirrored string.\n\n",str);
		else if(p)
			printf("%s -- is a regular palindrome.\n\n",str);
		else
			printf("%s -- is not a palindrome.\n\n",str);
	}
	return 0;
}