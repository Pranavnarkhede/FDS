#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node 
{
    int id;
    char name[100];
    struct node *next;
    struct node *prev;
} Node;

Node *head = NULL;

void insertStart() 
{
    Node new_node = (Node) malloc(sizeof(Node));

    printf("enter id : ");
    scanf("%d",&new_node->id);
    printf("enter name : ");
    scanf("%s",new_node->name);

    new_node->prev = NULL;
    new_node->next = head;

    if (head != NULL) 
    {
        head->prev = new_node;
    }

    head = new_node;
}

void insertAtPosition()
{
    int position;
    printf("enter position : ");
    scanf("%d",&position);
    Node new_node = (Node) malloc(sizeof(Node));
    printf("enter id : ");
    scanf("%d",&new_node->id);
    printf("enter name : ");
    scanf("%s",new_node->name);

    new_node->prev = NULL;
    new_node->next = NULL;

    if (head == NULL) 
    {
        head = new_node;
        return;
    }

    if (position == 0) 
    {
        new_node->next = head;
        head->prev = new_node;
        head = new_node;
        return;
    }

    Node *curr = head;
    int i = 0;
    while (curr != NULL) 
    {
        if (i == position) 
        {
            new_node->prev = curr->prev;
            new_node->next = curr;
            curr->prev->next = new_node;
            curr->prev = new_node;
            return;
        }
        curr = curr->next;
        i++;
    }

    curr->next = new_node;
    new_node->prev = curr;
}
void insertAtEnd()
{
    Node new_node = (Node) malloc(sizeof(Node));
    printf("enter id : ");
    scanf("%d",&new_node->id);
    printf("enter name : ");
    scanf("%s",new_node->name);
    
    new_node->prev = NULL;
    new_node->next = NULL;

    Node *curr = head;
    while (curr->next != NULL) 
    {
        curr = curr->next;
    }
    curr->next = new_node;
    new_node->prev = curr;
}

void deleteStart()
{
    if (head == NULL) 
    {
        return;
    }
    Node *temp = head;
    head = head->next;
    if (head != NULL) 
    {
        head->prev = NULL;
    }
    free(temp);
}

void deleteAtId() 
{
    int id;
    Node *curr = head;
    printf("enter id to be deleted : ");
    scanf("%d",&id);
    while (curr != NULL) 
    {
        if (curr->id == id) 
        {
            if (curr->prev != NULL) 
            {
                curr->prev->next = curr->next;
            } 
            else 
            {
                head = curr->next;
            }
            if (curr->next != NULL) 
            {
                curr->next->prev = curr->prev;
            }
            free(curr);
            break;
        }
        curr = curr->next;
    }
}

void deleteAtEnd()
{
    if (head == NULL) 
    {
        return;
    }
    if (head->next == NULL) 
    {
        free(head);
        head = NULL;
        return;
    }
    Node *curr = head;
    while (curr->next != NULL) 
    {
        curr = curr->next;
    }
    curr->prev->next = NULL;
    free(curr);
}

void print_forward() 
{
    Node *curr = head;
    while (curr != NULL) {
        printf("%d : %s\n", curr->id, curr->name);
        curr = curr->next;
    }
    printf("\n");
}

void print_backward() 
{
    Node *curr = head;
    while (curr != NULL) 
    {
        if (curr->next == NULL) 
        {
            break;
        }
        curr = curr->next;
    }

    while (curr != NULL) 
    {
        printf("%d : %s\n", curr->id, curr->name);
        curr = curr->prev;
    }
    printf("\n");
}

int main() 
{
    int ch;
    do
    {
        printf("1.insert at start\n2.insert at position\n3.insert at end\n4.delete start\n5.delete end\n6.delete a given id\n7.display forward\n8.display reverse\n0.exit\nenter choice : ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1 :
                insertStart();
                break;
            
            case 2 :
                insertAtPosition();
                break;

            case 3 :
                insertAtEnd();
                break;

            case 4 :
                deleteStart();
                break;

            case 5 :
                deleteAtEnd();
                break;

            case 6 :
                deleteAtId();
                break;

            case 7 :
                print_forward();
                break;

            case 8 :
                print_backward();
                break;

            case 0 :
                return 0;
                break;

            default:
                printf("enter valid choice\n");
        }
    }while(ch!=0);
    return 0;
}
