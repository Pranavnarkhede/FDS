#include <stdio.h>
int main()
{
    int   u , v , a , b , n , min , totalCost=0 ;
    printf("Enter no of vertices==>");
    scanf("%d",&n);
    int prims[n][n] , visited[n] ;
    for(int i = 0 ; i < n ; i++)
    {
        visited[i] = 0;
    }
    printf("enter array elements : \n");
    for(int i = 0 ; i < n ; i ++)
    {
        for(int j = 0 ; j < n ; j++)
        {
            scanf("%d",&prims[i][j]);
            if(prims[i][j] == 0)
            {
                prims[i][j] = 999;
            }
        }
    }
    visited[0] = 1;
    for(int i = 0 ; i < n ; i++)
    {
        min = 999; 
        for(int j = 0 ; j < n  ; j++)
        {
            if(prims[i][j] < min )
            {
                min = prims[i][j];
                a = u = i;
                b = v = j;
            }
        }
        if(visited[u] == 0 || visited[v] == 0)
        {
            totalCost = totalCost + min;
            printf("there is path from %d to %d with cost %d\n",u,v,min);
            visited[v] = 1;
            visited[u] = 1;
        }
        prims[a][b] = prims[b][a] = 999;
    }
    printf("the cost of min spanning tree is %d ",totalCost);
    return 0;
}
