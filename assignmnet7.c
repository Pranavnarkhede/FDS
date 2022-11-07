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
void insertM(struct abc*);
void deleteM(struct abc*);
void deleteP(struct abc*);
void deleteS(struct abc*);
void deleteM(struct abc*);





void inserts(struct abc* head)
{
    struct abc*new;
    new=(struct abc*)malloc(sizeof(struct abc));
    printf("enter name and PRN(Secretary) :\n");
    scanf(" %s",new->name);
    scanf("%d",&new->prn);
    new->next=NULL;
    new->prev=NULL;
    new->prev=head;
    head->next=new;
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

void main()
{
    struct abc*head;
    head=(struct abc*)malloc(sizeof(struct abc));
    printf("enter name and PRN(President):\n");
    scanf(" %s",head->name);
    scanf("%d",&head->prn);
    head->next=NULL;
    head->prev=NULL;
    inserts(head);
    printf("\n");
    int ch,y;
    do{
        printf("\n 1.Insert Member\n2.Delete Member\n3.Delete Secretary\n4.Delete President\n5.Count members\n6.display\n7.reverse\n");
        printf("Enter your choice:");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:insertM(head);
                   break;
            // case 2:deleteM(head);
                 break;
            case 3:deleteS(head);
                  printf("Secretary node deleted.");
                   break;
            case 4:deleteP(head);
                   printf("President node deleted.");
                   break;
            // case 5:count(head);
            //       break;
            // case 6:reverse(head);
            //       break;
             case 7:display(head);
                    break;
          }
    }while(ch>0);
   
}
void insertM(struct abc*head)
{
    struct abc * new,*temp;
    temp=head->next;
 new=(struct abc *)malloc(sizeof(struct abc));
    printf("Enter name:");
    scanf(" %s",new->name);
    printf("enter prn:");
    scanf("%d",&new->prn);
    new->next=NULL;
    new->prev=NULL;
    head->next=new;
    new->prev=head;
    temp->prev=new;
    new->next=temp;
    
}
void deleteP(struct abc* head)
{
    struct abc*temp;
    temp=head;
    head=head->next;
    free(temp);
}
void deleteS(struct abc*head)
{
    struct abc*temp;
    temp=head;
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    (temp->prev)->next=NULL;
    free(temp);
}
void deleteM(struct abc*head)
{
    struct abc*p,q;
    char ch[10];
    p=head;
    printf("Enter memeber name to be deleted:");
    scanf(" %s",ch);
    while(ch!=p->name)
    {
        q=p;
        p=p->next
    }
    q->next=p->next;
    (p->next)->prev=q;
    p->prev=NULL;
    P->next=NULL;
    
}

