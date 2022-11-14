#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct abc
{
   char name[10];
   struct abc *next;
};
struct abc *top=NULL;

void insert(char[]);
void delete();
void display();

void main()
{
   int ch;
   char value[10];
   do{
      printf("1.insert\n2.delete\n3.display\n");
      printf("Enter your choice: ");
      scanf("%d",&ch);
      switch(ch)
      {
	 case 1: printf("Enter the value to be insert: ");
		 scanf("%s",value);
		 insert(value);
		 break;
	 case 2: delete(); 
             break;
     case 3:display();
            break;
	    }
    }while(ch>0);
}

void insert(char value[])
{
   struct abc *new;
   new = (struct abc*)malloc(sizeof(struct abc));
   strcpy(new->name,value);
   if(top == NULL)
      new->next = NULL;
   else
      new->next = top;
        top = new;
  
}
void delete()
{
   if(top == NULL)
      printf("empty");
   else{
      struct abc *temp;
      temp=top;
      printf("Element deleted= %s\n",temp->name);
      top=temp->next;
      free(temp);
   }
}
void display()
{
   if(top == NULL)
      printf("empty");
   else{
      struct abc *temp;
      temp=top;
      while(temp->next != NULL){
	 printf(" %s",temp->name);
	 temp = temp -> next;
      }
 }
}