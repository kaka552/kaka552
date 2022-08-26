/* Write a C program to implement traverse the graph in DFS order.

Test Case example:

input= 5
0 1 1 1 0     
1 0 0 0 1                           
1 0 0 0 1
1 0 0 0 1
0 1 1 1 0
1
output=
1 2 5 3 4


*/
//Start writing program from here

#include<stdio.h>
void DFS(int);
int G[10][10],visited[10],n,s;
void main()
{
    int i,j;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
       for(j=1;j<=n;j++)
            scanf("%d",&G[i][j]);
    for(i=1;i<=n;i++)
        visited[i]=0;
    scanf("%d",&s);
    DFS(s);
}
void DFS(int i)
{
    int j;
    printf("%d ",i);
    visited[i]=1;
    for(j=1;j<=n;j++)
       if((visited[j]==0)&&G[i][j]==1)
            DFS(j);
}