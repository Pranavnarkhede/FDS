#include<stdio.h>

void add(void);
void mul(void);
void saddle(void);


int *p,*q;




int main()
{
    int ch;
    int i,j,k,a[3][3],b[3][3],c[3][3],d[3][3];
   
    printf("\nEnter the elements of  matrix A:");
    for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
        {
        
            scanf("%d",p+(i*3)+j);
        }
        printf("\n");
    }
   
    
    printf("\nEnter the elements of matrix B:");
    for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
        {
            scanf("%d",q+(i*3)+j);
        }
        printf("\n");
    }
    
    
    do
    {
    
    printf("\n\n1 - Matrix Addition\n2 - Matrix Multiplication\n3 - Saddle point of a Matrix\n4 - Exit");
    printf("\n\nEnter your choice :");
    scanf("%d",&ch);
    
    switch(ch)
    {
        case 1:
        add();
        break;
        
        case 2:
        mul();
        break;
        
        case 3:
        saddle();
        break;
    }
    }while(ch!=4); 
    
     return 0;
}

void add()
{
    int i,j,a[i][j],b[i][j],c[i][j];
     p=&a[0][0];
    q=&b[0][0];
   
    
    {
        for(i=0;i<3;i++)
        {
            for(j=0;j<3;j++)
            {
                c[i][j]=*(p+(i*3)+j)+*(q+(i*3)+j);
                
            }
        }
    }
   
    
    printf("\nThe addition of two matrices are - ");
    printf("\n");
    for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
        {
            printf("%d",c[i][j]);
            printf("\t");
        }
        printf("\n");
    }
}

void mul()
{
    int i,j,k,a[i][j],b[i][j],d[i][j];;
     p=&a[0][0];
 q=&b[0][0];
    
    for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
        {
            d[i][j]=0;
        }
    }
    
    
        for(i=0;i<3;i++)
        {
            for(j=0;j<3;j++)
            {
                for(k=0;k<3;k++)
                {
                    d[i][j]=d[i][j]+(*(p+(i*3)+k))*(*(q+(k*3)+j));
                }
            }
        }
    
   
    printf("\nThe multiplication of matrices are - ");
     printf("\n");
    for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
        {
            printf("%d",d[i][j]);
            printf("\t");
        }
        printf("\n");
    }
  
}

void saddle(void)
{
    int min,max,s[2][2],i,j,k,a[3][3],b[3][3];
    for(i=0;i<3;i++)
    {
        min=a[i][0];
        
        for(j=0;j<3;j++)
        {
            if(a[i][j]<=min)
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
            if(a[k][j]>=max)
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

}
       