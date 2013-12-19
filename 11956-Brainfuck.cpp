//AC
#include<cstdio>
#include<cstring>

using namespace std;

int main()
{
	int T;
	scanf("%d\n",&T);
	char c;
	for(int x=0;x<T;x++)
	{
		int a[100],cur = 0;
		memset(a,0x0,sizeof(a));
		while((c=getchar())!='\n')
		{
			if(c=='>')
				cur++;
			else if(c=='<')
				cur--;
			else if(c=='+')
				a[cur]++;
			else if(c == '-')
				a[cur]--;
			cur+=100;
			cur%=100;
			a[cur]+=256;
			a[cur]%=256;
		}
		printf("Case %d:",x+1);
		for(int i=0;i<100;i++)
		{
			printf(" %02X",a[i]);
		}
		printf("\n");
	}
	return 0;
}