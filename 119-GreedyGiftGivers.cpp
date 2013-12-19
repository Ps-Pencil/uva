//AC
#include<cstdio>
#include<cstring>
using namespace std;

int main()
{
	int n;
	bool start = true;
	while(scanf("%d",&n)!=EOF){
		if(!start)
			printf("\n");
	char names[20][20];
	int give[20], take[20];
	for(int i=0;i<n;i++)
	{
		scanf("%s",names[i]);
		take[i] = 0;
		give[i] = 0;
	}
	for(int i=0;i<n;i++)
	{
		int money,m,g;
		char giver[20];
		scanf("%s %d %d",giver,&money,&m);

		for(int k=0;k<n;k++)
		{
			if(strcmp(giver,names[k])==0)
			{
				g = k;
				break;
			}
		}
		if(m!=0) {
		give[g] = (money/m) * m;
		//take[i] += money - give[i];
		for(int j=0;j<m;j++)
		{
			char name[20];
			scanf("%s",name);
			for(int k=0;k<n;k++)
			{
				if(strcmp(name,names[k]) == 0)
				{
					take[k] += money/m;
					break;
				}
			}
		}}
	}

	for(int i=0;i<n;i++)
	{
		printf("%s %d\n",names[i],take[i] - give[i]);
	}
	start = false;

}}