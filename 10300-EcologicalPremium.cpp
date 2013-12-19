//AC
#include<cstdio>

using namespace std;

int main()
{
	int T;
	scanf("%d",&T);
	while(T--){
		int sum=0,farmer;
		scanf("%d",&farmer);
		while(farmer--){
			int a,b,c;
			scanf("%d %d %d",&a,&b,&c);
			sum += a*c;
		}
		printf("%d\n",sum);
	}
	return 0;
}