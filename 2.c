#define stack_size 5
#include<stdio.h>
struct stack
{
	int item[15];
	int top;
}s;
main()
{
  int i;
	s.top=-1;
	while(1)
	{
		printf("\n\n1.PUSH\n2.POP\n3.DISPLAY\n4.Exit");
		printf("\nEnter your Choice: ");
		scanf("%d",&i);

		switch(i)
		{
			case 1: push();
				break;
			case 2: pop();
				break;
			case 3: display();
				break;
			case 4: exit(0);
				break;
			default: printf("\nInvalid Input.");
		}}}

void push()
{
 int ele;
  printf("Enter the element to be pushed");
  scanf("%d",&ele);
	if(s.top==stack_size-1)
		printf("\n Overflow.\n");
	else
		{
		s.top++;
		s.item[s.top]=ele;
		}
}
void pop()
{
 int k;
	if(s.top==-1)
		{
		printf("\nUnderflow.\n");
		}
	else
               {
                k=s.item[s.top];
		printf("\nThe popped value is %d.",k);
                s.top=s.top-1;
                } 
}
void display()
{
 int i;
	if(s.top==-1)
		printf("\nEmpty Stack.\n");
	else
		{
		printf("\n\n");
		for(i=0;i<=s.top; i++)
			printf("%d\t",s.item[i]);
		}}
