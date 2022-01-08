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
void preorder(struct node *root)
{
    if (root != NULL)
    {
        printf("\t%d", root->data); //traverses tree root->left->right
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(struct node *root)
{
    if (root != NULL)
    {

        postorder(root->left); // traverses tree from left->right->root
        postorder(root->right);
        printf("\t%d", root->data);
    }
}

void inorder(struct node *root)
{
    if (root != NULL)
    {                           //traverses tree from left->root->right

        inorder(root->left);
        printf("\t%d", root->data);
        inorder(root->right);
    }
}
struct node *search(struct node *root, int key)
{
    if (root == NULL)
    {
        return NULL;
    }
    if (key == root->data)
    {
        return root;
    }
    else if (key < root->data)
    {
        return search(root->left, key);
    }
    else
    {
        return search(root->right, key);
    }
}
int smallest(struct node* root)
{
    struct node* current = root;
    while(current->left != NULL)
    {
        current = current->left;
    }
    return current->data;
}
int largest(struct node* root)
{
    struct node* current = root;
    while(current->right != NULL)
    {
        current = current->right;
    }
    return current->data;
}

int main()
{
    //creating a binary search tree
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
    printf("\nPreorder is : ");
    printf("\n");
    preorder(p);
    printf("\nPostorder is : ");
    printf("\n");
    postorder(p);
    printf("\nInorder is : ");
    printf("\n");
    inorder(p);
    printf("\n");
    struct node *n = search(p, 6);
    if (n != NULL)
    {
        printf("\nfound : %d", n->data);
    }
    else
    {
        printf("\nElement not found : ");
    }
    
    printf("\nThe smallest element is : %d", smallest(p));
    printf("\nThe largest element is : %d", largest(p));
    return 0;
}