#include<cstdio>
#include<cstring>

using namespace std;

int ft[200001],f[200001];
int N;

int rsq(int b){
	int sum = 0;for(;b;b-=(b&-b)) sum+=ft[b];
	return sum;
}
int rsq(int a,int b)
{
	return rsq(b) - (a==1?0:rsq(a-1));
}
int adjust(int k,int v)
{
	for(;k<=N;k+=(k&-k)) ft[k]+=v;
	return 0;
}
int main()
{
	int TC = 1;
	while(scanf("%d",&N),N)
	{
		if(TC!=1)
			printf("\n");
		printf("Case %d:\n",TC++);
		memset(f,0,sizeof(f));
		memset(ft,0,sizeof(ft));
		for(int i=1;i<=N;i++)
		{
			int x;
			scanf("%d",&x);
			f[i] = x;
			adjust(i,x);
		}
		char str[10];
		while(scanf("%s",str))
		{
			if(str[0]=='E')
				break;
			int a,b;
			scanf("%d %d",&a,&b);
			if(str[0] == 'M')
			{
				printf("%d\n",rsq(a,b));
				continue;
			}
			if(str[0] == 'S')
			{
				adjust(a,b-f[a]);
				f[a] = b;
			}
		}
	}
	return 0;
}