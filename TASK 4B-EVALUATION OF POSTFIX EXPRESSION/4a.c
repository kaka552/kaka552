/* Write a C program to evaluation postfix expression.

Test Case example:

input = abc*+d-
2 3 1 9
output = -4

*/
//Start writing program from here

#include<stdio.h>
#include<string.h>

#define SIZE 50
int stack[SIZE];
int top=-1;
int isoperand(char );
int isoperator(char );
void push(int );
int pop();
int postfixcheck(int ,int );

int main()
{
    char postfix[50],ch;
    int i,x,value,operand=0,operators=0;
    int a,b,c;
    scanf("%s",postfix);
    for(i=0;i<strlen(postfix);i++)
    {
        ch=postfix[i];
        if(isoperand(ch))
       {
        operand=operand+1;
       }    
        else
       {	 	  	 		      	   	    	 	
        operators=operators+1;
       }
       }
    if(postfixcheck(operand,operators))
   {
    for(i=0;i<strlen(postfix);i++)
    {
        ch=postfix[i];
        if(isoperand(ch))
        {
            scanf("%d",&x);
            push(x);
        }
        if(isoperator(ch))
        {
            a=pop();
            b=pop();
            switch(ch)
            {
                case '+':c=b+a;break;
                case '-':c=b-a;break;
                case '*':c=b*a;break;
                case '/':c=b/a;break;
                case '%':c=b%a;break;
                case '^':c=b^a;break;
                default :printf("invalid option");
            }
            push(c);
        }
    }
    value=pop();
    printf("%d",value);
   }
   else
   printf("invalid postfix expression");
    return 0;
}	 	  	 		      	   	    	 	

int isoperand(char ch)
{
    if((ch>='a' && ch<='z')||(ch>='A' && ch<='Z'))
    return 1;
    else
    return 0;
}

int isoperator(char ch)
{
    if(ch=='+'||ch=='-'||ch=='*'||ch=='/'||ch=='%'||ch=='^')
    return 1;
    else
    return 0;
}

void push(int ele)
{
    top++;
    stack[top]=ele;
}

int pop()
{
    return stack[top--];
}

int postfixcheck(int operand,int operators)
{
    if(operand==(operators+1))
    return 1;
    else
    return 0;
}








	 	  	 		      	   	    	 	
