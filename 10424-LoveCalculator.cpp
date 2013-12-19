#include<cstdio>
#include<string>
#include<iostream>
using namespace std;

int find_sum(string s)
{
	int sum = 0;
	for(int i=0;i<s.size();i++)
		if(s[i]>='A'&&s[i]<='Z')
			sum+=s[i]-'A'+1;
		else if(s[i]>='a'&&s[i]<='z')
			sum+=s[i]-'a'+1;
	while(sum>=10)
	{
		int new_sum = 0;
		while(sum!=0)
		{
			new_sum+=sum%10;
			sum/=10;
		}
		sum=new_sum;
	}
	return sum;
}
int main()
{
	string s1,s2;
	while(getline(cin,s1))
	{
		getline(cin,s2);
		int sum1 = find_sum(s1);
		int sum2 = find_sum(s2);
		if(sum1>sum2)
			printf("%.2f %%\n",(double)sum2 * 100.0 / (double)sum1);
		else
			printf("%.2f %%\n",(double)sum1 * 100.0 / (double)sum2);
	}
	return 0;
}
	