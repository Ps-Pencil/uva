#include<cstdio>
#include<cstring>
#include<vector>
#include<map>
using namespace std;

typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
class UnionFind{
private: 
	vi p,rank;
public:
	UnionFind(int N){rank.assign(N,0);
		p.assign(N,0);for(int i=0;i<N;i++) p[i] = i;}
	int findSet(int i) {return(p[i] == i)?i:(p[i] = findSet(p[i]));}
	bool isSameSet(int i, int j){
		return findSet(i) == findSet(j);
	}
	void unionSet(int i, int j){
		if(!isSameSet(i,j)){
			int x = findSet(i),y = findSet(j);
			if(x==0) p[y] = x;
			else if(y==0) p[x] = y;
		}
	}
};
int main()
{
	int N;
	while(scanf("%d",&N)!=EOF)
	{
		UnionFind awaken(30);
		int M;
		scanf("%d\n",&M);
		char c;
		for(int i=0;i<3;i++)
		{
			c = getchar();
			awaken.unionSet(c-'A'+1, 0);
		}

		vector<vi> adj;
		adj.assign(30,vi());
		for(int i=0;i<M;i++)
		{
			char link[3];
			scanf("%s",link);
			adj[link[0]-'A'+1].push_back(link[1]);
			adj[link[1]-'A'+1].push_back(link[0]);

		}
		int years = 0,up = 3;
		while(up < N)
		{
			vector<int> u;
			years++;
			int inc = 0;
			for(int i=1;i<28;i++)
			{

				int x=0;
				if(adj[i].size()==0) continue;
				if(awaken.findSet(i)!=0)
					for(int j=0;j<adj[i].size();j++)
					{
						if(awaken.findSet(adj[i][j]-'A'+1) == 0)
							x++;
					}

				if(x>=3)
				{
					inc ++;
					up++;
					u.push_back(i);
				}
			}
			for(int i=0;i<u.size();i++) awaken.unionSet(0,u[i]);
			if(inc == 0) break;
		}
		if(up >= N)
		printf("WAKE UP IN, %d, YEARS\n",years);
		else
			printf("THIS BRAIN NEVER WAKES UP\n");


	}
	return 0;
}