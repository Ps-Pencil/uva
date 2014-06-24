#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector>
using namespace std;

char s[1000010],ss[110];
vector<int> idx[53];

int getSerial(char c)
{
	if(c>='A' and c<='Z')
		return c-'A';
	else
		return c-'a'+26;
}
int getChar(int s)
{
	if(s<26)
		return 'A'+s;
	else
		return 'a'+s-26;
}
int main(){
	scanf("%s",s);
	int l = strlen(s);
	for(int i=0;i<l;i++)
		idx[getSerial(s[i])].push_back(i);
	int Q;
	scanf("%d",&Q);
	while(Q--)
	{
		bool match = true;
		scanf("%s",ss);
		vector<int> seq;
		seq.push_back(-1);
		for(int i=0;i<strlen(ss);i++)
		{
			vector<int>::iterator it = lower_bound(idx[getSerial(ss[i])].begin(),idx[getSerial(ss[i])].end(),seq[seq.size()-1]+1);
			if(it==idx[getSerial(ss[i])].end())
			{
				match = false;
				break;
			}
			seq.push_back(*it);
		}
		if(!match)
			printf("Not matched\n");
		else
			printf("Matched %d %d\n",seq[1],seq[seq.size()-1]);
	}
	return 0;
}