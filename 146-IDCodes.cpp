#include<cstdio>
#include<string>
#include<algorithm>
#include<iostream>
using namespace std;

int main()
{
	string str;
	while(cin>>str)
	{
		string a = str;
		if(str=="#")
			break;
		next_permutation(str.begin(),str.end());
		if(str>a)
		cout<<str<<endl;
		else
			printf("No Successor\n");
	}
	return 0;
}