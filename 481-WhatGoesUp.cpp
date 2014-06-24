#include<cstdio>
#include<vector>
#include<algorithm>
#include<cstring>
using namespace std;

int seq[1000000],L,P[1000000],M[1000000];
int main()
{
	L = 0;
	memset(seq,0,sizeof(seq));
	memset(P,0,sizeof(P));
	memset(M,0,sizeof(M));
	int len = 0,x;
	while(scanf("%d",&x)!=EOF)
		seq[len++] = x;
	for(int i=0;i<len;i++)
	{
		int j=0;
		int left = 0,right = L;
		while(left<=right)
		{
			//printf("%d %d\n",left,right);
			int mid = (left+right)/2;
			if(seq[M[mid]]<seq[i])
			{
				if(mid>j)
				j = mid;
				left = mid+1;
			}
			else if(seq[M[mid]]>=seq[i])
				right = mid-1;
		}
		P[i] = M[j];
		if(j==L or seq[i]<seq[M[j+1]])
		{
			M[j+1] = i;
			if(j+1>L)
				L=j+1;
		}
	}
	printf("%d\n-\n",L);
	vector<int> s;
	int current = M[L];
	for(int i=0;i<L;i++)
	{
		s.push_back(seq[current]);
		current = P[current];
	}
	for(int i=L-1;i>=0;i--)
		printf("%d\n",s[i]);
	return 0;
}