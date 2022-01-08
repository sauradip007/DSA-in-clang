#include <stdio.h>
#include <stdlib.h>
int visited[7] = {0, 0, 0, 0, 0, 0, 0};
int a[7][7] = {{1, 0, 0, 1, 0, 0, 0}, {1, 1, 0, 1, 1, 0, 0}, {1, 0, 1, 0, 1, 0, 0}, {0, 0, 1, 1, 0, 1, 1}, {0, 0, 0, 0, 1, 0, 0}, {0, 0, 0, 0, 1, 0, 0}

}; // adj array
void DFS(int i)
{
    int j;
    printf("%d",i); //prints whatever node you visit first
    visited[i] = 1; // denotes visited node
    for(int j = 0; j < 7 ; j++)
    {
        if(a[i][j] == 1 && !visited[j]) //if there is an edge denoted by 1 in the adj array and its unvisited
        {
            DFS(j);

        }

    }
}

int main()
{
   // array of nodes it has visited
    DFS(0);
}