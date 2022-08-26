/* Write a C program to implement QUICK sort

Test Cases:
input = 7
20 2 90 1 50 78 40
output = 2 1 20 40 50 78 90
*/
//Start writing program from here

#include <stdio.h>
#include <stdlib.h>

void quicksort(int [],int ,int);

int main()
{
    int n,i;
    scanf("%d",&n);
    int *a = (int *)malloc(n *sizeof(int));
    for(i=0;i<n;i++)
    scanf("%d",&a[i]);
    quicksort(a,0,n-1);
    for(i=0;i<n;i++)
    printf("%d ",a[i]);
    
    
    return 0;
}

void quicksort(int a[],int left,int right)
{
    int i,j,povit,t;
    if(left<right)
    {
        povit=a[left];
        i=left;
        j=right;
        while(i<j)
        {	 	  	 		      	   	    	 	
            while(a[i]<=povit && i<=right)
            i++;
            while(a[j]>povit)
            j--;
            if(i<j)
            {
               t=a[i]; 
               a[i]=a[j];
               a[j]=t;
            }
        }
        t=a[left];
        a[left]=a[j];
        a[j]=t;
        quicksort(a,left,j-1);
        quicksort(a,j+1,right);
    }
}



