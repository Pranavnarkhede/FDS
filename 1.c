#include<stdio.h>
int main()
{
int a,b,choice;
int sum=0,diff=0,mul=0,div=0;

printf(" enter 1 for addition\n");
printf(" enter 2 for subtration\n");
printf(" enter 3 for multiplication\n");
printf(" enter 4 for division\n");
scanf("%d",&choice);
switch(choice)
{
case 1:
       printf("enter values:");
       scanf("%d %d",&a,&b);
       sum=a+b;
       printf("Sum=%d\n",sum);
       break;
case 2:printf("enter values:");
       scanf("%d %d",&a,&b);
       diff=a-b;
       printf("Diff=%d\n",diff);
       break;
case 3:printf("enter values:");
       scanf("%d %d",&a,&b);
       mul=a*b;
       printf("multiplication=%d\n",mul);
       break;
case 4:printf("enter values:");
       scanf("%d %d",&a,&b);
       div=a/b;
       printf("division=%d\n",div);
       break;
default:
printf("enter correct value");
}
return 0;
}
