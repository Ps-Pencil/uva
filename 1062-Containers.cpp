#include<iostream>
#include<string>
#include<cstring>
#include<cstdio>
using namespace std;

int main()
{
	string s;
	int tc = 1;
	while(cin>>s)
	{
		if(s=="end") break;
		char con[30];
		memset(con,110,sizeof(con));
		int n = 0;
		for(int i=0;i<s.size();i++)
		{
			bool put = false;
			for(int j=0;j<n;j++)
			{
				if(con[j]>=s[i])
				{
					con[j] = s[i];
					put = true;
					break;
				}
			}
			if(!put)
				con[n++] = s[i];
		}
		printf("Case %d: %d\n",tc++,n );
	}
	return 0;
}