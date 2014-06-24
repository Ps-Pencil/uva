#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
	freopen("test11402","w",stdout);
	srand(time(NULL));
	
	int T = 10;
	printf("%d\n",T);
	for ( int t = 0 ; t < T ; ++ t ) {
		int m = rand()%100+1;
		int sum = 0;
		printf("%d\n",m);
		for ( int i = 0 ; i < m ; ++ i ) {
			int n = rand()%200+1;
			int l = rand()%50+1;
			printf("%d\n",n);
			for ( int j = 0 ; j < l ; ++ j )
				printf("%d",rand()%2);
			printf("\n");
			sum += n*l;
		}
		int q = rand()%1000+1;
		printf("%d\n",q);
		for ( int i = 0 ; i < q ; ++ i ) {
			switch( rand()%4 ) {
				case 0: printf("F ");break;
				case 1: printf("E ");break;
				case 2: printf("I ");break;
				case 3: printf("S ");break;
			}
			int x = rand()%sum;
			int y = rand()%sum;
			if ( x > y ) swap( x, y );
			printf("%d %d\n",x,y);
		}
	}
	return 0;
}
