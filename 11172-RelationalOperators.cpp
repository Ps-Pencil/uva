//AC
#include<cstdio>

using namespace std;

int main()
{
	int T;
	scanf("%d",&T);
	while(T--){
		int m,n;
		scanf("%d %d",&m,&n);
		if(m > n)
			printf(">\n");
		else if(m < n)
			printf("<\n");
		else
			printf("=\n");
	}
	return 0;
}