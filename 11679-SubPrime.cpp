//AC
#include<cstdio>

using namespace std;

int main()
{
	int b,n;
	while(scanf("%d %d",&b,&n),b){
		int m[30];
		for(int i=1;i<=b;i++)
		{
			scanf("%d",&m[i]);
		}
		for(int i=0;i<n;i++)
		{
			int a,b,c;
			scanf("%d %d %d",&a,&b,&c);
			m[a] -= c;
			m[b] += c;
		}
		bool fail = false;
		for(int i=1;i<=b;i++)
		{
			if(m[i] < 0)
				fail = true;
		}
		if(fail)
			printf("N\n");
		else
			printf("S\n");
	}
	return 0;
}