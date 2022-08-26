/* Write a C program to implement Merge sort

Test Cases:
input = 8
21 51 6 10 3 45 5 78
output = 3 5 6 10 21 45 51 78 
*/
//Start writing program from here

#include <stdio.h>
#include <stdlib.h>

void simplesort(int [],int ,int ,int);
void mergesort(int [],int ,int);

int main()
{
    int n,i;
    scanf("%d",&n);
    int *a = (int *)malloc(n *sizeof(int));
    for(i=0;i<n;i++)
    scanf("%d",&a[i]);
    mergesort(a,0,n-1);
    for(i=0;i<n;i++)
    {
        if(a[i]!=a[i+1])
        printf("%d ",a[i]);
        else
        continue;
    }
    return 0;
}

void mergesort(int a[],int low,int high)
{
    int mid;
    if(low<high)
    {	 	  	 		      	   	    	 	
        mid = (low+high)/2;
        mergesort(a,low,mid);
        mergesort(a,mid+1,high);
        simplesort(a,low,mid,high);
    }
}

void simplesort(int a[],int low,int mid,int high)
{
    int i,j,k,b[100];
    i=low;
    k=low;
    j=mid+1;
    while(i<=mid && j<=high)
    {
        if(a[i]<a[j])
        b[k++]=a[i++];
        else
        b[k++]=a[j++];
    }
    while(i<=mid)
    b[k++]=a[i++];
    while(j<=high)
    b[k++]=a[j++];
    for(i=low;i<=high;i++)
    a[i]=b[i];
}	 	  	 		      	   	    	 	
