#include<stdio.h>
#include<stdlib.h>
#define maxNode 4 //say there is a graph with 4 nodes
typedef struct Node//Node is a struct to store vertices
{
    int vertexNum; //stores vertices
    struct Node* next; //next pointer of LL
} Node;
typedef struct List{
    Node* head;
}List;//a list of head nodes is created
List *adjList[maxNode] = {0}; //array of header list nodes is created and initialised to 0
void addNode(int s, int d)
{
    Node *dest, *tmp, *src;
    if(adjList[s]->head == NULL)
    {
        src = (Node*)malloc(sizeof(Node));
        src->vertexNum = s;
        src->next = NULL;
        adjList[s]->head = src;
    }
    dest = (Node*)malloc(sizeof(Node));
    dest->vertexNum = d;
    dest->next = NULL;
    tmp = adjList[s]->head;//used to traverse the LL
    while(tmp->next != NULL){
        tmp = tmp->next;
       
    }
    tmp->next = dest; //source points to dest
}
int main()
{
    int i;
    for(i = 0 ; i < maxNode; i++)
    {
        adjList[i] = (List*)malloc(sizeof(List)); //creates the header array
        adjList[i]->head = NULL;//header points to 0
    }
    addNode(0,1);
    addNode(0,3);
    addNode(1,2);
}