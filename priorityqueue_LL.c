
#include<stdio.h>
#include<stdlib.h>

struct node
{
        int priority;
        int data;
        struct node *next;
}*head=NULL;

void insert(int item, int item_pr);
int del();
void display();
int isEmpty();

int main()
{
        int ch,item,item_pr;
        while(1)
        {
                printf("\n1.Insert");
                printf("\n2.Delete");
                printf("\n3.Display");
                printf("\n4.Quit");
                printf("\nEnter your choice : ");
                scanf("%d", &ch);

                switch(ch)
                {
                 case 1:
                        printf("\nInput the item to be added in the queue : ");
                        scanf("%d",&item);
                        printf("\nEnter its priority : ");
                        scanf("%d",&item_pr);
                        insert(item, item_pr);
                        break;
                 case 2:
                        printf("\nDeleted item is %d\n",del());
                        break;
                 case 3:
                        display();
                        break;
                 case 4:
                        exit(1);
                 default :
                        printf("\nWrong choice\n");
                }
        }

        return 0;
}

void insert(int item,int item_pr)
{
        struct node *temp,*p;
        temp=(struct node *)malloc(sizeof(struct node));
        temp->data=item;
        temp->priority=item_pr;
        if( isEmpty() || item_pr < head->priority)
        {
                temp->next=head; 
                head=temp;
        }
        else
        {
                p = head;
                while( p->next!=NULL && p->next->priority<=item_pr )
                        p=p->next;
                temp->next=p->next;
                p->next=temp;
        }
}

int del()
{
        struct node *temp;
        int item;
        if( isEmpty() )
        {
                printf("\nQueue Underflow\n");
        }
        else
        {
                temp=head;
                item=temp->data;
                head=head->next;
                free(temp);
        }
        return item;
}

int isEmpty()
{
        if( head == NULL )
                return 1;
        else
                return 0;

}


void display()
{
        struct node *ptr;
        ptr=head;
        if( isEmpty() )
                printf("\nQueue is empty\n");
        else
        {       printf("\nQueue is :\n");
                while(ptr!=NULL)
                {
                        printf("%d   %d\n",ptr->priority,ptr->data);
                        ptr=ptr->next;
                }
        }
}
