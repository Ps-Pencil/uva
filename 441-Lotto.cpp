#include<cstdio>

using namespace std;

int main()
{
	int k,a=0;
	while(scanf("%d",&k),k)
	{
		if(a)
			printf("\n");
		int seq[20];
		for(int i=0;i<k;i++)
			scanf("%d",&seq[i]);
		for(int i1=0;i1<k-5;i1++)
			for(int i2=i1+1;i2<k-4;i2++)
				for(int i3=i2+1;i3<k-3;i3++)
					for(int i4=i3+1;i4<k-2;i4++)
						for(int i5=i4+1;i5<k-1;i5++)
							for(int i6=i5+1;i6<k;i6++)
								printf("%d %d %d %d %d %d\n",seq[i1],seq[i2],seq[i3],seq[i4],seq[i5],seq[i6]);
		if(!a) a=1;	
	}
	return 0;
}