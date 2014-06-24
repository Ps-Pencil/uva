#include<cstdio>
#include<string>
#include<iostream>
#include<map>
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
	int findSet(int i) {
		return(p[i] == i)?i:(p[i] = findSet(p[i]));}
	bool isSameSet(int i, int j){
		return findSet(i) == findSet(j);
	}
	void unionSet(int i, int j){
		if(!isSameSet(i,j)){
			int x = findSet(i),y = findSet(j);
			if(rank[x] > rank[y]) {p[y] = x; size[x]+=size[y];}
			else{
				p[x] = y;
				size[y]+=size[x];
				if(rank[x] == rank[y]) rank[y]++;
			}

		}
	}
	int findSize(int i)
	{
		return size[findSet(i)];
	}
};
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int f,n=1;
		scanf("%d",&f);
		UnionFind network(2*f+1);
		map<string,int> name;
		for(int i=0;i<f;i++)
		{

			string x,y;
			cin>>x>>y;
			if(name[x]==0) name[x] = n++;
			if(name[y]==0) name[y] = n++;
			network.unionSet(name[x],name[y]);

			printf("%d\n",network.findSize(name[x]));
		}
	}
	return 0;
}