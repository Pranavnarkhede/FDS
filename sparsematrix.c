#include <stdio.h>

int main() {
   int r,c,count=0,i,j,k=0,p=0;
   printf("Enter rows an columns of matrix:");
   scanf("%d %d",&r,&c);
   int a[r][c];
   printf("Enter matrix elements:");
   for(i=0;i<r;i++)
   {
       for(j=0;j<c;j++)
       {
           scanf(" %d",&a[i][j]);
           if(a[i][j]!=0)
           {
               k++;
           }
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
       printf("Matrix A is sparse matrix\n");
   }
   else
   {
      printf("Matrix A is not sparse matrix\n");
   }
  int s[k][3];
  for(i=0;i<r;i++)
  {
   for(j=0;j<c;j++)
   {
       if(a[i][j]!=0)
       {
           s[p][0]=i;
           s[p][1]=j;
           s[p][2]=a[i][j];
           p++;
       }
   }
  }
  printf("Triplet Reprenstation of Sparse Matrix:\n");
  for(i=0;i<k;i++)
  {
    for(j=0;j<3;j++)
    {
       printf("%d \t",s[i][j]);
    }
    printf("\n");
  }
  
   
    return 0;
}
