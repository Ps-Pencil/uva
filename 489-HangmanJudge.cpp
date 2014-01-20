#include<cstdio>
#include<cstring>
using namespace std;

int main()
{
	int r;
	while(scanf("%d",&r))
	{
		if(r==-1)
			break;
		char word[100],guess[100];
		scanf("%s\n%s\n",word,guess);
		bool guessed[26] = {false},correct[26] = {0};
		int win = 0, lose = 0, length = 0;
		for(int i=0;i<strlen(word);i++)
		{
			if(correct[word[i]-'a']!=1)
				length++;
			correct[word[i]-'a'] = 1;
		}
		for(int i=0;i<strlen(guess);i++)
		{
			int index = guess[i]-'a';
			if(guessed[index])
				continue;
			if(correct[index])
			{
				win++;
				guessed[index] = true;
				if(win == length)
					break;
			}
			else
			{
				lose++;
				guessed[index] =true;
				if(lose == 7)
					break;
			}
		}
		printf("Round %d\n",r);
		if(win==length)
			printf("You win.\n");
		else if(lose == 7)
			printf("You lose.\n");
		else
			printf("You chickened out.\n");
	}
	return 0;
}