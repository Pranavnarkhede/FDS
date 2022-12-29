#include <stdio.h>
#define max 5

void enqueue(int);
void dequeue();
void display();

int q[max], front = -1, rear = -1;

int main() {
    int ch,y,data;
    do{
        printf("\n1.Insert");
        printf("\n2.Delete");
        printf("\n3.Display");
        printf("\nEnter your choice:");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:printf("Enter value to be inserted:");
                   scanf("%d",&data);
                  enqueue(data);
                break;
            case 2:dequeue();
                break;
            case 3:display();
                break;
        }
         printf("Do you want to continue:");
  scanf("%d",&y);
  }while(y==1);
  
   return 0;
}

void enqueue(int value) {
  if (rear == max - 1)
    printf("\nQueue is Full");
  else {
    if (front == -1)
      front = 0;
    rear++;
    q[rear] = value;
    printf("\nInserted -> %d", value);
  }
}

void dequeue() {
  if (front == -1)
    printf("\nQueue is Empty");
  else {
    printf("\nDeleted : %d", q[front]);
    front++;
    if (front > rear)
      front = rear = -1;
  }
}

void display() {
  if (rear == -1)
    printf("\nQueue is Empty");
  else {
    printf("\nQueue elements are:\n");
    for (int i = front; i <= rear; i++)
      printf("%d  ", q[i]);
  }
}
