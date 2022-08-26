/* Write a C program to implement STACK operations using array

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
output = 45 21 12

example 2:
case = t2
input = 2 4
output = stack is empty
*/
//Start writing program from here

#include<stdio.h>
#include<stdlib.h>
#define STACK_SIZE 3
int stack[STACK_SIZE];
int top=-1;

void push(int);
void pop();
void display();

int main()
{
    int item,ch;
    while(1)
    {
        scanf("%d",&ch);
        switch(ch)
        {	 	  	 		      	   	    	 	
            case 1: scanf("%d",&item);
            push(item);
            break;
            case 2: pop();
            break;
            case 3: display();
            break;
            case 4: exit(0);
            default: printf("invalid choice");
        }
    }
    return 0;
}

void push(int element)
{
    if(top==STACK_SIZE-1)
    printf("stack is full");
    else
    {
        top = top + 1;
        stack[top] = element;
    }
}

void pop()
{
    if(top==-1)
    printf("stack is empty");
    else
    {
        printf("%d is popped from stack\n",stack[top]);
        top--;
    }
}

void display()
{	 	  	 		      	   	    	 	
    int i;
    if(top==-1)
    printf("stack is empty");
    else
    for(i=top;i>=0;i--)
    printf("%d ",stack[i]);
}