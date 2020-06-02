#include <stdio.h>
#include <stdlib.h>

int min(int a,int b)
{
   if(a<b)
   {
       return a;
   }
   return b;
}

    int c[100][100];  
void binCoeff(int n,int k)
{
     
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<min(i,k);j++)
        {
            if(j==0 || j==1)
            {
                c[i][j]=1;

            }
            else{
                c[i][j]=c[i-1][j-1]+c[i-1][j];
            }
        }
    }
  
}


int main()
{
    int t;
    scanf("%c",&t);
    while(t-->0)
    {
        int n ;
        scanf("%d",&n);
        int k;
        scanf("%d",&k);
        binCoeff(n,k);
        printf("Computed matrix is \n");
        for(int i=0;i<=n;i++)
        {
            for(int j=0;j<min(i,k);j++)
            {
                printf("%d\t",c[i][j]);
            }
            printf("\n");
        }
        printf("bin coeff c[%d,%d] =%d\n",n,k,c[n][k]);

    }
    return 0;
}