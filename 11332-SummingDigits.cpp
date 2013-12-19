//AC
#include<cstdio>
#include<cstring>

using namespace std;

int main()
{
	char c[100];
	while(scanf("%s",c)){
		if(c[0] == '0')
			break;
		int sum = 0;
		for(int i=0;i<strlen(c);i++)
		{
			sum += c[i] - '0';
		}
		while(sum>=10)
		{
			int s = 0;
			while(sum != 0)
			{
				s += sum%10;
				sum /= 10;
			}
			sum = s;
		}
		printf("%d\n",sum);
	}
	return 0;
}