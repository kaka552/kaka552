/* Write a C program to implement Circular Linked List operations. 
Test Case examples:
input =
1                                                                               
12 1                                                                            
1                                                                               
23 2                                                                            
1                                                                               
34 3                                                                            
4                                                                               
3                                                                               
2                                                                               
2                                                                               
3                                                                               
4                                                                               
6                                                                         
output =
23->34->12  
12->23->34-> 
12->34-> 
34->12

input =
1
12 1
1 
13 2
1
23 3
5 13
6
output=
13 found at position 2
 

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
            case 4:revdisplay();
                   break;       
            case 5:search();
                   break;
            case 6:exit(0);
            default:printf("\ninvalid choice");
        }
    }	 	  	 		      	   	    	 	
}

void insert()
{
    int n,p,i;
    struct node *temp=(struct node*)malloc(sizeof(struct node));
    struct node *temp2,*x;
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
            x=head;
            for(i=1;i<c;i++)
            x=x->next;
            x->next=temp;
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
    struct node *temp1=head,*temp2,*x;
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
            x=head;
            for(i=1;i<c;i++)
            x=x->next;
            x->next=head;
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
    if(x==NULL)
    {
        printf("list is empty");
        return ;
    }	 	  	 		      	   	    	 	
    do
    {
        printf("%d-> ",x->data);
        x=x->next;
    }while(x!=head);
}

void search()
{
    int n,p=0,flag=0;
    struct node *x=head;
    scanf("%d",&n);
    do
    {
        if(x==NULL)
        {
            printf("list is empty");
            return ;
        }
        p++;
        if(x->data==n)
        {
            flag=1;
            break;
        }
        x=x->next;
    }while(x!=head);
    if(flag==1)
    printf("\n%d found at position %d",x->data,p);
    else
    printf("\nelement not found");
}

void revdisplay()
{
    struct node *ptr;
    ptr=head->next;
    if(ptr==NULL)
    {	 	  	 		      	   	    	 	
        printf("list is empty");
        return;
    }
    do
    {
        printf("%d->",ptr->data);
        ptr=ptr->next;
    }while(ptr!=head->next);
}


