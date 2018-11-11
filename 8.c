#include<stdio.h>
#include<stdlib.h>
void insertbeg();
void insertend();
void insertpos();
void display();
struct node
{
	int id;
	char name[10];
	int sem;
	struct node *next;
};
struct node *start=NULL;
main()
{
	int ch;
	while(1)
	{
		printf("\n1.Insert in the beginning\n2.Insert in the end\n3.Insert in the position\n4.Display\n5.Exit\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1: insertbeg();	break;
			case 2: insertend();	break;
			case 3: insertpos();	break;
			case 4: display();	break;
			case 5: exit(0);	break;
		}
	}
}
void insertbeg()
{
	struct node *temp;
	temp=(struct node *)malloc(sizeof(struct node));
	if(temp==NULL)
	{
		printf("Memory not allocated\n");
		return;
	}
	temp->next=NULL;
	printf("Enter the ID,Name and sem\n");
	scanf("%d%s%d",&temp->id,temp->name,&temp->sem);
	if(start==NULL)
		start=temp;
	else
	{
		temp->next=start;
		start=temp;
	}
}
void insertend()
{
	struct node *temp,*ptr;
        temp=(struct node *)malloc(sizeof(struct node));
        if(temp==NULL)
        {
                printf("Memory not allocated\n");
                return;
        }
        temp->next=NULL;
        printf("Enter the ID,Name and sem\n");
        scanf("%d%s%d",&temp->id,temp->name,&temp->sem);
        if(start==NULL)
                start=temp;
	else
	{
		ptr=start;
		while(ptr->next!=NULL)
			ptr=ptr->next;
		ptr->next=temp;
	}
}
void insertpos()
{
        struct node *temp,*ptr;
	int i,pos;
        temp=(struct node *)malloc(sizeof(struct node)); 
        if(temp==NULL)
        {
                printf("Memory not allocated\n");
                return;
        }
        temp->next=NULL;
	printf("Enter the position\n");
	scanf("%d",&pos);
        printf("Enter the ID,Name and sem\n");      
        scanf("%d%s%d",&temp->id,temp->name,&temp->sem);
	if(pos==1)
	{
		temp->next=start;
		start=temp;
	}
	else
	{
		for(i=0,ptr=start;i<pos-2;i++)
		{
			ptr=ptr->next;
			if(ptr==NULL)
			{
				printf("Position not found\n");
				return;
			}
		}
		temp->next=ptr->next;
		ptr->next=temp;
	}
}
void display()
{
	struct node *ptr;
	if(start==NULL)
	{
		printf("List is empty\n");
		return;
	}
	else
	{
		ptr=start;
		printf("The elements on the list are\n");
		while(ptr!=NULL)
		{
			printf("\nID: %d\tName: %s\tSemester: %d",ptr->id,ptr->name,ptr->sem);
			ptr=ptr->next;
		}
	}
}
