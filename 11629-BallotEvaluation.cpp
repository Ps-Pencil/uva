#include<map>
#include<iostream>
#include<cstdio>
#include<string>

using namespace std;

int main()
{
	int p,g;
	scanf("%d %d\n",&p,&g);
	map<string,int> party;
	for(int i=0;i<p;i++)
	{
		string s;
		int a,b;
		cin>>s;
		scanf("%d.%d",&a,&b);
		party[s] = a*10+b;
	}
	for(int tc = 1; tc<=g;tc++)
	{
		int sum = 0;
		string s;
		cin>>s;
		sum+=party[s];
		while(cin>>s)
		{
			if(s=="+")
			{
				cin>>s;
				sum+=party[s];
			}
			else
			{
				int n;
				cin>>n;
				n*=10;
				printf("Guess #%d was ",tc);
				string a = "incorrect";
				//printf("%d %d\n",sum,n);
					if(s == "<" && sum < n)
						a = "correct";
					if(s == ">" && sum > n)
						a = "correct";
					if(s == "<=" && sum <= n)
						a = "correct";
					if(s == ">=" && sum >= n)
						a = "correct";
					if(s == "=" && sum==n)
						a = "correct";

				printf("%s.\n",a.c_str());
				break;
			}
		}
	}
	return 0;
}