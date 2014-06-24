#include<cstdio>
#include<cstring>
using namespace std;

struct Node{
	int num_negative,num_zero;
}ft[200001];
int N,K,f[200001];

int adjust(int k, int neg,int zero)
{
	for(;k<=N;k+=(k&-k)) {ft[k].num_negative+=neg;ft[k].num_zero+=zero;
	}
	return 0;
}
int debug()
{
	for(int k=1;k<=N;k++)printf("%d %d %d %d\n",k-(k&-k)+1,k,ft[k].num_negative,ft[k].num_zero);
}
int rsq_zero(int b)
{
	int sum = 0;
	for(;b;b-=(b&-b)) sum+=ft[b].num_zero;
	return sum;
}
int rsq_neg(int b)
{
	int sum = 0;
	for(;b;b-=(b&-b)) sum+=ft[b].num_negative;
	return sum;
}
int rsq(int a,int b)
{
	int nn = rsq_neg(b) - (a==1?0:rsq_neg(a-1));
	int nz = rsq_zero(b) - (a==1?0:rsq_zero(a-1));
	//printf("%d %d %d %d\n",a,b,nn,nz);
	if(nz > 0)
		return 0;
	else if(nn % 2==0)
		return 1;
	else 
		return -1;
}
int main()
{
	while(scanf("%d %d",&N,&K)!=EOF)
	{
		memset(ft,0,sizeof(ft));
		for(int i=1;i<=N;i++)
		{
			int x;
			scanf("%d",&x);
			if(x > 0) f[i] = 1;
			else if(x == 0) {f[i] = 0;adjust(i,0,1);}
			else {f[i] = -1;adjust(i,1,0);}
		}
		int i;
		for(i=0;i<K;i++)
		{
			char str[10];
			int a,b;
			scanf("%s %d %d",str,&a,&b);
			if(str[0]=='C')
			{
				
				int dn = 0, dz = 0,n = 0,z = 0;
				if(f[a] == 0)
					dz = 1;
				else if(f[a] < 0)
					dn = 1;

				if(b == 0) {z = 1;f[a] = 0;}
				else if(b<0) {n = 1;f[a] = -1;}
				else f[a] = 1;

				adjust(a,n-dn,z-dz);

			}
			else if(str[0] == 'P')
			{
				//printf("P %d %d\n",i,K);
				int x = rsq(a,b);
				if(x == 0)
					printf("0");
				else if(x > 0)
					printf("+");
				else
					printf("-");
			}
			//printf("%d %d\n",i,K);
			//printf("%d %s %d %d\n",K,str,a,b);
		}
		printf("\n");
	}
	return 0;
}