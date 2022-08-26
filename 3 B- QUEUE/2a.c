/* Write a C program to implement QUEUE operations using array

Test Cases:
example 1:
input = 1 
12 
1 
21 
1 
45 
3 
4
output = 12 21 45

example 2:
case = t2
input = 2 4
output = queue is empty
*/
//Start writing program from here

#include<stdio.h>
#include<stdlib.h>
#define SIZE 3
int queue[SIZE];
int f=-1,r=-1;
void enqueue(int);
void dequeue();
void display();

int main()
{
    int ch,ele;
    while(1)
    {
        scanf("%d",&ch);
        switch(ch)
        {	 	  	 		      	   	    	 	
            case 1:scanf("%d",&ele);
                   enqueue(ele);
                   break;
            case 2:dequeue();
                   break;
            case 3:display();
                   break;
            case 4:exit(0);
            default :printf("invalid choice\n");  
        }
    }
    return 0;
}

void enqueue(int ele)
{
    if(r==SIZE-1)
    printf("queue is full");
    else
    {
        r=r+1;
        queue[r]=ele;
    }
}

void dequeue()
{
    if(f==r)
    printf("queue is empty");
    else
    {
        f=f+1;
        printf("%d is deleted from queue\n",queue[f]);
        if(f==r)
        {
            f=-1;
            r=-1;
        }	 	  	 		      	   	    	 	
    }
}

void display()
{
    int i;
    if(r==f)
    printf("queue is empty");
    else
    for(i=f+1;i<=r;i++)
    printf("%d ",queue[i]);
}



























	 	  	 		      	   	    	 	
