#include <stdio.h>
#include <stdlib.h>
struct node
{
	int data;
	struct node* next;
};
struct node *front = NULL;
struct node *rear = NULL;

void enqueue(int d)
{
	struct node* new;
	new = (struct node*)malloc(sizeof(struct node));
	new->data = d;
	new->next = NULL;
	if((front == NULL)&&(rear == NULL)){
		front = rear = new;
	}
	else{
		rear->next = new;
		rear = new;
	}
	
}
void display()
{
	struct node* temp;
	if((front == NULL)&&(rear == NULL)){
		printf("\nQueue is Empty");
	}
	else{
		temp = front;
		while(temp){
			printf("\n%d",temp->data);
			temp = temp->next;
		}
	}
}
int dequeue()
{
	struct node *temp;
    int element;
	temp = front;
	if((front == NULL)&&(rear == NULL)){
		printf("\nQueue is Empty");
	}
	else{
        element=front->data;
        front = front->next;
		free(temp);
	}
    return element;
}
int main()
{
	int ch,n,i=0,num,y;
	printf("Enter Your Choice:-");

	do
    {
    printf("\n1.Insert");
        printf("\n1.Delete");
        printf("\n2.Display");
        printf("\n3.Enter your choice:");
        scanf("%d",&ch);

	switch(ch){
		case 1:printf("\nEnter the no. of elements: ");
				scanf("%d",&n);
				printf("\nEnter your data\n");
				while(i<n){
					scanf("%d",&num);
					enqueue(num);
					i++;
				}
				break;
		case 2:printf("Element deleted==>%d",dequeue());
				break;
		case 3:display();
				break;
			default:
				printf("\nIncorrect Choice");
			
		}
        printf("\ndo you want to continue:");
        scanf("%d",&y);
    }while(y==1);

}
