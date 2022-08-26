/* Write a C program to implement Doubly Linked List operations. 

Test Case example:
input =
input= 
1
12 1
1 
45 2
1 
34 1
3
2
2
3
5
output =
FORWARD Traversal: 34 12 45 
BACKWARD Traversal: 45 12 34 
FORWARD Traversal: 34 45 
BACKWARD Traversal: 45 34 
*/
//Start writing program from here

#include<stdio.h>
#include<stdlib.h>
struct node
{
int data;
struct node *next;
struct node *pre;
};
struct node *head;
void insert();
void delete();
void display();
void search();
int c=0,b=0;

int main()
{	 	  	 		      	   	    	 	
    int ch;
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
            case 5:exit(0);
            default:printf("invalid choice");
        }
    }
    return 0;
}

void insert()
{
    int p,n,i;
    struct node *temp=(struct node *)malloc(sizeof(struct node));
    struct node *temp2,*x;
    scanf("%d%d",&n,&p);
    if(p<=0||p>c+1)
    printf("Enter a valid position");
    else
    {
        c++;
        temp->data=n;
        temp->next=NULL;
        temp->pre=NULL;
        if(head==NULL)
        head=temp;
        else if(p==1)
        {	 	  	 		      	   	    	 	
            x=head;
            x->pre=temp;
            temp->next=x;
            head=temp;
        }
        else
        {
            temp2=head;
            for(i=1;i<p-1;i++)
            {
                temp2=temp2->next;
            }
            temp->next=temp2->next;
            temp2->next=temp;
            temp->pre=temp2;
            if(p!=c)
            {
                temp2=temp->next;
                temp2->pre=temp;
            }
        }
    }
}

void delete()
{
    int p,i;
    struct node *temp1=head,*temp2;
    scanf("%d",&p);
    if(p<=0||p>c)
    printf("Enter a valid position");
    else
    {
        c--;
        if(p==1)
        {	 	  	 		      	   	    	 	
            head=temp1->next;
            if(c!=0)
            {
                temp2=temp1->next;
                temp2->pre=temp1->pre;
            }
            free(temp1);
        }
        else
        {
            for(i=1;i<p-1;i++)
            {
                temp1=temp1->next;
            }
            temp2=temp1->next;
            temp1->next=temp2->next;
            if(p!=c+1)
            {
                temp1=temp2->next;
                temp1->pre=temp2->pre;
            }
            free(temp2);
        }
    }
}

void search()
{
    int n,p=0;
    struct node *x;
    scanf("%d",&n);
    if(head==NULL)
    {
        printf("DLL is empty");
        return ;
    }	 	  	 		      	   	    	 	
    x=head;
    while(x!=NULL)
    {
        p++;
        if(x->data==n)
        {
            printf("%d found at position %d",x->data,p);
            return ;
        }
        x=x->next;
    }
    printf("element not found");
}

void display()
{
    int i;
    struct node *x;
    if(head==NULL)
    {
        printf("DLL is empty");
        return;
    }
    x=head;
    printf("FORWARD Traversal: ");
    while(x!=NULL)
    {
    printf("%d ",x->data);
    x=x->next;
    }
    printf("BACKWARD Traversal: ");
    x=head;
    for(i=0;i<c-1;i++)
    {
        x=x->next;
    }	 	  	 		      	   	    	 	
    while(x!=NULL)
    {
        printf("%d ",x->data);
        x=x->pre;
    }
}