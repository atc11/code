#include<stdio.h>
#include<stdlib.h>
struct node
{
	int info;
	struct node *lt;
	struct node *rt;
};
struct node *root=NULL;
void bst(int);
struct node *maketree(int);
void setleft(struct node *,int);
void setright(struct node *,int);
void inorder(struct node *);
void preorder(struct node *);
void postorder(struct node *);
void main()
{
	int ch,x;
	while(1)
	{
		printf("\n1.Make Tree\n2.Inorder\n3.Preorder\n4.Postorder\n5.Exit\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1: printf("Enter the element\n");
				scanf("%d",&x);
				bst(x);
				break;
			case 2: if(root==NULL)
				{
					printf("Tree doesnt exist\n");
					return;
				}
				else
				{
					printf("Inorder transversal is \n");
					inorder(root);
				}
				break;
			case 3: if(root==NULL)
				{
					printf("Tree doesnt exist\n");
					return;
				}
				else
				{
					printf("Preorder tranversal id \n");
					preorder(root);
				}
				break;
			case 4: if(root==NULL)
				{
					printf("Tree doesnt exist\n");
					return;
				}
				else
				{
					printf("Postorder transversal is \n");
					postorder(root);
				}
				break;
			case 5: exit(0);
				break;
		}
	}
}
void bst(int x)
{
	struct node *p,*q;
	if(root==NULL)
		root=maketree(x);
	else
	{
		p=q=root;
		while(q!=NULL)
		{
			p=q;
			if(p->info>x)
				q=p->lt;
			else
				q=p->rt;
		}
		if(p->info<=x)
			setright(p,x);
		else
			setleft(p,x);
	}
}
struct node *maketree(int x)
{
	struct node *p;
	p=(struct node *)malloc(sizeof(struct node));
	if(p==NULL)
	{
		printf("Memory not allocated \n");
		return;
	}
	p->info=x;
	p->lt=p->rt=NULL;
	return p;
}
void setleft(struct node *p,int x)
{
	if(p==NULL)
		printf("Insertion not possible\n");
	if(p->lt!=NULL)
		printf("Left node already exixts\n");
	p->lt=maketree(x);
}
void setright(struct node *p,int x)
{
	if(p==NULL)
		printf("Insertion not possible\n");
	if(p->rt!=NULL)
		printf("Right element already exists\n");
	p->rt=maketree(x);
}
void inorder(struct node *p)
{
	if(p!=NULL)
	{
		inorder(p->lt);
		printf("%d\t",p->info);
		inorder(p->rt);
	}
}
void preorder(struct node *p)
{
	if(p!=NULL)
	{
		printf("%d\t",p->info);
		preorder(p->lt);
		preorder(p->rt);
	}
}
void postorder(struct node *p)
{
	if(p!=NULL)
	{
		postorder(p->lt);
		postorder(p->rt);
		printf("%d\t",p->info);
	}
}
