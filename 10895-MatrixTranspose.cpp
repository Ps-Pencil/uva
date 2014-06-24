#include<cstdio>
#include<vector>


using namespace std;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

int main()
{
	int m,n;
	while(scanf("%d %d",&m,&n)!=EOF){
	vector<vii> adj;
	adj.assign(n+1,vii());
	for(int i=1;i<=m;i++)
	{
		int p;
		scanf("%d",&p);
		vi index,value;
		for(int j=0;j<p;j++)
		{
			int q;
			scanf("%d",&q);
			index.push_back(q);
		}
		for(int j=0;j<p;j++)
		{
			int q;
			scanf("%d",&q);
			value.push_back(q);
		}
		for(int j=0;j<p;j++)
		{
			adj[index[j]].push_back(ii(i,value[j]));
		}
	}
	printf("%d %d\n",n,m);
	for(int i=1;i<=n;i++)
	{
		printf("%lu",adj[i].size());
		for(int j=0;j<adj[i].size();j++)
		{
			printf(" %d",adj[i][j].first);
		}
		printf("\n");
		if(adj[i].size()>0)
		printf("%d",adj[i][0].second);
		for(int j=1;j<adj[i].size();j++)
			printf(" %d",adj[i][j].second);
		printf("\n");
	}
}
	return 0;


}