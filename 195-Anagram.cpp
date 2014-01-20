#include<cstdio>
#include<iostream>
#include<string>
#include<algorithm>

using namespace std;
bool cmp(char a, char b)
{
	char a1 = a, b1 = b;
	if(a1>='A' and a1<='Z')
		a1 += 'a' - 'A';
	if(b1>='A' and b1<='Z')
		b1 += 'a' - 'A';
	if(a1 == b1)
		return a<b;
	else
		return a1<b1;
}
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		string s;
		cin>>s;
		sort(s.begin(),s.end(),cmp);
		do{
			cout<<s<<endl;
		}while(next_permutation(s.begin(),s.end(),cmp));
	}
	return 0;
}