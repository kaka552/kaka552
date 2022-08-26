/* Write a C program to implement Bubble sort

Test Cases:
input = 5
2 5 6 10 3
output = 2 3 5 6 10
*/
//Start writing program from here
#include<stdio.h>
#include<stdlib.h>

void Bubblesort(int [],int);

int main()
{
    int n,i;
    scanf("%d",&n);
    int *a = (int *)malloc(n *sizeof(int));
    for(i=0;i<n;i++)
    scanf("%d",&a[i]);
    Bubblesort(a,n);
    return 0;
}

void Bubblesort(int a[],int n)
{
    int i,j,t;
    for(i=0;i<n-1;i++)
    {
        for(j=0;j<n-i-1;j++)
        {
            if(a[j]>a[j+1])
            {
                t=a[j];
                a[j]=a[j+1];
                a[j+1]=t;
            }	 	  	 		      	   	    	 	
        }
    }
    for(i=0;i<n;i++)
    printf("%d ",a[i]);
}