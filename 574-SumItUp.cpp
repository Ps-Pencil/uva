#include<cstdio>
#include<map>
#include<string>
using namespace std;
int n,t;
map<string,bool> used;

int main()
{
	while(scanf("%d %d",&t,&n),t)
	{
		used.clear();
		int num[20];
		for(int i=0;i<n;i++)
			scanf("%d",&num[i]);
		printf("Sums of %d:\n",t);
		int count = 0;
		for(int i=1;i<(1<<n);i++)
		{
			int sum = 0;
			for(int j=0;j<n;j++)
				if(i&(1<<j))
				{
					sum+=num[j];
					if(sum>t)
						break;
				}
			if(sum == t)
			{
				string result_str="";
				for(int j = 0; j < n;j++)
				{
					if((1<<j)==(i&(-i)))
						result_str+=to_string(num[j]);   //to_string requires c++11. Alternative can be used. 
					else if((1<<j)&i)
						result_str+="+"+to_string(num[j]);
				}
				if(!used[result_str])
					used[result_str] = 1;
				count++;
			}
		}
		string ans_str = "";
		for(map<string,bool>::iterator it = used.begin();it!=used.end();it++)
				if(it->second)
					ans_str = (it->first) + "\n" + ans_str;
		printf("%s",ans_str.c_str());

		if(count==0)
			printf("NONE\n");
	}
	return 0;
}