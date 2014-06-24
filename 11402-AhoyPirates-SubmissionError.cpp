///SubmissionError
#include<cstdio>
#include<vector>
#include<cstring>
#include<algorithm>
#include<set>
#define CLEAR 0
#define SET 1
#define NORMAL -1
#define FLIP 2
#define left(i) i<<1
#define right(i) (i<<1)+1
using namespace std;

struct Node{
	int sum;
	int start;
	int end;
};


typedef vector<int> vi;

class SegmentTree{
private:
	vector<Node> st,*A;
	vi state;
	int n;
	void build(int p,int L,int R){
		if(L==R)
			st[p] = (*A)[L];
		else{
			build(left(p),L,(L+R)/2);
			build(right(p),(L+R)/2+1,R);
			Node p1 = st[left(p)],p2 = st[right(p)];
			st[p].sum = p1.sum+p2.sum;
			st[p].start = p1.start;
			st[p].end = p2.end;
		}
		return;
	}
	int rsq(int p,int i,int j){
		if(i>st[p].end || j<st[p].start) return 0;
		propagate(p);
		if(st[p].start>=i && st[p].end<=j) return st[p].sum;
		int p1 = rsq(left(p),i,j);
		int p2 = rsq(right(p),i,j);
		//printf("= %d %d %d %d %d\n",p,st[p].start,st[p].end,p1,p2);
		return p1+p2;
	}
	int set(int p, int i, int j){
		propagate(p);
		if(i>st[p].end || j<st[p].start) return 0;
		
		if(st[p].start>=i && st[p].end<=j) {st[p].sum = st[p].end - st[p].start+1;state[left(p)] = state[right(p)] = SET;return 0;}
		set(left(p),i,j);
		set(right(p),i,j);
		st[p].sum = st[left(p)].sum + st[right(p)].sum;
		return 0;
	}
	int clear(int p, int i, int j){
		propagate(p);
		if(i>st[p].end || j<st[p].start) return 0;
		
		if(st[p].start>=i && st[p].end<=j) {st[p].sum = 0;state[left(p)] = state[right(p)] = CLEAR;return 0;}
		clear(left(p),i,j);
		clear(right(p),i,j);
		st[p].sum = st[left(p)].sum + st[right(p)].sum;
		return 0;
	}
	int flip(int p,int i,int j){
		//printf("flip %d %d %d\n",p,st[p].start,st[p].end);
		propagate(p);
		if(i>st[p].end||j<st[p].start) return 0;
		
		if(st[p].start>=i && st[p].end<=j) {st[p].sum = st[p].end - st[p].start+1 - st[p].sum; state[left(p)] = flip_state(state[left(p)]);state[right(p)] = flip_state(state[right(p)]);return 0;}
		flip(left(p),i,j);
		flip(right(p),i,j);
		st[p].sum = st[left(p)].sum + st[right(p)].sum;
		//printf("{%d %d %d}\n",st[p].start,st[p].end,st[p]);
		return 0;
	}
	int flip_state(int s)
	{
		switch(s){
			case NORMAL:
			return FLIP;
			case FLIP:
			return NORMAL;
			case SET:
			return CLEAR;
			case CLEAR:
			return SET;
		}
		return 0;
	}
	int propagate(int p)
	{
		
		if(state[p] == SET) {st[p].sum = st[p].end-st[p].start+1;state[left(p)] = state[right(p)] = SET;}
		else if(state[p] == CLEAR) {st[p].sum = 0;state[left(p)] = state[right(p)] = CLEAR;}
		else if(state[p] == FLIP )
		{
			st[p].sum =st[p].end-st[p].start+1 - st[p].sum;
			if(st[p].start!=st[p].end)
			{
				state[left(p)] = flip_state(state[left(p)]);state[right(p)] = flip_state(state[right(p)]);			}
			
		}
		//printf("[%d %d %d %d %d]\n",p,st[p].start,st[p].end,state[p],st[p]);
		state[p] = NORMAL;
		return 0;
	}
public:
	SegmentTree(const vector<Node> &_A){
		A = (vector<Node>*)&_A;n = (int)_A.size();
		Node x;
		st.assign(4*n + 100,x);
		state.assign(4*n + 100,NORMAL);
		build(1,0,n-1);
	}
	int rsq(int i,int j){return rsq(1,i,j);}
	int set(int i,int j){return set(1,i,j);}
	int clear(int i,int j){return clear(1,i,j);}
	int flip(int i,int j){return flip(1,i,j);}
	/*void print() {return print(1,0,n-1);}
	void print(int p,int st[p].start,int st[p].end)
	{
		printf("(%d %d %d %d %d)\n",p,st[p].start,st[p].end,st[p].sum,state[p]);
		if(st[p].start==st[p].end) return;
		print(left(p),st[p].start,(st[p].start+st[p].end)/2);
		print(right(p),(st[p].start+st[p].end)/2+1,st[p].end);
		return;
	}*/
};

int main()
{
	int T;
	scanf("%d",&T);
	for(int TC = 1;TC<=T;TC++)
	{
		printf("Case %d:\n",TC);
		vi pirates;
		int M;
		scanf("%d",&M);
		vector<char> ops;
		vi index;
		vector<bool> bound;
		for(int i=0;i<M;i++)
		{
			int n;
			scanf("%d",&n);
			char p[100];
			scanf("%s",p);
			for(int j=0;j<n;j++)
				for(int k = 0; k<strlen(p);k++)
					pirates.push_back(p[k]-'0');
		}
		bound.assign(pirates.size(),0);
		int q,qn = 1;
		scanf("%d",&q);
		for(int i = 0;i<q;i++)
		{
			char c[10];
			int l,r;
			scanf("%s %d %d",c,&l,&r);
			//printf("%s %d %d\n",c,l,r);
			ops.push_back(c[0]);
			index.push_back(l);
			index.push_back(r);
			bound[l] = bound[r] = 1;
				//T.print();
		}
		vector<Node> tree;
		Node node;
		node.start = 0;
		int count = 0;
		vector<int> mapping;
		mapping.assign(pirates.size(),0);
		for(int i=0;i<pirates.size();i++)
		{
			if(bound[i])
			{
				if(i!=0 && node.start!=i)
				{
					node.end = i-1;
					node.sum = count;
					tree.push_back(node);
				}
				Node a;
				a.start = a.end = i;
				a.sum = pirates[i];
				mapping[i] = tree.size();
				tree.push_back(a);
				node.start = i+1;
				count = 0;
			}
			else
				count+=pirates[i];
		}
		//for(int i=0;i<tree.size();i++)
		//	printf("%d %d %d\n",tree[i].start,tree[i].end,tree[i].sum);
		SegmentTree ST(tree);
		for(int i=0;i<index.size();i+=2)
		{
			//printf("%d %d %d %d\n",index[i],index[i+1],index[i],index[i+1]);
			switch(ops[i/2]){
				case 'F':
				ST.set(index[i],index[i+1]);
				break;
				case 'E':
				ST.clear(index[i],index[i+1]);
				break;
				case 'I':
				ST.flip(index[i],index[i+1]);
				break;
				case 'S':
				printf("Q%d: %d\n",qn++,ST.rsq(index[i],index[i+1]));
				break;
			}
			//ST.print();
			//printf("\n");
		}
	}
	return 0;
}