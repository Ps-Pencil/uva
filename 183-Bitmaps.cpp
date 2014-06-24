#include<cstdio>
#include<cstring>
#include<string>
using namespace std;

char bm[300][300];
int m,n;
char s[100000];
string toD(int t,int b,int l,int r)
{
	string s=" ";
	if(t==b&&l==r){
		s[0]=bm[t][l];
		return s;
	}
	else if(t==b)
	{
		string s1 = toD(t,b,l,(l+r)/2);
		string s2 = toD(t,b,(l+r)/2+1,r);
		if(s1[0]!=s2[0] or s1[0]=='D' or s2[0]=='D')
			return "D"+s1+s2;
		else if(s1[0]=='1')
			return "1";
		else
			return "0";
	}
	else if(l==r)
	{
		string s1 =toD(t,(t+b)/2,l,r);
		string s2 = toD((t+b)/2+1,b,l,r);
		if(s1[0]!=s2[0] or s1[0]=='D' or s2[0]=='D')
			return "D"+s1+s2;
		else if(s1[0]=='1')
			return "1";//+s1+s2;
		else
			return "0";//+s1+s2;

	}
	else{
		string s1 = toD(t,(t+b)/2,l,(l+r)/2);
		string s2 = toD(t,(t+b)/2,(l+r)/2+1,r);
		string s3 = toD((t+b)/2+1,b,l,(l+r)/2);
		string s4 = toD((t+b)/2+1,b,(l+r)/2+1,r);
		if(!(s1[0] == s2[0] and s2[0] == s3[0] and s3[0]==s4[0])or s1[0]=='D' or s2[0]=='D' or s3[0] =='D' or s4[0]=='D')
			return "D"+s1+s2+s3+s4;
		else if(s1[0]=='1')
			return "1";//+s1+s2+s3+s4;
		else
			return "0";//+s1+s2+s3+s4;
	}
}

int toB(int t,int b,int l,int r)
{
	char c = getchar();
	if(c=='\n')
		c = getchar();
	if(c=='0' or c=='1')
	{
		for(int i=t;i<=b;i++)
			for(int j=l;j<=r;j++)
				bm[i][j]=c-'0';
	}
	else{
		if(t==b)
		{
			toB(t,b,l,(l+r)/2);
			toB(t,b,(l+r)/2+1,r);
		}
		else if(l==r)
		{
			toB(t,(t+b)/2,l,r);
			toB((t+b)/2+1,b,l,r);
		}
		else{
			toB(t,(t+b)/2,l,(l+r)/2);
			toB(t,(t+b)/2,(l+r)/2+1,r);
			toB((t+b)/2+1,b,l,(l+r)/2);
			toB((t+b)/2+1,b,(l+r)/2+1,r);
		}
	}
	return 0;
}
int main()
{
	char c;
	while(scanf("%c",&c)!=EOF)
	{
		if(c=='\n')
			c = getchar();
		if(c=='#') break;
		s[0]='\0';
		scanf("%d %d\n",&m,&n);
		
		if(c=='B')
		{
			int expected_length = m*n;
			while(strlen(s)!=expected_length)
			scanf("%s\n",s+strlen(s));
			for(int i=0;i<m;i++)
				for(int j=0;j<n;j++)
					bm[i][j] = s[i*n+j];
			printf("%c%4d%4d\n",'D',m,n);
			string ans = toD(0,m-1,0,n-1);
			int pos = 0;
			while(pos+50<=ans.size())
			{
				printf("%s\n",ans.substr(pos,50).c_str());
				pos+=50;
			}
			if(pos!=ans.size())
				printf("%s\n",ans.substr(pos).c_str());
		}
		else{
			printf("%c%4d%4d\n",'B',m,n);
			toB(0,m-1,0,n-1);
			int count = 0;
			for(int i=0;i<m;i++)
				for(int j=0;j<n;j++)
				{
					printf("%d",bm[i][j]);
					count++;
					if(count%50==0)
						printf("\n");
				}
			if(count%50!=0)
				printf("\n");
		}
	}
	return 0;
}