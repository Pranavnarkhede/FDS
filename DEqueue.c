#include <stdio.h>
#define max 5

void enqueuerear(int);
void dequeuefront();
void enqueuefront(int);
void dequeuerear();
void display();

int q[max], front = -1, rear = -1;

int main() {
    int ch,y,data;
    do{
        printf("\n1.Insert from rear ");
        printf("\n2.Delete from front ");
        printf("\n3.Insert from front ");
        printf("\n4.Delete from rear ");
        printf("\n5.Display");
        printf("\nEnter your choice:");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:printf("Enter value to be inserted:");
                   scanf("%d",&data);
                  enqueuerear(data);
                break;
            case 2:dequeuefront();
                break;
            case 3:printf("Enter value to be inserted:");
                   scanf("%d",&data);
                  enqueuefront(data);
                     break;
            case 4:dequeuerear();
                break;
            case 5:display();
                break;
        }
         printf("Do you want to continue:");
  scanf("%d",&y);
  }while(y==1);
  
   return 0;
}

void enqueuerear(int value) {
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

void dequeuefront() {
  if (front == -1)
    printf("\nQueue is Empty");
  else {
    printf("\nDeleted : %d", q[front]);
    front++;
    if (front > rear)
      front = rear = -1;
  }
}


void enqueuefront(int value) {
  if (front<=0)
  {
    printf("Not possible");
  }
  else {
    if(front==-1)
    {
        front=front+1;
        rear=rear+1;
    }
    else{
        front=front-1;
        q[front]=value;
    }
  }
}

void dequeuerear() {
  if (front == -1)
    printf("\nQueue is Empty");
  else {
    printf("\nDeleted : %d", q[front]);
    rear=rear-1;
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
 
