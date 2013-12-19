//AC
//might be optimised by the use of STL map
#include<cstdio>
#include<cstring>
#include<vector>

using namespace std;

int main()
{
	int d[2000001];
	memset(d,0,sizeof(d));
	d[1]=1;
	int a,b;
	while(scanf("%d %d",&a,&b)!=EOF)
	{
		printf("%d %d",a,b);
		if(a>b)
		{
			int t=a;
			a=b;
			b=t;
		}
		int max = 0;
		for(int i=a;i<=b;i++)
		{
			if(d[i]>max)
			{
				max=d[i];
				continue;
			}
			vector<int> seq;
			seq.push_back(i);
			while(seq[seq.size()-1]!=1)
			{
				a = seq[seq.size()-1];
				if(a<2000001&&d[a]!=0) break;
				if(a%2==0)
					seq.push_back(a/2);
				else
					seq.push_back(a*3+1);
			}
			for(int j=seq.size()-2;j>=0;j--)
				{
					if(seq[j]<2000001)
					d[seq[j]] = d[seq[seq.size()-1]] + seq.size() - 1 - j;
			}

			if(d[i]>max)
				max = d[i];
		}
		printf(" %d\n",max);
	}
	return 0;
}