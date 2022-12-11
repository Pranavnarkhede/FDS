#include<stdio.h>
#include<stdlib.h>

struct abc
{
    int data;
    struct abc *left,*right;
};
struct abc * createNode(int key)
{
    struct abc*new;
    new=(struct abc*)malloc(sizeof(struct abc));
    new->data=key;
    new->right=NULL;
    new->left=NULL;

    return new;

    
}
int searchBST(struct abc* node,int key)
{
  if(node==NULL)
    return -1;

 if(key==node->data)
    return key;

else if(key<node->data)
      searchBST(node->left,key);

else searchBST(node->right,key);

 }
void inorder(struct abc*root)
{
   if(root!= NULL)
    {
    inorder(root->left);
    printf("%d ",root->data);
    inorder(root->right);
    }

}
void preorder(struct abc*root)
{
    if(root != NULL)
    {
     printf("%d ", root->data);
     preorder(root->left);
     preorder(root->right);
    }
}
void postorder(struct abc*root)
{
    if(root!= NULL)
    {
     postorder(root->left);
     postorder(root->right);
     printf("%d ", root->data);
}
}
struct abc* insertBST(struct abc *rootNode,int key)
{
    if(rootNode==NULL)
    {
       return  createNode(key);
    }
    else if(key<rootNode->data)
    {
        rootNode->left =insertBST(rootNode->left,key);
    }
    else
    {
        rootNode->right=insertBST(rootNode->right,key);
    }

    return rootNode; 

}
int main()
{
    struct abc *root=NULL;
    int ch,y,key;
    do{
    printf("\n1.Insertion in BST");
    printf("\n2.Searching in BST");;
    printf("\n3.Traversal in BST(Inorder)");
    printf("\n4.Traversal in BST(preorder)");
    printf("\n5.Traversal in BST(postorder)");
    printf("\nEnter your choice;");
    scanf("%d",&ch);

    switch(ch)
    {
      case 1:printf("Enter element:");
             scanf("%d",&key);
             root=insertBST(root,key);
             break;
      case 2:printf("Enter data to be searched:");
             scanf("%d",&key);
             key=searchBST(root,key);
             if(key==-1)
             printf("Element not found");

             else printf("Element %d found",key);
            break;
      case 3:printf("The elements in Tree:");
            inorder(root);
            break;
       case 4:printf("The elements in Tree:");
            preorder(root);
            break;
       case 5:printf("The elements in Tree:");
            postorder(root);
            break;
        
    }
    printf("\nDo you want to continue:");
    scanf("%d",&y);
    }while(y==1);

    return 0;
    

}
