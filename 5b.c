#include<stdio.h>

   void hanoi(int n,char source,char destination,char temp);

   void main()
   {

       int n;
       printf("\nenter the no. of disks:\n");
       scanf("%d",&n);
       hanoi(n,'t','s','d');
   }
   void hanoi(int n,char source,char destination,char temp)

{


      if(n>0)
      {
          hanoi(n-1,source,temp,destination);
        printf(" \n movedisk %d from %c to %c",n,source,destination);
        hanoi(n-1,temp,destination,source);
      }
}
