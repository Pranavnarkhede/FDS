#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>
#include<math.h>

struct stack
{
    char data;
    struct stack *next;
};

void push(char);
char pop();
int precedence(char);
void evaluate(char []);
void push1(int);
int pop1();

struct stack *top = NULL;
int s[20], top1= -1;

int main()
{
    char infix[20], postfix[20];
    int i = 0, j = 0;

    printf("Enter Infix Expression: ");
    scanf(" %s",infix);

    while(infix[i]!='\0')
    {
        if(isalnum(infix[i]))
            postfix[j++] = infix[i];
        else
        {
            if(top == NULL)
                push(infix[i]);

            else
            {
             while( top != NULL && (precedence(top->data) >= precedence(infix[i])) ) 
                postfix[j++]=pop();
                push(infix[i]);
            }
        }

        i++;
    }

    while(top != NULL)
        postfix[j++] = pop();

    postfix[j] = '\0';
    puts(postfix);
    evaluate(postfix);
    getchar();

    return 0;
}

int precedence(char x)
{
    switch(x)
    {
    case '^': return 3;
              break;
    case '*':return 2;
             break;
    case '/': return 2;
             break;
    case '+':return 1;
             break;
    case '-': return 1;
            break;
    }
}

void push(char a)
{
    struct stack* new;
    new = ( struct stack *) malloc (sizeof(struct stack));
    new->data = a;
    new->next = NULL;
    if(top == NULL)
    {
        top = new ;
    }
    else
    {
        new->next = top ;
        top = new;
    }
}
char pop()
{
    struct stack *temp;
    char element;

    if(top == NULL)
        printf("Stack is Empty");
    
    else
    {
        temp = top;
        element = top->data;
        top = top->next;
        free(temp);
    }

    return element;
}
void push1(int num)
{
    top1++;
    s[top1] = num;
}
int pop1()
{
    int num;
    num = s[top1];
    top1--;
    return num;
}
void evaluate(char postfix[])
{
    int i = 0 ,num ,n1,n2,n3;
    while(postfix[i]!='\0')
    {
        if(isdigit(postfix[i]))
        {
            num = postfix[i] - 48;
            push1(num);
        }
        else
        {
            n1 = pop1();
            n2 = pop1();
            switch(postfix[i])
            {
                case '^' :
                    n3 = pow(n2,n1);
                    push1(n3);
                    break;
            
                case '*' :
                    n3 = n2*n1;
                    push1(n3);
                    break;
            
                case '/' :
                    n3 = n2/n1;
                    push1(n3);
                    break;
            
                case '+' :
                    n3 = n2+n1;
                    push1(n3);
                    break;
            
                case '-' :
                    n3 = n2-n1;
                    push1(n3);
                    break;
            }
        }
        i++;
    }
     printf("Evaluation==>%d",pop1());
}
