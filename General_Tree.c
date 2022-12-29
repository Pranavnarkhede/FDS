#include<stdio.h>
#include<stdlib.h>


struct abc
{
    char data;
    struct abc*left,*right;
};
struct abc*create(char key)
{
    struct abc *new;
    new=(struct abc*)malloc(sizeof(struct abc));
    new->data=key;
    new->left=NULL;
    new->right=NULL;
    
    return new;
}
struct abc *insert(struct abc*root)
{
    char key;
    printf("Enter Element to be inserted:");
    scanf(" %c",&key);
    root=create(key);

    if(key=='*')
    {
        return NULL;
    }

    printf("\nEnter data in left of %c\n",key);
    root->left=insert(root->left);
    printf("\nEnter data in right %c ",key);
    root->right=insert(root->right);

    return root;

}
void inorder(struct abc* root)
{
   if(root==NULL)
    {
        return;
    }
	inorder(root->left);
	printf("%c ",root->data);
	inorder(root->right);
}

void main()
{
    struct abc *root=NULL;
    int ch,y;
    do
    {
    printf("\n1.Insert");
    printf("\n2.Display");
    printf("\nEnter your choice:");
    scanf("%d",&ch);

    switch(ch)
    {
        case 1:root=insert(root);
               break;
        case 2:inorder(root);
            break;
    }
    printf("\nDo you want to continue:");
    scanf("%d",&y);
     } while(y==1);
}
