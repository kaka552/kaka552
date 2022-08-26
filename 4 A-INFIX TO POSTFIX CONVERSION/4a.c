// Write a C program to implement INFIX TO POSTFIX conversion.

//Test Case example:

// input = a-b/(c*d$e)

// output = abcde$*/-

//Start writing program from here

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define SIZE 20
int stack[SIZE],top=-1;

void push(char );
char pop();
int sp(char );
int ip(char );
void infix_to_postfix(char [],char []);

int main()
{
    char infix[20],postfix[20];
    scanf("%s",infix);
    infix_to_postfix(infix,postfix);
    printf("%s",postfix);
    return 0;
}

void infix_to_postfix(char infix[],char postfix[])
{
    int j=0,k;
    char sy;
    push('#');
    for(k=0;k<strlen(infix);k++)
    {	 	  	 		      	   	    	 	
        sy=infix[k];
        while(sp(stack[top])>ip(sy))
        postfix[j++]=pop();
        if(sp(stack[top])!=ip(sy))
        push(sy);
        else
        pop();
    }
    while(stack[top]!='#')
    postfix[j++]=pop();
    postfix[j]='\0';
}

int sp(char s)
{
    switch(s)
    {
        case '+':
        case '-':return 2;
        case '*':
        case '/':return 4;
        case '$':
        case '^':return 5;
        case '(':return 0;
        case '#':return -1;
        default :return 8;
    }
}

int ip(char s)
{
    switch(s)
    {
        case '+':
        case '-':return 1;
        case '*':
        case '/':return 3;
        case '$':
        case '^':return 6;
        case '(':return 9;
        case ')':return 0;
        default :return 7;
    }	 	  	 		      	   	    	 	
}

void push(char ele)
{
    if(top==SIZE-1)
    printf("stack is full");
    else
    stack[++top]=ele;
}

char pop()
{
    return stack[top--];
}