/* Write a C program to implement Insertion sort

Test Cases:
input = 5
2 5 6 10 3
output = 2 3 5 6 10
*/
//Start writing program from here

#include<stdio.h>
#include<stdlib.h>

void Insertionsort(int [],int);

int main()
{
    int n,i;
    scanf("%d",&n);
    int *a = (int *)malloc(n *sizeof(int));
    for(i=0;i<n;i++)
    scanf("%d",&a[i]);
    Insertionsort(a,n);
    return 0;
}

void Insertionsort(int a[],int n)
{
    int i,j,t;
    for(i=1;i<n;i++)
    {
        t=a[i];
        for(j=i-1;j>=0 && t<a[j];j--)
        {
            a[j+1]=a[j];
        }
        a[j+1]=t;
    }	 	  	 		      	   	    	 	
    for(i=0;i<n;i++)
    printf("%d ",a[i]);
}