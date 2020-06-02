<<<<<<< HEAD
#include <time.h>
#include <stdio.h>
#include <stdlib.h>


int min(int x ,int y)
{
    if (x<y)
    {
        return x;
    }
    return y;
}
int gcd(int a, int b) {
	int opcount=0;
	if (a > b){
		
		gcd(b, a);
		}
	int fact = 2;
	int gcd = 1;
	int z = a;
	for (fact = 2; fact <= z; fact ++) {
		opcount++;
        printf("the value of opcount is %d\n",opcount);
		while (((a % fact) == 0) && ((b % fact) == 0)) {
			
			gcd = gcd * fact;
			b = b / fact;
			a = a / fact;
			if (a == 0 || b == 0) 
				return gcd;
		}
	}
	
	return gcd;
}

int main()
{
    srand(time(NULL));
    int iter=0;
    printf("Enter the number of iterations required\n");
   
    scanf("%d",&iter);
    //no1 and no2 are the two numbers considered for gcd
    int no1=0;
    int no2=0;
    int ans=0;
    int sum=0;
    while(iter-- >0)
    {
         no1 = rand()%101;
         no2 = rand()%101;

         ans =gcd(no1,no2);
         printf("The gcd is %d\n",ans);
         sum = no1+no2;
         printf("The value of m+n is %d\n",sum);
    }    
return 0;
}
=======
#include <time.h>
#include <stdio.h>
#include <stdlib.h>


int min(int x ,int y)
{
    if (x<y)
    {
        return x;
    }
    return y;
}
int gcd(int a, int b) {
	int opcount=0;
	if (a > b){
		
		gcd(b, a);
		}
	int fact = 2;
	int gcd = 1;
	int z = a;
	for (fact = 2; fact <= z; fact ++) {
		opcount++;
        printf("the value of opcount is %d\n",opcount);
		while (((a % fact) != 0) && ((b % fact) != 0)) {
			
			gcd = gcd * fact;
			b = b / fact;
			a = a / fact;
			if (a == 0 || b == 0) 
				return gcd;
		}
	}
	
	return gcd;
}

int main()
{
    srand(time(NULL));
    int iter=0;
    printf("Enter the number of iterations required\n");
   
    scanf("%d",&iter);
    //no1 and no2 are the two numbers considered for gcd
    int no1=0;
    int no2=0;
    int ans=0;
    int sum=0;
    while(iter-- >0)
    {
         no1 = rand()%101;
         no2 = rand()%101;

         ans =gcd(no1,no2);
         printf("The gcd is %d\n",ans);
         sum = no1+no2;
         printf("The value of m+n is %d\n",sum);
    }    
return 0;
}
>>>>>>> 21f53057af87e5525be185888267a11aa297548e
