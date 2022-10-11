#include<stdio.h>

int main()
{
	int a[3][3],b[3][3],c[3][3],d[3][3],i,j,k,min,max,s[2][2],ch,sum=0,flag=0;
	int *p,*q,*r;
	p=&a[0][0];
	q=&b[0][0];
	r=&d[0][0];
	
	printf("\n Enter the elements of A matrix:");
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
		scanf("%d", &a[i][j]);
		}
	}
	printf("\n Enter the elements of B matrix:");
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
		scanf("%d", &b[i][j]);
		}
	}
	do
	{
		printf("\n1.Addition\n2.Multiplication\n3.Saddle point");
		printf("\n Enter your choice=");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
            for(i=0;i<3;i++)
		{
			for(j=0;j<3;j++)
			{
				  c[i][j]= *(p+(i*3)+j)+*(q+(i*3)+j);	
			}
			
		}
		printf("\n sum of matrix=\n");
		for(i=0;i<3;i++)
		{
			for(j=0;j<3;j++)
			{	
			printf("%d	",c[i][j]);
			}
			printf("\n");
		}
		

            
				break;
			case 2:

             for(i=0;i<3;i++)
		{
            
			for(j=0;j<3;j++)
			{
				for(k=0;k<3;k++)
				{
					sum+=*(p+(i*3)+k)*(*(q+(k*3)+j));
				}
                *(r+(i*3)+j)=sum;
                sum=0;

			}
		}
	printf("\n multiplication of matrix=\n");
		for(i=0;i<3;i++)
		{
			for(j=0;j<3;j++)
			{	
			printf("%d	",*(r+(i*3)+j));
			}
			printf("\n");
		}
	


				break;
			case 3:
            for(i=0;i<3;i++)
   {
       min=*(p+(i*3)+0);
       for(j=0;j<3;j++)
       {
           if(min>=*(p+(i*3)+j))
           {
               min=*(p+(i*3)+j);
               s[0][0]=i;
               s[0][1]=j;
           }
       }
       j=s[0][1];
       max=*(p+(0*3)+j);
       for(k=0;k<3;k++)
       {
           if(max<=*(p+(k*3)+j))
           {
               max=*(p+(k*3)+j);
               s[1][0]=k;
               s[1][1]=j;
           }
       }
       if(min==max)
       {
           if(s[0][0]==s[1][0] && s[0][1]==s[1][1])
           {
               printf("Saddle point(%d,%d)=%d",s[0][0],s[0][1],max);
               flag=1;
           }
       }

   } 
   if(flag=0)
   {
    printf("no saddle point");
   }
				break;
			
			default:printf("\n Invalid choice");
		}
	}while(ch!=0);
return 0;
}
/*
int addmat(int *p,int *q,int *r)
{
	int i,j;
	
		for(i=0;i<3;i++)
		{
			for(j=0;j<3;j++)
			{
				  *(r+(i*3)+j)= *(p+(i*3)+j)+*(q+(i*3)+j);	
			}
			
		}
		printf("\n sum of matrix=\n");
		for(i=0;i<3;i++)
		{
			for(j=0;j<3;j++)
			{	
			printf("%d	",*(r+(i*3)+j));
			}
			printf("\n");
		}
		
}
int mul(int *p,int *q,int *r)
{
	int i,j,k;
	 
     for(i=0;i<3;i++)
		{
            *(r+(i*3)+j)=0;
			for(j=0;j<3;j++)
			{
				for(k=0;k<3;k++)
				{
					*(r+(i*3)+j)=*(r+(i*3)+j)+*(p+(i*3)+k)*(*(q+(k*3)+j));
				}
			}
		}
	printf("\n multiplication of matrix=\n");
		for(i=0;i<3;i++)
		{
			for(j=0;j<3;j++)
			{	
			printf("%d	",*(r+(i*3)+j));
			}
			printf("\n");
		}
	
}
/*int transpose(int *p,int *q)
{
	int i=0,j=0;
	

		for(i=0;i<3;i++)
		{
			for(j=0;j<3;j++)
			{
				*(q+(i*3)+j)=*(p+(j*3)+i);
				
			}
			
		}
		printf("\n Transpose of matrix=\n");
		for(i=0;i<3;i++)
		{
			for(j=0;j<3;j++)
			{	
			printf("%d	",*(q+(i*3)+j));
			}
			printf("\n");
		}
}

*/
