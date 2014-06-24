//Segment Tree
#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
typedef vector<int> vi;

class SegmentTree{
private: vi st,A;
	int n;
	int left(int p) {return p<<1;}
	int right(int p) {return (p<<1)+1;}
	void build(int p, int L,int R){
		if(L==R)
			st[p] = L;
		else{
			build(left(p),L,(L+R)/2);
			build(right(p),(L+R)/2+1,R);
			int p1 = st[left(p)],p2 = st[right(p)];
			st[p] = (A[p1] <= A[p2])?p2:p1;
		}
		/*if(p==1)
		{
			for(int i=0;i<n;i++)
				printf("%d ",st[i]);
			printf("\n");
		}*/
	}
	int rmq(int p, int L,int R, int i, int j){
		if(i>R || j<L) return -1;
		if(L>=i && R<=j) return st[p];
		int p1 = rmq(left(p),L,(L+R)/2,i,j);
		int p2 = rmq(right(p),(L+R)/2+1,R,i,j);

		if(p1 == -1) return p2;
		if(p2 == -1) return p1;
		return (A[p1] <= A[p2])?p2:p1;
	}
public:
	SegmentTree(const vi &_A){
		A = _A; n = (int)A.size();
		st.assign(4*n,0);
		build(1,0,n-1);
	}
	int rmq(int i, int j){return A[rmq(1,0,n-1,i,j)];}
};
int main()
{
	int n,q;
	while(scanf("%d",&n),n)
	{
		scanf("%d",&q);
		vi seq;
		seq.assign(n,0);
		for(int i=0;i<n;i++)
		{
			int x;
			scanf("%d",&x);
			seq[i] = x;
		}

		vi left(n,0), right(n,0),C(n,0);
		for(int i=1;i<n;i++)
		{
			if(seq[i] == seq[i-1])
				left[i] = left[i-1];
			else
				left[i] = i;
		}

		for(int i=n-1;i>=0;i--)
		{
			if(i==n-1 or seq[i] != seq[i+1])
				right[i] = i;
			else
				right[i] = right[i+1];
		}

		for(int i=0;i<n;i++)
		{
			C[i] = right[i]-left[i]+1;
		//	printf("%d\n",C[i]);
		}
		SegmentTree T(C);
		for(int i=0;i<q;i++)
		{
			int a,b;

			scanf("%d %d",&a,&b);
			a--;b--;
			if(seq[a]==seq[b])
				{printf("%d\n",b-a+1);continue;}
			printf("%d\n",max(max(right[a]-a+1,b-left[b]+1),T.rmq(right[a]+1,left[b]-1)));
		}

	}
	return 0;
}