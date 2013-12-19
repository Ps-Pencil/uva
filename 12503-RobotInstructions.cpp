//AC
#include<cstdio>

using namespace std;

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int n,pos = 0,inst[200];
		scanf("%d",&n);
		for(int i=0;i<n;i++)
		{
			char c[10];
			scanf("%s",c);
			if(c[0] == 'L')
			{
				inst[i] = -1;
				pos--;
			}
			else if(c[0] == 'R')
			{
				inst[i] = 1;
				pos++;
			}
			else
			{
				int num;
				scanf("%*s %d",&num);
				inst[i] = inst[num-1];
				pos += inst[i];
			}
		}
		printf("%d\n",pos);
	}
	return 0;
}