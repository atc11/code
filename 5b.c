#include<stdio.h>
#include<conio.h>
#include<dos.h>
void hanoi(int n,char s,char d,char temp)
{
    if(n>0)
    {
        hanoi(n-1,s,temp,d);
        printf("\n move disk %d from %c to %c",n,s,d);
        hanoi(n-1,temp,d,s);
    }
}
void main()
{
    int n;
printf("enter the no of disks :");
scanf("%d",&n);
hanoi(n,'s','d','t');
}
