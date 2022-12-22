#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<ctype.h>

struct tree {
    char data;
    struct tree *left, *right;
};

int top=-1;
struct tree *stack[20];
struct tree *root;

void push(struct tree* root)
 {
  top=top+1;
  stack[top] = root;
}
struct tree * pop()
{
return stack[top--];
}
void inorder(struct tree *root)
 {
    if(root==NULL)
    {
    return;
    }

  else
   {
    if(root!=NULL)
    {
        inorder(root->left);
        printf("%c",root->data);
        inorder(root->right);
        
    }
  }
}

void operand(char b)
{
   struct tree *root;
   root = (struct tree*) malloc(sizeof(struct tree));
   root->data=b;
   root->left = NULL;
   root->right=NULL;
    push(root);
}
void operators(char a) {
   struct tree *root;
   root = (struct tree*)malloc(sizeof(struct tree));
   root->data=a;
   root->right=pop();
   root->left=pop();
   push(root);

}

int main() {
int i=0;
char postfix[20];
printf("\nEnter postfix expression:");
scanf("%s",postfix);
while(postfix[i]!='\0')
 {
    if(isalnum(postfix[i]))
    {
        printf("\nOperand==>%c",postfix[i]);
        operand(postfix[i]);
    }
    else{
        operators(postfix[i]);
    }
    i++;
  }

  printf("\nInorder traversal of the tree==>\n");
   inorder(stack[top]);
return 0;
}
