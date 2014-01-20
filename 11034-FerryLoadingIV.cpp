//Always check for empty before use front()

#include<cstdio>
#include<queue>
#include<cstring>
using namespace std;

int main()
{
	int T;
	scanf("%d\n",&T);
	while(T--)
	{
		int l,m;
		scanf("%d %d\n",&l,&m);
		l*=100;
		queue<int> left,right;
		for(int i=0;i<m;i++)
		{
			int len;
			char side[10];
			scanf("%d %s\n",&len,side);
			if(strcmp(side,"right")==0)
				right.push(len);
			else
				left.push(len);
		}

		int pos = 0,change = 0;
		while(!(left.empty() and right.empty()))
		{
			if(pos == 0)
			{
				int Sum = 0;
				while(!left.empty() and Sum + left.front() <= l)
				{
					Sum+=left.front();
					left.pop();
				}
				pos = 1;change++;

			}
			else
			{
				int Sum = 0;

				while(!right.empty() && Sum + right.front() <= l)
				{
					Sum+=right.front();
					right.pop();
				}
				pos = 0;change++;
			}

		}

		printf("%d\n",change);
	}
	return 0;
}