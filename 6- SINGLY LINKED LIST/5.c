/* Write a C program to implement Singly Linked List operations. 

Test Case examples:

input= 
1                                                                               
12 1                                                                            
1                                                                               
14 1                                                                            
1                                                                               
24 2                                                                            
3

output =
14-> 24-> 12->

input= 
1                                                                               
12 1                                                                            
1                                                                               
13 3
5
output =
Enter a valid position 

*/
//Start writing program from here

#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *head;
void insert();
void delete();
void display();
void search();
void revdisplay();

int c=0,b=0;

void main()
{	 	  	 		      	   	    	 	
    int ch,a;
    head=NULL;
    while(1)
    {
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:insert();
                   break;
            case 2:delete();
                   break;
            case 3:display();
                   break;
            case 4:search();
                   break;
            case 5:revdisplay();
                   break;
            case 6:exit(0);
            default:printf("invalid choice");
        }
    }
}

void insert()
{
    int n,p,i;
    struct node *temp=(struct node*)malloc(sizeof(struct node));
    struct node *temp2;
    scanf("%d%d",&n,&p);
    if(p<=0||p>c+1)
    printf("\nenter a valid position");
    else
    {
        c++;
        temp->data=n;
        temp->next=NULL;
        if(p==1)
        {	 	  	 		      	   	    	 	
            temp->next=head;
            head=temp;
        }
        else
        {
            temp2=head;
            for(i=1;i<p-1;i++)
            temp2=temp2->next;
            temp->next=temp2->next;
            temp2->next=temp;
        }
    }
}

void delete()
{
    int p,i;
    struct node *temp1=head,*temp2;
    scanf("%d",&p);
    if(p<=0||p>c)
    printf("\nenter a valid position");
    else
    {
        c--;
        if(p==1)
        {
            head=temp1->next;
            free(temp1);
        }
        else
        {
           for(i=1;i<p-1;i++)
           temp1=temp1->next;
           temp2=temp1->next;
           temp1->next=temp2->next;
           free(temp2);
        }	 	  	 		      	   	    	 	
    }
}

void display()
{
    struct node *x;
    x=head;
    while(x!=NULL)
    {
        printf("%d-> ",x->data);
        x=x->next;
    }
}

void search()
{
    int n,p=0,flag=0;
    struct node *x=head;
    scanf("%d",&n);
    while(x!=NULL)
    {
        p++;
        if(x->data==n)
        {
            flag=1;
            break;
        }
        x=x->next;
    }
    if(flag==1)
    printf("\n%d is found at position %d",x->data,p);
    else
    printf("\n%d element not found",n);
}

void revdisplay()
{	 	  	 		      	   	    	 	
    int i=0;
    int *a=(int *)malloc(c*sizeof(int));
    struct node *x=head;
    while(x!=NULL)
    {
       a[i]=x->data;
       x=x->next;
       i++;
    }
    for(i=c-1;i>=0;i--)
    {
        printf("%d",a[i]);
        if(i!=0)
        printf("-> ");
    }
}