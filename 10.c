#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct node
{
	char name[10];
	struct node *link;
};
void main()
{
	char ch,name[10];
	struct node *cur;
	int n,i;
	cur=NULL;
	printf("Enter the number of the players\n");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		printf("Enter the name of the player \n",i+1);
		scanf("%s",name);
		cur=add_player(name,cur);
	}
	while(ch=getc(stdin)!='q')
	{
		printf("Press 'n' for next move and 'q' to exit the game \n");
		printf("Choice: \n");
		scanf("%c",&ch);
		cur=next_turn(cur);
		whose_turn(cur);
	}
}
add_player (char name[],struct node *cur )
{
	struct node *new;
	new=(struct node *)malloc(sizeof(struct node));
	strcpy(new->name,name);
	new->link=new;
	if(cur==NULL)
		return new;
	new->link=cur->link;
	cur->link=new;
	return new;
}
next_turn (struct node *cur)
{
	cur =cur->link;
	return cur;
}
void whose_turn(struct node *cur)
{
	printf("%s must play now \n",cur->name);
}

		
