#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct node
{
	char url[20];
	struct node *r;
	struct node *l;
};
void main()
{
	char url[20];
	int ch;
	struct node *cur;
	cur=NULL;
	while(1)
	{
		printf("1.Browse forward\n2.Browse backward\n3.Add URL\n4.Current URL\n5.Exit\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1: cur=browsef(cur);
				break;
			case 2: cur=browseb(cur);
				break;
			case 3: printf("Enter the new URL\n");
				scanf("%s",url);
				cur=add(url,cur);
				break;
			case 4: show(cur);
				break;
			case 5: exit(0);
				break;
		}
	}
}
add(char url[],struct node *cur)
{
	struct node *new;
	new=(struct node *)malloc(sizeof(struct node));
	strcpy(new->url,url);
	new->l=NULL;
	new->r=NULL;
	if(cur==NULL)
		return new;
	new->l=cur;
	cur->r=new;
	return new;
}
browsef(struct node *cur)
{
	if(cur==NULL)
	{
		printf("Nothing to show\n");
		return cur;
	}
	if(cur->r==NULL)
	{
		printf("Atmost page reached\n");
		return cur;
	}
	cur=cur->r;
	return cur;
}
browseb(struct node *cur)
{
	if(cur==NULL)
	{
		printf("NO browsing history\n");
		return cur;
	}
	if(cur->l==NULL)
	{
		printf("No records before this\n");
		return cur;
	}
	cur=cur->l;
	return cur;
}
void show(struct node *cur)
{
	if(cur==NULL)
	{
		printf("History clean\n");
		return ;
	}
	printf("You are viewing %s\n",cur->url);
}
