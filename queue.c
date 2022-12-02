#include<stdio.h>
#define max 20

int front=-1,rear=-1;
int s[max];
void enqueue()
{
    int a;
    printf("enter element to be pushed");
    scanf("%d",&a);
    if((front ==0 && rear==max-1) || (rear+1)%max==front)
    {
        printf("overflow");
    }
    else
    {
        if(rear==max-1)
    {
        rear=(rear+1)%max;
        s[rear]=a;
    }
    else
    {
        rear=(rear+1)%max;
        s[rear]=a;
    }
    }
  

}
int dequeue()
{
    int element;
  if(front==-1)
  {
    printf("oveflow");
  }
  else{
    element=s[front];
    if(front==rear)
    {
     front=rear=-1;
    }
  else{
    front=(front+1)%max;
  }


}
}
void Display()
{
    int i=0;
  if(front=-1)
  {
    printf("queue is empty");
  }
  else
  {
    {
        printf("%d",s[i]);
        i++;
    }
  }
}

int main()
{
    int ch,y;
    do{
        printf("\n1.Insert");
        printf("\n1.Delete");
        printf("\n1.Display");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:enqueue();
                break;
            case 2:printf("Element deleted is:%d",dequeue());
                break;
            case 3:Display();
                break;    

        }
        printf("do you want to continue:");
        scanf("%d",&y);
    }while(y==1);
} 
 
