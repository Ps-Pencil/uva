#include<cstdio>
#include<algorithm>
using namespace std;

int main()
{
	int m,n;
	while(scanf("%d %d",&m,&n),m)
	{
		int answer = 0;
		if(m == 1 or n == 1)
			answer = m*n;
		else if(m*n == 4 or m*n == 6)
			answer = 4;
		else if(m==2 or n == 2)
			answer = max(m,n)/4 * 4 +(max(m,n)%4>=2?4:0)+(max(m,n)%4==1?2:0);
		else
			answer = (m*n+1)/2;
		printf("%d knights may be placed on a %d row %d column board.\n",answer,m,n);

	}
	return 0;
}