/* Write a C program to implement BST TREE TRAVERSAL TECHNIQUES BFS(level-order) AND DFS (only inorder and preorder)

Test Case example:
case = t4
input=
1
100
1
23
1
150
1
5
2
3
4
output=
100->23->150->5->
Preorder Traversal is:100->23->5->150->
Inorder Traversal is:5->23->100->150->

*/
//Start writing program from here

#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

int f=-1,r=-1;
struct node *queue[100];

struct node *root=NULL;

struct node *getnode(int n);
struct node *insert(struct node *root,int ele);
// struct node *del(struct node *root);
void display(struct node *root);
void dfs(struct node *root);
void inorder(struct node *root);
void preorder(struct node *root);

struct node *getfrount()
{
    int m=f+1;
    return queue[m];
}

void enqueue(struct node *x)
{
    r++;
    queue[r]=x;
}

void dequeue()
{
    f++;
}

int main()
{
    int ch,ele;
    while(1)
    {
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:scanf("%d",&ele);
                    root=insert(root,ele);
                    break;
            case 2:display(root);
                    break;
            case 3:dfs(root);
                    break;
            case 4:exit(0);
            default:printf("invalid choice");
        }
    }
}

struct node *getnode(int n)
{
    struct node *temp=(struct node *)malloc(sizeof(struct node));
    temp->data=n;
    temp->left=NULL;
    temp->right=NULL;
    return temp;
}

struct node *insert(struct node *root,int ele)
{
    if(root==NULL)
    {
        root=getnode(ele);
        return root;
    }
    else if(ele<=root->data)
    root->left=insert(root->left,ele);
    else 
    root->right=insert(root->right,ele);
}

void display(struct node *root)
{
    struct node *temp;
    if(root==NULL)
    {
        printf("\nTree is empty");
        return ;
    }
    enqueue(root);
    while(f!=r)
    {
        temp=getfrount();
        printf("%d->",temp->data);
        if(temp->left!=NULL)
        enqueue(temp->left);
        if(temp->right!=NULL)
        enqueue(temp->right);
        dequeue();
    }
}

void dfs(struct node *root)
{
    printf("\nPreorder Traversal is:");
    preorder(root);
    printf("\nInorder Traversal is:");
    inorder(root);
}

void inorder(struct node *root)
{
    if(root==NULL)
        return ;
    inorder(root->left);
    printf("%d->",root->data);
    inorder(root->right);
}

void preorder(struct node *root)
{
    if(root==NULL)
        return ;
    printf("%d->",root->data);
    preorder(root->left);
    preorder(root->right);
}





























