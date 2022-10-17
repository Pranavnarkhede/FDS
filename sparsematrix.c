#include <stdio.h>

int main() {
   int r,c,count=0,i,j;
   printf("Enter rows an columns of matrix:");
   scanf("%d %d",&r,&c);
   int a[r][c];
   printf("Enter matrix elements:");
   for(i=0;i<r;i++)
   {
       for(j=0;j<c;j++)
       {
           scanf(" %d",&a[i][j]);
       }
       printf("\n");
   }
   printf("Matrix A:\n");
    for(i=0;i<r;i++)
   {
       for(j=0;j<c;j++)
       {
           printf("%d \t",a[i][j]);
       }
       printf("\n");
   }
   for(i=0;i<r;i++)
   {
       for(j=0;j<c;j++)
       {
        if(a[i][j]==0)
        count++;
       }
   }   
   if(count>((i*j)/2))
   {
       printf("Matrix A is sparse matrix");
   }
   else
   {
      printf("Matrix A is not sparse matrix");
   }
   
   
    return 0;
}
