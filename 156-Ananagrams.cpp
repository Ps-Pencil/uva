#include<cstdio>
#include<string>
#include<iostream>
#include<algorithm>
using namespace std;

int cmp(string a, string b)
{
	string a1 = a, b1 = b;
	for(int i=0;i<a1.size();i++)
		if(a1[i]>='A' and a1[i]<='Z')
			a1[i]+='a' - 'A';
	for(int i=0;i<b1.size();i++)
		if(b1[i]>='A' and b1[i]<='Z')
			b1[i]+='a' - 'A';
	sort(a1.begin(),a1.end());
	sort(b1.begin(),b1.end());
	if(a1==b1)
		return 0;
	else if(a1<b1)
		return 1;
	else
		return 0;
}
int cmp2(string a, string b)
{
	string a1 = a, b1 = b;
	for(int i=0;i<a1.size();i++)
		if(a1[i]>='A' and a1[i]<='Z')
			a1[i]+='a' - 'A';
	for(int i=0;i<b1.size();i++)
		if(b1[i]>='A' and b1[i]<='Z')
			b1[i]+='a' - 'A';
	sort(a1.begin(),a1.end());
	sort(b1.begin(),b1.end());
	if(a1==b1)
		return -1;
	else if(a1<b1)
		return 1;
	else
		return 0;
}
int main()
{
	//printf("%d %d\n",cmp("leader","dealer"),cmp("dealer","ladder"));
	string dict[1000];
	string newd[1000];
	int m = 0;
	int n = 0;
	string s;
	while(cin>>s)
	{
		if(s=="#")
		{
			sort(dict,dict+n,cmp);
			//for(int i=0;i<n;i++)
			//	cout<<dict[i]<<' ';
			//cout<<endl;
			if(cmp2(dict[0],dict[1])!=-1)
			newd[m++] = dict[0];
			for(int i=1;i<n-1;i++)
			if(cmp2(dict[i],dict[i+1])!=-1 and cmp2(dict[i],dict[i-1])!=-1)
				newd[m++] = dict[i];
			if(cmp2(dict[n-1],dict[n-2])!=-1)
			newd[m++] = dict[n-1];
			break;
		}
		dict[n++]=s;
		
	}
	sort(newd,newd+m);
	for(int i=0;i<m;i++)
		cout<<newd[i]<<endl;
	return 0;
}