#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>

struct stack
{
    char data;
    struct stack *next;
};
struct stack *top = NULL;
int s[20], top1= -1,top2=-1,t[20];
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
void push2(int num)
{
    top2++;
    t[top2] = num;
}
int pop2()
{
    int num;
    num = t[top2];
    top2--;
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

char* postfix_conversion(char infix[],char postfix[])
 {
    
    int i=0,j=0;
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
    
    return postfix;
 }

char *reverse(char exp[])
{
    char temp[20];
    int len = strlen(exp);  
   int j = 0;  
   for (int i = len - 1; i >= 0; i--)  
   {  
       temp[j] = exp[i];  
       j++;  
    }    
   temp[j++] = '\0'; 
   strcpy(exp,temp); 
    
} 
void prefix_conversion(char infix[],char prefix[])
{
    reverse(infix);
    postfix_conversion(infix,prefix);
    reverse(prefix);
    reverse(infix);

}
void evaluate_prefix(char prefix[])
{
    reverse(prefix);
    int i = 0 ,num ,n1,n2,n3;
    while(prefix[i]!='\0')
    {
        if(isdigit(prefix[i]))
        {
            num = prefix[i] - 48;
            push2(num);
        }
        else
        {
            n1 = pop2();
            n2 = pop2();
            switch(prefix[i])
            {
                case '^' :
                    n3 = pow(n1,n2);
                    push2(n3);
                    break;
            
                case '*' :
                    n3 = n1*n2;
                    push2(n3);
                    break;
            
                case '/' :
                    n3 = n1/n2;
                    push2(n3);
                    break;
            
                case '+' :
                    n3 = n1+n2;
                    push2(n3);
                    break;
            
                case '-' :
                    n3 = n1-n2;
                    push2(n3);
                    break;
            }
        }
        i++;
    }
     printf("Evaluation==>%d",pop2());
}


int main()
{
    char infix[20],prefix[20],postfix[20];
    int ch,y;
    
    printf("Enter Infix Expression: ");
    scanf(" %s",infix);
   do
   {
    printf("\n1.Infix to postfix conversion");
    printf("\n2.Postfix Evaluation");
    printf("\n3.Infix to prefix conversion");
    printf("\n4.Prefix Evaluation");
    printf("\nEnter your choice:");
    scanf("%d",&ch);

    switch(ch)
    {
        case 1:  postfix_conversion(infix,postfix);
                 printf("Postfix Expression-==>%d",postfix);
                break;
        case 2: evaluate(postfix);    
                 break;
        case 3: prefix_conversion(infix,prefix);
                printf("Prefix Expression==>%s",prefix);
                break;
        case 4:evaluate_prefix(prefix);
               break;   
    }
    printf("\nDo you want to continue:");
    scanf("%d",&y);

}while(y==1);
    getchar();

    return 0;
}

