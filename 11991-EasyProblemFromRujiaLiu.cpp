#include<cstdio>
#include<vector>

using namespace std;

int main()
{
	int m,n;
	vector< vector<int> > adj;
	while(scanf("%d %d",&m,&n)!=EOF)
	{
		adj.clear();
		
		adj.assign(1000001,vector<int>() );

		for(int i=1;i<=m;i++){
			int a;
			scanf("%d",&a);
			adj[a].push_back(i);
		}
		for(int i=0;i<n;i++)
		{
			int a,b;
			scanf("%d %d",&a,&b);
			if(adj[b].size() > a-1)
			printf("%d\n",adj[b][a-1]);
			else
				printf("0\n");
		}
	}
	return 0;

}