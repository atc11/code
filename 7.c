#include<stdio.h>
#include<stdlib.h>
#define qsize 10
void main()
{
	int ch,item,f,r,c,q[qsize];
	f=0;
	r=-1;
	c=0;
	while(1)
	{
		printf("\n1.Insert\n2.Delete\n3.Display\n4.Exit\n");
		printf("Enter your choice \n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1: printf("Enter the number\n");
				scanf("%d",&item);
				insert(item,&r,q,&c);
				break;
			case 2: item=delete(&f,q,&c);
				if(item==0)
					printf("Queue is empty\n");
				printf("The deleted item is %d",item);
				break;
			case 3: display(f,q,c);
				break;
			case 4: exit(0);	break;
		}
	}
}
void insert(int item,int *r,int *q,int *c)
{
	if(*c==qsize)
	{
		printf("Queue is full\n");
		return;
	}
	*r=(*r+1)%qsize;
	q[*r]=item;
	(*c)++;
}
int delete(int *f,int q[],int *c)
{
	int item;
	if(*c==0)
		return 0;
	item=q[*f];
	*f=(*f+1)%qsize;
	*c--;
	return item;
}
void display(int f,int q[],int c)
{
	int i;
	if(c==0)
	{
		printf("Queue is empty\n");
		return;
	}
	printf("The contents of the queue are \n");
	for(i=0;i<c;i++)
	{
		printf("%d\t",q[f]);
		f=(f+1)%qsize;
	}
}

