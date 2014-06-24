#include<cstdio>
#include<vector>

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
			if(rank[x] > rank[y]) p[y] = x;
			else{
				p[x] = y;
				if(rank[x] == rank[y]) rank[y]++;
			}
		}
	}
};

int main()
{
	int T,x = 0;;
	scanf("%d",&T);
	while(T--)
	{
		if(x!=0)
			printf("\n");
		x++;
		int yes = 0,no = 0;
		int n;
		scanf("%d",&n);	
		getchar();
		UnionFind uf(n+1);
		char c;
		int a,b;
		while(scanf("%c",&c)!=EOF){
			//printf("%c\n",c);
			if(c == '\n') break;
		scanf(" %d %d",&a,&b);
		getchar();
		//printf("%c %d %d\n",c,a,b);
		if(c =='c')
			uf.unionSet(a,b);
		else
			if(uf.isSameSet(a,b))
				yes++;
			else
				no++;
		}
		printf("%d,%d\n",yes,no);

	}
	return 0;
}