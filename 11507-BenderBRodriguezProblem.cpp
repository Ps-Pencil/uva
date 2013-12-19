//AC
#include<cstdio>

using namespace std;

int main()
{
	int n;
	while(scanf("%d\n",&n),n)
	{
		int dir = 'x', dn = 0;
		for(int i=0;i<n-1;i++)
		{
			char bend[10];
			scanf("%s",bend);
			if(bend[0] == 'N')
				continue;
			else if(bend[1] == 'y')
			{
				if(dir == 'z')
					continue;
				if(bend[0] == '+')
					dn++;
				else
					dn--;
				dn+=4;
				dn%=4;
				if(dn==2 or dn == 0)
					dir = 'x';
				else
					dir = 'y';

			}
			else if(bend[1] == 'z')
			{
				if(dir == 'y')
					continue;
				if(bend[0] == '+')
					dn++;
				else
					dn--;
				dn+=4;
				dn%=4;
				if(dn==2 or dn == 0)
					dir = 'x';
				else
					dir = 'z';

			}

		}
		if(dn==0 or dn == 1)
			printf("+");
		else
			printf("-");
		printf("%c\n",dir);

	}
	return 0;
}