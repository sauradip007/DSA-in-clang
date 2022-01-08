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
// int isBST(struct node *root)
// {
//     static struct node *prev = NULL;
//     if (root != NULL)
//     {
//         if (!isBST(root->left))
//         {
//             return 0;
//         }
//         if (prev != NULL && root->data <= prev->data)
//         {
//             return 0;
//         }
//         prev = root;
//         return isBST(root->right);
//     }
//     else
//     {
//         return 1;
//     }
// }
struct node* mini(struct node* root)
{
   
    if(root == NULL)
    {
        return NULL;
    }
    if(root->left == NULL && root->right == NULL)
    {
        return root;
    }
    return mini(root->left);
    // while(root->left != NULL)
    // {
    //     return mini(root->left);
    // }
}
struct node* maxi(struct node* root)
{
    if(root ==NULL)
    {
        return NULL;
    }if(root->right == NULL && root->left == NULL)
    {
        return root;
    }
    return maxi(root->right);
}
int main()
{
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
    // inorder(p);
    struct node *n = mini(p);
    struct node* q = maxi(p);
    printf("\nMin is : %d", n->data);
    printf("\nMax is : %d", q->data);
}