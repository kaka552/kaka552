/* Write a C program to implement Circular Queue Operations

Test Case example:

input = 
1                                                                               
12                                                                              
1                                                                               
21                                                                              
1                                                                               
45                                                                              
3  
2
2
1
50
3

output =
12      21      45                                                              
rear=2 pointing at 45                                                           
front=0 pointing at 12                                                          
Deleted Element is 12                                                           
Deleted Element is 21                                                           
50      45                                                                      
rear=0 pointing at 50                                                           
front=2 pointing at 45 

Test Case example 2:
input = 
1                                                                               
12                                                                              
1                                                                               
21                                                                              
1                                                                               
45                                                                              
3  
2
2
1
50
1
80
3
1
100

output =
12      21      45                                                              
rear=2 pointing at 45                                                           
front=0 pointing at 12                                                          
Deleted Element is 12                                                           
Deleted Element is 21                                                           
50   80   45                                                                      
rear=1 pointing at 80                                                           
front=2 pointing at 45  
queue overflow


*/
//Start writing program from here

#include<stdio.h>
#include<stdlib.h>

#define SIZE 3
char q[SIZE];
int f=-1,r=-1;

void CQinsert(int );
int CQdelete();
int CQfull();
int CQempty();
void display();

int main()
{	 	  	 		      	   	    	 	
    int choice;
    int ele;
    while(1)
    { 
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:scanf("%d",&ele);
                   CQinsert(ele);
                   break;
            case 2:CQdelete();
                   break;
            case 3:display();
                   break;
            case 4:exit(0);
            default:printf("invalid choice\n");
        }
    }
}

void CQinsert(int ele)
{
    if(CQfull())
    printf("queue overflow\n");
    else
    {
        if(f==-1)
        f=0;
        r=(r+1)%SIZE;
        q[r]=ele;
    }
}

int CQdelete()
{
    int ele=0;
    if(CQempty())
    {	 	  	 		      	   	    	 	
        printf("queue underflow\n");
        return 0;
    }
    else
    {
        ele=q[f];
        printf("Deleted Element is %d\n",ele);
        if(f==r)
        {
            f=-1;
            r=-1;
        }
        else
        f=(f+1)%SIZE;
        return ele;
    }
}

void display()
{
    int i;
    if(CQempty())
    printf("queue is empty\n");
    else
    {
        if(f>r)
        {
            for(i=0;i<=r;i++)
            printf("%d ",q[i]);
            for(i=f;i<SIZE;i++)
            printf("%d ",q[i]);
            printf("\nrear=%d pointing at %d",r,q[r]);
            printf("\nfront=%d pointing at %d\n",f,q[f]);
        }
        else
        {	 	  	 		      	   	    	 	
            for(i=f;i<=r;i++)
            printf("%d ",q[i]);
            printf("\nrear=%d pointing at %d",r,q[r]);
            printf("\nfront=%d pointing at %d\n",f,q[f]);
        }
    }
}

int CQfull()
{
    if((r==SIZE-1 && f==0)||(f==r+1))
    return 1;
    return 0;
}

int CQempty()
{
    if(f==-1)
    return 1;
    return 0;
}