#include <stdio.h>
#include <malloc.h>
struct node
{
    int data;
    struct node *left;
    struct node *right;
};
struct node *createNode(int data) // creating a node pointer
{
    struct node *p;
    p = (struct node *)malloc(sizeof(struct node));
    p->data = data; // setting the data
    p->left = NULL; // initialising left and right data as null
    p->right = NULL;
    return p; // finally returning the created node as root
}
void inorder(struct node *root)
{
    if (root != NULL)
    {

        inorder(root->left);
        printf("\t%d", root->data);
        inorder(root->right);
       
    }
    
}
int isBST(struct node *root)
{
    static struct node *prev = NULL; //prev is null only when it precedes root
    if (root != NULL)//no tree so not a BST
    {
        if (!isBST(root->left))//checking for left subtree
        {
            return 0;
        }
        if (prev != NULL && root->data <= prev->data)
        {
            return 0;
        }//replicating inorder traversal
        prev = root;
        return isBST(root->right);//repeats the same process for right subtree
    }
    else
    {
        return 1;
    }
}

int main()
{
    // struct node *p;
    // p = (struct node*)malloc(sizeof(struct node));
    // p->data = 2;
    // p->left = NULL;
    // p->right = NULL;
    // // root node has been declared in the heap
    // struct node *p1;
    // p1 = (struct node *)malloc(sizeof(struct node));
    // p->data = 1;
    // p1->left = NULL;
    // p1->right = NULL;
    // // child node 1
    // struct node *p2;
    // p2 = (struct node *)malloc(sizeof(struct node));
    // p->data = 1;
    // p2->left = NULL;
    // p2->right = NULL;
    // // child node 2
    // p->left = p1;
    // p->right = p2;
    // making linkage between root and both the nodes
    struct node *p = createNode(5);
    struct node *p1 = createNode(3);
    struct node *p2 = createNode(6);
    struct node *p3 = createNode(1);
    struct node *p4 = createNode(4);
    // Linking the root node with left and right children
    p->left = p1;
    p->right = p2;
    p1->left = p3;
    p1->right = p4;
    inorder(p);
    return 0;
}