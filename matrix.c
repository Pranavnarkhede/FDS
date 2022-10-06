#include<stdio.h>
int main()
{
 int *p,*q,a[3][3],b[3][3],i,j,c[3][3],d[3][3],k,sum;
 p=&a[0][0];
 q=&b[0][0];
 printf("Enter elements OF MATRIX A:\n");
 for(i=0;i<3;i++){
    for(j=0;j<3;j++){
        scanf("%d",(p+(i*3)+j));  	
    }
 }
 printf("\n");
printf("Elemets of Matrix A:\n");
 for(i=0;i<3;i++)
 { 
   for(j=0;j<3;j++)
   {
    printf("%d ",*(p+i*3+j)); 
   }	
   printf("\n"); 
 }
 printf("\n");
 printf("Enter elements of matrix B:\n");

 for(i=0;i<3;i++)
 {
  for(j=0;j<3;j++)
  {
   scanf("%d",(q+(i*3)+j));
  }
 }
 printf("\n");
 printf("Elemets of matrix B:\n");	
 for(i=0;i<3;i++)
 { 
   for(j=0;j<3;j++){
    printf("%d ",*(q+(i*3)+j));  
   }	
   printf("\n"); 
 }
 for(i=0;i<3;i++)
 {
  for(j=0;j<3;j++)
  {
   c[i][j]=*(p+i*3+j)+*(q+i*3+j);
  }   
   printf("\n");
 }
printf("Sum of both Matrix:\n");
 for(i=0;i<3;i++)
 { 
    for(j=0;j<3;j++){
        printf("%d ",c[i][j]);
        }  
    printf("\n"); 
 }
 printf("\n");
 printf("Matrix Multiplication:\n");
 for(i=0;i<3;i++)
 {
    sum=0;
  for(j=0;j<3;j++)
  {
    for(k=0;k<3;k++)
    {    
        sum+=a[i][k]*b[k][j];
    }
    d[i][j]=sum;    

  }
 }
 for(i=0;i<3;i++)
        {
            for(j=0;j<3;j++)
            {
                printf("%d \t",d[i][j]);
            }
            printf("\n");
        }

 return 0;
}


