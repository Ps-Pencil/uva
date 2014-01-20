#include<cstdio>
#include<list>
#include<string>
#include<iostream>

using namespace std;

int main()
{
	list<char> sentence;
	list<char>::iterator it;
	string s;
	while(getline(cin,s))
	{
		sentence.clear();
		it = sentence.begin();
		for(int i = 0; i < s.size();i++)
		{
			if(s[i] == '[')
				it = sentence.begin();
			else if(s[i] == ']')
				it = sentence.end();
			else
			{
				sentence.insert(it,s[i]);
			}
		}
		it = sentence.begin();
		for(;it!=sentence.end();it++)
			putchar(*it);
		putchar('\n');
	}
	return 0;
}