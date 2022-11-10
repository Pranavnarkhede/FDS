#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};
struct node* head;
  

void create()
{
        int n;
        printf("\nEnter the number of nodes: ");
        scanf("%d", &n);
            int d;
            struct node* new,*temp;
            temp=head;
           
         for (int i = 2; i <= n; i++) 
           {
            
            new= (struct node*)malloc(sizeof(struct node));
            printf("\nEnter value in %d node:\n",i);
            printf("Value=\n");
            scanf("%d",&d);
            new->next=NULL;
            new->data= d;
            temp->next = new;
             temp=temp->next;
            }
}
    

void display()
{
    struct node* temp;

        temp = head;
        while (temp != NULL)
         {

            printf("Data = %d\n", temp->data);
            temp = temp->next;
        }
}

  

void insertFront()
{
    int d;
    struct node* temp;
    temp = (struct node*)malloc(sizeof(struct node));
    printf("\nEnter data : ");
    scanf("%d", &d);
    temp->data = d;
  
    temp->next = head;
    head = temp;
}
  

void insertEnd()
{
    int d;
    struct node *new,*temp ;
    new = (struct node*)malloc(sizeof(struct node));    
  
   printf("\nEnter data : ");
    scanf("%d",&d);
    new->data = d;
    new->next=NULL;
    temp = head;
    while (temp !=NULL) {
        temp = temp->next;
    }
    temp->next = new;
}
  

void insertIntermediate()
{
    struct node *temp, *new;
    int pos, d, i = 1;
    new=(struct node*)malloc(sizeof(struct node));
 
    printf("\nEnter position:");
    scanf("%d", &pos);
    temp = head;
    new->data = d;
    while (i < pos - 1) {
        temp = temp->next;
        i++;
    }
    new->next = temp->next;
    temp->next= new;
}

void deleteFirst()
{
    struct node* temp;
    if (head == NULL)
        printf("\nList is empty\n");
    else {
        temp = head;
        head= head->next;
        free(temp);
    }
}
  
void deleteEnd()
{
    struct node *temp, *prev;
    if (head == NULL)
        printf("\nList is Empty\n");
    else {
        temp = head;
        while (temp->next!= 0) {
            prev = temp;
            temp = temp->next;
        }
        free(temp);
        prev->next= NULL;
    }
}

void deleteIntermediate()
{
    struct node *temp, *p;
    int i = 1, pos;
    printf("Enter position:");
    scanf("%d",&pos);
    while(i!=pos)
    {
        p=temp;
        temp=temp->next;
        i++;
    }
  p->next=temp->next;
  free(temp);
    
       
    }

  
 

void sort()
{
    struct node* p = head;
    struct node* q;
    int temp;
  
      while (p != NULL) {
         q= p->next;
        while (q != NULL) {
             if (p->data>q->data) 
             {
              temp = p->data;
              p->data= q->data;
              q->data = temp;
            }
                q = q->next;
            }
            p = p->next;
        }
}


void reverse()
{
    struct node *t1, *t2, *temp;

  

    while (head!= NULL) {
            t2 = head->next;
            head->next = t1;
            t1 = head;
            head= t2;
        }
        head= t1;
       temp = head;
       printf("Reversed linked "
               "list is : ");
  
        while (temp != NULL) {
            printf("%d ", temp->data);
            temp = temp->next;
        }
    }


int main()
{
    int d;
    head=(struct node*)malloc(sizeof(struct node));
    printf("enter data in head node:");
    scanf("%d",&d);
    head->data=d;
    head->next=NULL;
    create();

    int choice;
    while (1) {
         printf("\nEnter Choice :\n");
        scanf("%d", &choice);
  
        switch (choice) {
        case 1:
            display();
            break;
        case 2:
            insertFront();
            break;
        case 3:
            insertEnd();
            break;
        case 4:
            insertIntermediate();
            break;
        case 5:
            deleteFirst();
            break;
        case 6:
            deleteEnd();
            break;
        case 7:
            deleteIntermediate();
            break;
       case 8:
            sort();
            break;
        case 9:
            reverse();
            break;
        case 10:
            exit(1);
            break;
        default:
            printf("Incorrect Choice\n");
        }
    }
    return 0;
}
