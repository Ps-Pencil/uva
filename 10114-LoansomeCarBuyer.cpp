//AC
#include<cstdio>
#include<cmath>
using namespace std;

int main()
{
	int duration;
	while(scanf("%d",&duration)){
		if(duration < 0)
			break;
		double down,loan;
		int de;
		scanf("%lf %lf %d",&down,&loan,&de);
		double records[1000] = {0.0};

		for(int i = 0; i < de;i++)
		{
			int month;
			double de_value;
			scanf("%d %lf",&month,&de_value);
			records[month] = de_value;
		}
		double car = (double)(down + loan) * (1.0 - records[0]);
		double loan_value = loan / (double)duration;
		if(car > loan){
			printf("0 months\n");
			continue;
		}
		for(int i = 1 ; i <= duration ; i ++)
		{
			loan -= loan_value;
			double* de_value = &records[i];
			while(fabs(*de_value-0) < 1e-6)
				de_value --;
			car *= (1.0-*de_value);

			if(car > loan){
				if(i > 1)
					printf("%d months\n",i);
				else
					printf("%d month\n",i);
				break;
			}

		}
	}
	return 0;
}
