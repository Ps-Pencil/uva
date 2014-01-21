#include<map>
#include<string>
#include<iostream>
#include<cstdio>
using namespace std;

int main()
{
	map<string, int> species;
	int T;
	scanf("%d\n\n",&T);
	while(T--)
	{
		if(!species.empty()) printf("\n");
		species.clear();
		string s;
		int total = 0;
		while(getline(cin,s))
		{
			if(s=="") break;
			total++;
			if(species.find(s)==species.end())
				species[s] = 1;
			else
				species[s]++;
		}
		for(map<string,int>::iterator it = species.begin(); it!=species.end();it++)
		{
			printf("%s %.4f\n",(it->first).c_str(),(double)(it->second * 100) / (double)total);
		}
	}
	return 0;
}