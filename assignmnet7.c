#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct abc
{
    char name[10];
    int prn;
    struct abc *next;
    struct abc *prev;
};

struct abc *head;

void inserts()
{
    struct abc*new,*temp;
    temp=head;
    new=(struct abc*)malloc(sizeof(struct abc));
    printf("enter name and PRN(Secretary) :\n");
    scanf(" %s",new->name);
    scanf("%d",&new->prn);
    new->next=NULL;
    new->prev=NULL;
    new->prev=temp;
    temp->next=new;
}
void display(struct abc *head)
{
     struct abc * temp;
     temp=head;
        while (temp != NULL)
         {
            printf("Name = %s \t PRN=%d \n",temp->name,temp->prn);
            temp =temp->next;
        }
}
void insertM()
{
    struct abc * new,*temp;
    temp=head;
    new=(struct abc *)malloc(sizeof(struct abc));
    printf("Enter name:");
    scanf(" %s",new->name);
    printf("enter prn:");
    scanf("%d",&new->prn);
    new->next=NULL;
    new->prev=NULL;
    new->next=temp->next;
    temp->next=new;
    new->next->prev=new;
    new->prev=temp;
    
    
}
void deleteP()
{
    struct abc *temp;
    temp=head;
    free(head);
    head=temp->next;
    
    printf("\nThe President has been deleted..\n");
}
void deleteS()
{
    struct abc*temp1,*temp2;
    temp1=head;
    while(temp1->next!=NULL)
    {
        temp1=temp1->next;
    }
    temp2=temp1->prev;
    temp2->next=NULL;
    free(temp1);
}
void deleteM()
{
    struct abc*temp1,*temp2;
    int pr;
    printf("Enter pr of member to be deleted:");
    scanf("%d",&pr);
    temp1=head;
    while(temp1->prn!=pr)
    {
        temp1=temp1->next;
    }
    temp2=temp1->prev;
    temp2->next=temp1->next;
    temp1->next->prev=temp2;
    free(temp1);
    temp1=NULL;
    
    
}
int count()
{
       struct abc *temp;
       temp=head;
       int count=0;
       while(temp!=NULL)
       {
              temp=temp->next;
              count++;
       }
       return count;
}
struct abc * reverse(struct abc* node)
{
    struct abc*temp;
 
    if (node==NULL)
        return NULL;

    temp = node->next;
    node->next = node->prev;
    node->prev = temp;
 
    
    if (node->prev=NULL)
        return node;
 

    return reverse(node->prev);
}
void main()
{
    head=(struct abc*)malloc(sizeof(struct abc));
    printf("enter name and PRN(President):\n");
    scanf(" %s",head->name);
    scanf("%d",&head->prn);
    head->next=NULL;
    head->prev=NULL;

    inserts();
    printf("\n");
    int ch,y,n;
    do{
        printf("\n 1.Insert Member\n");
        printf("2.Delete member\n");
        printf("3.Delete President\n");
        printf("4.Delete Secretary\n");
        printf("5.Count Members\n");
        printf("6.Reverse\n");
        printf("7.Display\n");

        printf("Enter your choice:");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:printf("Enter no of members to be inserted:");
                   scanf("%d",&n);
                   for(int i=0;i<n;i++)
                   {
                   insertM(head);
                   }
                   break;
            case 2:deleteM(head);
                 break;
            case 3:deleteP(head);
                  printf("President node deleted.");
                   break;
            case 4:deleteS(head);
                   printf("Secretary node deleted.");
                   break;
            case 5:printf("Total members in group=%d\n",count(head));
                  break;
            case 6:head=reverse(head);
                    display(head);
                 break;
             case 7:display(head);
                    break;
             default:exit(1);
        }
    
    printf("Do you want to continue(0/1):");
    scanf("%d",&y);
     } while(y==1);   
}

