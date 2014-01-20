#include<cstdio>

using namespace std;

int main()
{
	int T;
	scanf("%d\n",&T);
	for(int x = 1;x<=T;x++)
	{
		printf("Case #%d:\n",x);
		char str[100000];
		int len = 0;
		char c;
		while((c=getchar())!='\n')
		{
			if(c>='A' and c<='Z')
				c = c -'A' + 'a';
			if(c>='a' and c<='z')
				str[len++] = c;
		}
		str[len] = '\0';
		int side = 0;
		for(int i=1;i*i<=len;i++)
			if(i*i == len)
				side = i;
		bool p = true;
		if(side!=0)
		for(int i=0;i<len/2;i++)
		{
			if(str[i]!= str[len-i-1] or str[i]!= str[i%side*side + i/side] or str[i] != str[len-(i%side*side+i/side)-1])
			{
				p = false;
				break;
			}
		}
		if(!p or !side)
			printf("No magic :(\n");
		else
			printf("%d\n",side);
	}
	return 0;
}