#include<stdio.h>
#include<stdlib.h>
struct Node{
    int key;
    struct Node* left;
    struct Node* right;
    int height;
};
int getHeight(struct Node* n)
{
    if(n==NULL)
    {
        return 0;
    }
    return n->height;
}
struct Node* creatNode(int key)
{
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->key = key;
    node->left = NULL;
    node->right = NULL;
    node->height = 1;
    //this is the leaf node to be inserted
}
int getBalanceFactor(struct Node* n)
{
    if(n == NULL)
    {
        return 0; //no bf
    }
    return getHeight(n->left) - getHeight(n->right);
}
struct Node* leftRotate(struct Node* y)
{
    struct Node* x = y->left;
    struct Node* T2 = x->right;
    x->right = y;
    y->left = T2; //after rotation

    y->height = max(getHeight(y->right), getHeight(y->left)) + 1; //whichever subtree of y has greater height will be its height to consider
    
    //similarly
    x->height = max(getHeight(x->right), getHeight(x->left)) + 1;
    return x;
}