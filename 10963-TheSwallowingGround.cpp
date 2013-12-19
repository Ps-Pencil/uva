//AC
#include<cstdio>

using namespace std;

int main()
{
	int T;
	scanf("%d",&T);
	for(int i=0;i<T;i++)
	{
		int row,a,b;
		scanf("%d",&row);
		scanf("%d %d",&a,&b);
		int diff = a-b;
		bool cor = true;
		row -= 1;

		if(i!=0)
			printf("\n");
		while(row--)
		{
			scanf("%d %d",&a,&b);
			if(diff != a-b)
				{
					cor = false;
				}
		}
		if(cor)
			printf("yes\n");
		else
			printf("no\n");

	}
	return 0;
}