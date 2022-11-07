#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct node {
    int data;
    char city[15];
    struct node* next;
};
struct node* head;


void sort();
void create();
void display();
  


int main()
{
    int d;
    char str[20];
    head=(struct node*)malloc(sizeof(struct node));
    printf("enter data in head node:\n");
    scanf("%d",&d);
    printf("Enter name of the city:\n");
    scanf(" %s",str);
    head->data=d;
    strcpy(head->city,str);
    head->next=NULL;
    create();
    printf("\n");
    sort();
    printf("Sorted Data:\n");
    display();
    return 0;
}
void create()
{
        int n;
        printf("Enter the number of nodes: \n");
        scanf("%d", &n);
            int d;
            char str[20];
            struct node* new,*temp;
            temp=head;
           
         for (int i = 1; i <= n; i++) 
           {
            
            new= (struct node*)malloc(sizeof(struct node));
            printf("Enter data:\n");
            scanf("%d", &d);
            printf("Enter name of the city:\n");
            scanf(" %s",new->city);
            new->data= d;
            new->next=NULL;
            temp->next= new;
            temp=temp->next;
            }
}

void sort()
{
    struct node* p = head;
    struct node* q;
    char r[20];
    int temp;
  
      while (p != NULL) {
         q= p->next;
        while (q != NULL) {
             if (p->data>q->data) 
             {
                temp=p->data;
                p->data=q->data;
                q->data=temp;
                strcpy(r,p->city);
                strcpy(p->city,q->city);
                strcpy(q->city,r);
            }
                q = q->next;
            }
            p = p->next;
        }
}


void display()
{
    struct node* temp;
          temp = head;
        while (temp != NULL)
         {

            printf(" %s ==>%d\n",temp->city,temp->data);
            temp = temp->next;
        }
}