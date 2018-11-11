#include<stdio.h>
#include<ctype.h>
#define stack_size 25
int elem,i;
char str[25],res[25];
char stack[25];
int top;

void push(char ele)
{
   if(top==stack_size-1)
       printf("\n Overflow.\n");
   else
   {
      top++;
     stack[top]=ele;
    }
}

char pop()
{
  if(top==-1)
{
  printf("\nUnderflow.\n");
  return (-1);
 }
  else
   return (stack[top--]);
}

void convert()
{
  int i=0,j=0;
  for(i=0;str[i]!='\0';i++)
 {
    if(isalpha(str[i]) ||  isdigit(str[i]))
	res[j++]=str[i];
    else
        switch(str[i])
        {
	case '(': push(str[i]); break;
	case '$': while(stack[top]=='$')
		        res[j++]=pop();
		  push(str[i]);
		  break;
	case '/':
	case '*':while(stack[top]=='$' || stack[top]=='/'||stack[top]=='*')
					res[j++]=pop();
		  push(str[i]);
		  break;
	case '+':
	case '-':while(stack[top]=='$'||stack[top]=='*'||stack[top]=='/'||stack[top]=='+'
						||stack[top]=='-')
			res[j++]=pop();
		  push(str[i]);
		  break;
	case ')': while(stack[top]!='(')
			res[j++]=pop();
		  pop();
		  break;
	}
       }
       while(top>-1)
		res[j++]=pop();
        res[j]='\0';
       printf("Postfix Expression is: %s ",res);
}

main()
{              	top=-1;
	printf("Enter a valid infix expression: ");
	scanf("%s",str);
	convert();    
 }
