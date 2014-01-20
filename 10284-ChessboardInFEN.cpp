#include<cstdio>
#include<cstring>
using namespace std;
int main()
{
    char chess[10][10],string[200];
    bool attacked[10][10];
    memset(chess,'0',sizeof(chess));
    memset(attacked,0,sizeof(attacked));
    char c;
    int x=1,y=1;
    while(scanf("%s",string)!=EOF)
    {
        for(int index = 0;index<strlen(string);index++)
        {
            c = string[index];
            if(c<'9' and c>'0')
            {
                y+=c-'0';
                continue;
            }
            if(c == '/')
            {
                x+=1;
                y = 1;
                continue;
            }
            chess[x][y++] = c;
        }
        for(int i=1;i<9;i++)
        {
            for(int j=1;j<9;j++)
            {
                if(chess[i][j]!='0') attacked[i][j] = 1;
                if(chess[i][j] ==  'P')
                attacked[i-1][j+1] = attacked[i-1][j-1] = 1;
                else if(chess[i][j] == 'p')
                attacked[i+1][j+1] = attacked[i+1][j-1] = 1;
                else if(chess[i][j] =='k' or chess[i][j] == 'K')
                attacked[i-1][j-1] = attacked[i-1][j] = attacked[i-1][j+1] = attacked[i][j-1] = attacked[i][j+1]= attacked[i+1][j-1] = attacked[i+1][j] = attacked[i+1][j+1] = 1;
                else if(chess[i][j] == 'r' or chess[i][j] == 'R')
                {
                    for(int x1 = i-1;x1>0 && chess[x1][j] == '0';x1--)
                    attacked[x1][j] = 1;
                    for(int x1 = i+1;x1<9 && chess[x1][j] == '0';x1++)
                    attacked[x1][j] = 1;
                    for(int y1 = j-1;y1>0 && chess[i][y1] == '0';y1--)
                    attacked[i][y1] = 1;
                    for(int y1 = j+1;y1<9 && chess[i][y1] == '0';y1++)
                    attacked[i][y1] = 1;
                }
                else if(chess[i][j] == 'b' or chess[i][j] =='B')
                {
                    for(int k = 1; i-k>0 && j-k>0 && chess[i-k][j-k] == '0';k++)
                    attacked[i-k][j-k] = 1;
                    for(int k = 1; i+k<9 && j-k>0 && chess[i+k][j-k] == '0';k++)
                    attacked[i+k][j-k] = 1;
                    for(int k = 1; i-k>0 && j+k<9 && chess[i-k][j+k] == '0';k++)
                    attacked[i-k][j+k] = 1;
                    for(int k = 1; i+k<9 && j+k<9 && chess[i+k][j+k] == '0';k++)
                    attacked[i+k][j+k] = 1;
                }
                else if(chess[i][j] == 'Q' or chess[i][j] == 'q')
                {
                    for(int x1 = i-1;x1>0 && chess[x1][j] == '0';x1--)
                    attacked[x1][j] = 1;
                    for(int x1 = i+1;x1<9 && chess[x1][j] == '0';x1++)
                    attacked[x1][j] = 1;
                    for(int y1 = j-1;y1>0 && chess[i][y1] == '0';y1--)
                    attacked[i][y1] = 1;
                    for(int y1 = j+1;y1<9 && chess[i][y1] == '0';y1++)
                    attacked[i][y1] = 1;
                    for(int k = 1; i-k>0 && j-k>0 && chess[i-k][j-k] == '0';k++)
                    attacked[i-k][j-k] = 1;
                    for(int k = 1; i+k<9 && j-k>0 && chess[i+k][j-k] == '0';k++)
                    attacked[i+k][j-k] = 1;
                    for(int k = 1; i-k>0 && j+k<9 && chess[i-k][j+k] == '0';k++)
                    attacked[i-k][j+k] = 1;
                    for(int k = 1; i+k<9 && j+k<9 && chess[i+k][j+k] == '0';k++)
                    attacked[i+k][j+k] = 1;
                }
                else if(chess[i][j] == 'n' or chess[i][j] == 'N')
                {
                    if(i>1)
                    attacked[i-2][j+1] = attacked[i-2][j-1] = 1;
                    if(i<9)
                    attacked[i+2][j-1] = attacked[i+2][j+1] = 1;
                    if(j>1)
                    attacked[i-1][j-2] = attacked[i+1][j-2] = 1;
                    if(j<9)
                    attacked[i-1][j+2] = attacked[i+1][j+2] = 1;
                }
            }
        }
        int empty = 0;
        for(int i=1;i<9;i++)
        {
            for(int j=1;j<9;j++)
            {
                //printf("%d ",attacked[i][j]);
                if(attacked[i][j] == 0)
                empty++;
            }
            //printf("\n");
        }
        printf("%d\n",empty);
        memset(attacked,0,sizeof(attacked));
        memset(chess,'0',sizeof(chess));
        x = y = 1;
    }
    return 0;
}
