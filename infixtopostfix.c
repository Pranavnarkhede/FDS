#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>

struct stack
{
    char data;
    struct stack *next;
};

struct stack * top=NULL;

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
void infix_to_postfix(char infix[20])
{
    char postfix[20];
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
    postfix[j]='\0';

printf("%s",postfix);


}    
int main()
{
    char infix[20],postfix[20];
    printf("Enter Infix Expression:");
    scanf(" %s",infix);
    infix_to_postfix(infix);

    return 0;
} 
