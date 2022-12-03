#include<stdio.h>
#define max 5

int front= -1,rear= -1;
int s[max];
void enqueue()
{
    int a;
    printf("\nenter element to be pushed==>");
    scanf("%d",&a);
    if((front == 0 && rear == (max-1)) || (rear+1)%max==front)
    {
        printf("overflow\n");
    }
    else
    {
      if (front == -1) 
    {
        front = rear = 0;
        s[rear] = a;
    }
    else if (rear == max-1 && front != 0)
    {
        rear =(rear+1)%max;
        s[rear] = a;
    }
   else
    {
        rear=(rear+1)%max;
        s[rear] = a;
    }
    
 }
}
int dequeue()
{
    int element;
  if(front==-1)
  {
    printf("overflow");
  }
  else
  {
      element=s[front];
      if(front == rear)
      {
     front=-1;
     rear=-1;
      }
       if(front==max-1){
    front=(front+1)%max;
      }
      else{
            front=(front+1)%max;
      }
  }
  return element; 
}
void display()
{
  int i=0;
  if(front==-1)
  {
    printf("\nqueue is empty");
  }
  else
  {
     printf("Elements in Queue:");
     for (i = front; i != rear; i = (i + 1) % max)
        {
            printf("%d ",s[i]);
        }
    printf("%d \n", s[i]);
    }
  
}

int main()
{
    int ch,y;
    do{
        printf("\n1.Insert");
        printf("\n1.Delete");
        printf("\n1.Display");
        printf("\nEnter your choice:");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:enqueue();
                break;
            case 2:printf("\nElement deleted is:%d",dequeue());
                break;
            case 3:display();
                break;    

        }
        printf("\ndo you want to continue:");
        scanf("%d",&y);
    }while(y==1);

    return 0;
} 
