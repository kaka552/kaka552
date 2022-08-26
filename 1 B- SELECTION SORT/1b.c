/* Write a C program to implement Selection sort

Test Cases:
input = 5
2 5 6 10 3
output = 2 3 5 6 10
*/
//Start writing program from here

#include<stdio.h>
#include<stdlib.h>

void Selectionsort(int [],int);

int main()
{
    int n,i;
    scanf("%d",&n);
    int *a = (int *)malloc(n *sizeof(int));
    for(i=0;i<n;i++)
    scanf("%d",&a[i]);
    Selectionsort(a,n);
    return 0;
}

void Selectionsort(int a[],int n)
{
    int i,j,min,t;
    for(i=0;i<n-1;i++)
    {
        min=i;
        for(j=i+1;j<n;j++)
        if(a[j]<a[min])
        min=j;
        if(min!=i)
        {
            t=a[i];
            a[i]=a[min];
            a[min]=t;
        }	 	  	 		      	   	    	 	
    }
    for(i=0;i<n;i++)
    printf("%d ",a[i]);
}