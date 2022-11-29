#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<limits.h>
#include<ctype.h>

struct stack
{
    char data;
    struct stack *next;
};

struct stack * top=NULL;
int s[20];
int top1=-1;

void push(char element)
{
    struct stack *new;
    new=(struct stack *)malloc(sizeof(struct stack));
    new->data=element;
    new->next=NULL;
    if(top==NULL)
    {
        top=new;
    }
    else{
       new->next=top;
       top=new;
    }
}
char pop()
{
    char element; 
    struct stack *temp;
    if(top==NULL)
    {
        printf("stack is empty");
    }
    else if(top->next=NULL)
    {
        temp=top;
        element=top->data;
        top=NULL;
        free(temp);
    }
    else
    {
        temp=top;
        element=top->data;
        top=top->next;
        free(temp);
    }
    return element;
}
int precedence(char c)
{
        if(c=='^')
        {
            return 3;
        }
        else if(c=='*' || c=='/')
        {
            return 2;
        }
        else
            {
                return 1;
            }
    
    
}  
void push1(int n3)
{
top1=top1+1;
s[top1]=n3;
}
int pop1()
{
int num=s[top1];
top1--;
return num;
}
void evaluate(char postfix[20])
{
  int i=0;
  int result,n1,n2,n3;
  while(postfix[i]!='\0')
  {
    if(isdigit(postfix[i]))
     {
    n3=postfix[i]-48;
   push1(n3);
    }
else
{
n1=pop();
n2=pop1();
  switch(postfix[i])
{
case '^':result=n2^n1;
         push(result);
         break;
case '*':result=n2*n1;
         push(result);
         break;
case '/':result=n2/n1;
         push(result);
         break;
case '+':result=n2+n1;
         push(result);
         break;
case '-':result=n2-n1;
         push(result);
         break;
  }
  }
}
i++;
}
prinf("Evaluation of %s is %d",postfix,pop1());
int main()
{
    char infix[20],postfix[20];
    printf("Enter Infix Expression:");
    scanf(" %s",infix);
    int i=0,j=0;
    while(infix[i]!='\0')
    {
        if(isalnum(infix[i]))
        {
            postfix[j]=infix[i];
            j++;
        }
        else
        {
            if(top==NULL)
            {
                push(infix[i]);
                
            }
            else
            {
while(precedence(infix[i])<=precedence(top->data) && top!=NULL)
                {
                    postfix[j]=pop();
                    j++;
                }
                push(infix[i]);

            }      
        }
    i++;
}    
while(top!=NULL)
    {
        postfix[j]=pop();
        j++;
    }
    postfix[j++]='\0';

printf("%s",postfix);

 evaluate(postfix);



    return 0;
}
