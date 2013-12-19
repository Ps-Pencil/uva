//AC
#include<cstdio>
#include<string>
#include<iostream>
#include<cmath>
using namespace std;

int main()
{
	int n,p,index = 1;;
	while(scanf("%d %d\n",&n,&p),n)
	{
		string req[1001];
		for(int i=0;i<n;i++)
		{
			getline(cin,req[i]);
		}
		double maxC = 0.0;
		string prop;
		double maxP = 0.0;
		for(int i=0;i<p;i++)
		{
			string name;
			getline(cin,name);
			double price;
			int num;
			scanf("%lf %d\n",&price,&num);
			for(int j=0;j<num;j++)
			{
				string str;
				getline(cin,str);
			}
			double comp = (double)num / (double)p;
			if(comp>maxC)
			{
				maxC = comp;
				prop = name;
				maxP = price;
			}
			else if(fabs(maxC - comp) < 1e-6)
			{
				if(price < maxP)
				{
					prop = name;
					maxP = price;
				}
			}
		}
		if(index!=1)printf("\n");
		printf("RFP #%d\n",index++);
		cout<<prop<<endl;
	}
	return 0;
}