#include<stdio.h>
#define MAX 50
  int binarysearch(int ar[],int low,int high,int key)
   {
        int mid;
        if(low>high)
            return -1;
            mid=(low+high)/2;
        if(ar[mid]==key)
            return mid;
        else
        {
            if(key>ar[mid])
                binarysearch(ar,mid+1,high,key);
            else
              binarysearch(ar,low,mid-1,key);
        }
   }
   int main()
   {
       int ar[MAX],i,n,ele,found;
       printf("enter the no. of elements\n");
       scanf("%d",&n);
       printf("enter the elements");

        for(i=0;i<n;i++)
            scanf("%d",&ar[i]);

            printf("enter the elements to be searched\n");
            scanf("%d",&ele);
            found=binarysearch(ar,0,n-1,ele);
             if(found==-1)
                printf("not found\n");
             else
                printf("found at %d\n",found+1);
   }
