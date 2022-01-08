#include <stdio.h>
#include <stdlib.h>
//creating an adjacency matrix 
int visited[7] = {0, 0, 0, 0, 0, 0, 0};//initialised visited array of nodes
int a[7][7] = {
    {0, 1, 1, 1, 0, 0, 0},
    {1, 0, 1, 0, 0, 0, 0},
    {1, 1, 0, 1, 1, 0, 0},
    {1, 0, 1, 0, 1, 0, 0},
    {0, 0, 1, 1, 0, 1, 1},
    {0, 0, 0, 0, 1, 0, 0},
    {0, 0, 0, 0, 1, 0, 0}
    };

void DFS(int i)
{
    printf("%d ", i);
    visited[i] = 1;
    for (int j = 0; j < 7; j++)
    {
        if (a[i][j] == 1 && !visited[j])
        {
            DFS(j);
        }
    }
}

int main()
{
    
    DFS(0);
    return 0;
}