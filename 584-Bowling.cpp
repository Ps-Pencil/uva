#include<cstdio>

using namespace std;

int main()
{
	char c;
	while((c=getchar())!='G')
	{
		char roll[50];
		roll[0] = c;
		int n = 1;
		while((c=getchar())!='\n')
			roll[n++] = getchar();
		int sum = 0,score[11] = {0};
		int frame = 1,r = 0;
		for(int i=0;i<n;i++)
		{
			if(frame==11)break;
			if(roll[i]>='0' and roll[i]<='9')
			{
				r++;
				score[frame]+=roll[i]-'0';
				if(r==2)
				{
					r = 0;
					frame++;
				}
			}
			else if(roll[i] == '/')
			{
				score[frame] = 10;
				if(roll[i+1]>='0' and roll[i+1]<='9')
					score[frame]+=roll[i+1]-'0';
				else
					score[frame] = 20;
				frame++;
				r = 0;
			}
			else
			{
				score[frame] = 10;
				if(roll[i+2]=='/')
					score[frame] = 20;
				else{
				if(roll[i+1]>='0' and roll[i+1]<='9')
					score[frame]+=roll[i+1]-'0';
				else
					score[frame] +=10;
				if(roll[i+2]>='0' and roll[i+2]<='9')
					score[frame]+=roll[i+2]-'0';
				else
					score[frame] +=10;
				}
				frame++;
			}

		}
		for(int i=1;i<11;i++)
		{
			//printf("%d ",score[i]);
			sum+=score[i];
		}//printf("\n");
		printf("%d\n",sum);

	}
	return 0;
}