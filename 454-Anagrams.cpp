#include<iostream>
#include<cstdio>
#include<string>
#include<algorithm>

using namespace std;

bool cmp(string a, string b)
{
	string a1,b1;
	for(int i=0;i<a.size();i++)
		if(a[i]!=' ')
			a1+=a[i];
	for(int i=0;i<b.size();i++)
		if(b[i]!=' ')
			b1+=b[i];
	return a1<b1;
}
bool same(string a, string b)
{
	string a1,b1;
	for(int i=0;i<a.size();i++)
		if(a[i]!=' ')
			a1+=a[i];
	for(int i=0;i<b.size();i++)
		if(b[i]!=' ')
			b1+=b[i];
	string a2 = a1, b2 = b1;
	sort(a2.begin(),a2.end());
	sort(b2.begin(),b2.end());
	if(a2==b2)
		return true;
	else
		return false;
}
int main()
{
	int T;
	scanf("%d\n\n",&T);
	for(int x=0;x<T;x++)
	{
		string list[200];
		int n = 0;
		string s;
		while(getline(cin,s))
		{
			//cout<<"s is "<<s<<endl;
			if(s=="") break;
			list[n++] = s;
		}
		sort(list,list+n);
		if(x!=0) putchar('\n');

		for(int i=0;i<n-1;i++)
		{
			for(int k=i+1;k<n;k++)
				if(same(list[i],list[k]))
				cout<<list[i]<<" = "<<list[k]<<endl;
		}
	}
	return 0;
}