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
void inserts(struct abc* head)
{
    struct abc*new;
    new=(struct abc*)malloc(sizeof(struct abc));
    printf("enter name and PRN :\n");
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
    printf("enter name and PRN :\n");
    scanf(" %s",head->name);
    scanf("%d",&head->prn);
    head->next=NULL;
    head->prev=NULL;
    inserts(head);
    printf("\n");
    int ch,y;
    do{
        printf("\n 1.Insert Member\n2.Delete Member\n3.Delete Secretary\n4.Delete President\n5.Count members\n6.display\n7.reverse");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:insertM(head);
                   break;
            case 2:deleteM(head);
                   break;
            case 3:deleteS(head);
                   break;
            case 4:deleteP(head);
                   break;
            case 5:count(head);
                   break;
            case 6:reverse(head);
                   break;
            case 7:display(head);
                   break;
            default:
                   break;
        }
    }while(ch>0);
   
}
