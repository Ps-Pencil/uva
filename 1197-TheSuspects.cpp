#include<cstdio>
#include<vector>

using namespace std;


typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
class UnionFind{
private: 
	vi p,rank,size;
public:
	UnionFind(int N){rank.assign(N,0);
		p.assign(N,0);size.assign(N,1);for(int i=0;i<N;i++) p[i] = i;}
	int findSet(int i) {return(p[i] == i)?i:(p[i] = findSet(p[i]));}
	bool isSameSet(int i, int j){
		return findSet(i) == findSet(j);
	}
	void unionSet(int i, int j){
		if(!isSameSet(i,j)){
			int x = findSet(i),y = findSet(j);
			if(x == 0)
				{
					p[y] = x;
					size[x] += size[y];
				}
			else if(y == 0)
			{
				p[x] = y;
				size[y]+=size[x];
			}
			else
			{
				p[x] = y;
				size[y]+=size[x];
			}
			
		}
	}
	int findSize(int i){return size[findSet(i)];}
};
int main()
{
	int m,n;
	while(scanf("%d %d",&n,&m),n)
	{
		UnionFind uf(n);
		for(int i=0;i<m;i++)
		{
			int x;
			scanf("%d",&x);
			int first = -1;
			for(int j=0;j<x;j++)
			{
				int p;
				scanf("%d",&p);
				if(first == -1)
					first = p;
				else
					uf.unionSet(first,p);
			}
		}
		printf("%d\n",uf.findSize(0));

	}
	return 0;
}