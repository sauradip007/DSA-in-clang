#include<stdio.h>
#include<stdlib.h>
struct Graph{
    int V;
    int E;
    int **Adj; //points to adjacency matrix , pointer to 2D matric since we know *(*(a+i)+j)
};
struct Graph* adjMatrixOfGraph()//returns address of graph struct
{
    int u,v,i;
    struct Graph *G = (struct Graph*)malloc(sizeof(struct Graph));
    if(G)//No memory allocated i.e. G=NULL
    {
        printf("\nNo memory allocaated");
        return;
    }
    printf("\nEnter the no of nodes and edges");
    scanf("%d %d", &G->V, &G->E);
    G->Adj = malloc(sizeof(int)*(G->V*G->E));//stores address stored in adj i.e. newly created matrix
    for(u = 0 ; u <G->V;u++)
    {
        for(v=0; v < G->E; v++)
        {
            G->Adj[u][v] = 0;//initialising matrix to 0
        }
    }
    printf("\nEnter node in pairs for an edge");
    for(i = 0; i < G->E; i++)
    {
        scanf("%d,%d", &u, &v);
        G->Adj[u][v]=1;
        G->Adj[v][u]= 1;//since graph is undirected , link goes both ways
    }
};
int main(int argc, char *argv[])
{
    adjMatrixOfGraph();
    return 0;
}