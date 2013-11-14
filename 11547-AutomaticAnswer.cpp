//AC
#include<cstdio>

using namespace std;

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int n;
		scanf("%d",&n);
		n = (n * 567 / 9 + 7492) * 235 / 47 - 498;
		if(n < 0)
			n = -n;
		printf("%d\n",(n/10)%10);
	}
	return 0;
}