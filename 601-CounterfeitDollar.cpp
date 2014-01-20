#include<cstdio>
#include<cstring>
using namespace std;

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		char word[10] = "light";
		char weigh[3][3][10];
		for(int i=0;i<3;i++)
			for(int j=0;j<3;j++)
				scanf("%s",weigh[i][j]);
		bool correct = true;
		for(int i=0;i<='L'-'A';i++)
		{
			correct = true;
			for(int k=0;k<3;k++)
			{
				int w1=0,w2=0;
				for(int l=0;l<strlen(weigh[k][0]);l++)
				{
					if(weigh[k][0][l] - 'A' ==i)
						w1 += 0;
					else
						w1+=1;
					if(weigh[k][1][l] -'A' == i)
						w2+=0;
					else
						w2+=1;
				}
				char ans[10];
				if(w1<w2)
					strcpy(ans,"down");
				else if(w1==w2)
					strcpy(ans,"even");
				else
					strcpy(ans,"up");
				if(strcmp(weigh[k][2],ans)!=0)
				{
					correct = false;
					break;
				}
			}
			if(correct)
			{
				printf("%c is the counterfeit coin and it is %s.\n",'A'+i,word);
				break;
			}
		}
		strcpy(word,"heavy");
		for(int i=0;i<='L'-'A';i++)
		{
			correct = true;
			for(int k=0;k<3;k++)
			{
				int w1=0,w2=0;
				for(int l=0;l<strlen(weigh[k][0]);l++)
				{
					if(weigh[k][0][l] - 'A' ==i)
						w1 += 2;
					else
						w1+=1;
					if(weigh[k][1][l] -'A' == i)
						w2+=2;
					else
						w2+=1;
				}
				char ans[10];
				if(w1<w2)
					strcpy(ans,"down");
				else if(w1==w2)
					strcpy(ans,"even");
				else
					strcpy(ans,"up");
				if(strcmp(weigh[k][2],ans)!=0)
				{
					correct = false;
					break;
				}
			}
			if(correct)
			{
				printf("%c is the counterfeit coin and it is %s.\n",'A'+i,word);
				break;
			}
		}
	}
	return 0;
}