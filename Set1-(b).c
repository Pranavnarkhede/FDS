#include <stdio.h> 
#include <string.h> 

void reverse(char* p)
{
	int len=0,i;
	char *start,*end,temp;
    while(p[len]!='\0')
    {
        len++;
    }
    printf("Length is %d\n",len);
    
	start=p;
	end =p+len-1;	

	for (i= 0; i<(len/2); i++) 
    {
         temp = *end;
		*end = *start;
		*start = temp;
        
        start++; 
		end--;
	}
}

int main()
{	
	char p[20];
	printf("Enter the string to be reversed:");	
	gets(p);
	
	reverse(p);
	printf("Reversed String is %s",p);

	return 0;
}
