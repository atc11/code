#include<stdio.h>
#include<stdlib.h>
#define max 50
int q[max];
int f=-1;
int r=-1;
main()
{
	int ch;
	while(1)
	{
		printf("\n1.Insert\n2.Delete\n3.Display\n4.Exit\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1: insert();	break;
			case 2: delete();	break;
			case 3: display();	break;
			case 4: exit(0);	break;
		}
	}
}
insert()
{
	int item;
	if(r==max-1)
	{
		printf("Queue Overflow\n");
		return;
	}
	else
	{
		if(f==-1)
			f=0;
		printf("Enter the item\n");
		scanf("%d",&item);
		r=r+1;
		q[r]=item;
	}
}
delete()
{
	if(f==-1||f>r)
	{
		printf("Queue Underflow\n");
		return;
	}
	printf("The deleted item is %d\n",q[f]);
	f=f+1;
}
display()
{
	int i;
	if(f==-1)
	{
		printf("Queue underflow\n");
		return;
	}
	printf("The items of the queue are \n");
	for(i=f;i<=r;i++)
	{
		printf("%d\t",q[i]);
	}
}

