#include <stdio.h>

int main() 
{
   int min,max,i,j,k,a[3][3],s[2][2];
   printf("enter array elements:");
   for(i=0;i<3;i++)
   {
       for(j=0;j<3;j++)
       {
       scanf("%d",&a[i][j]);
       }
   }
   for(i=0;i<3;i++)
   {
       min=a[i][0];
       for(j=0;j<3;j++)
       {
           if(min>=a[i][j])
           {
               min=a[i][j];
               s[0][0]=i;
               s[0][1]=j;
           }
       }
       j=s[0][1];
       max=a[0][j];
       for(k=0;k<3;k++)
       {
           if(max<=a[k][j])
           {
               max=a[k][j];
               s[1][0]=k;
               s[1][1]=j;
           }
       }
       if(min==max)
       {
           if(s[0][0]==s[1][0] && s[0][1]==s[1][1])
           {
               printf("Saddle point(%d,%d)=%d",s[0][0],s[0][1],max);
           }
       }
   }

    return 0;
}
