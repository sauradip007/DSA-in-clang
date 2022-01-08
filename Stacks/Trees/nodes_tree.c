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
    return p; // finally returning the created node
}
void printlevelnode(struct node *root, int level)
{
    if (root == NULL)
        return;

    if (level == 1)
    {
        if (root->left == NULL && root->right == NULL)
        {
           printf("\t%d", root->data);
        }
    }
    else if (level > 1)
    {
        printlevelnode(root->left, level - 1);
        printlevelnode(root->right, level - 1);
    }
}

int leafnode(struct node* root)
{
    if(root == NULL)
    {
        return 0;
    }
    else if(root->left == NULL && root->right == NULL)
    {
        return 1;
    }
    int totalNodes = leafnode(root->left) + leafnode(root->right);
    return totalNodes;
}
int depthmax(struct node* root, int x)
{
    int d;
    if(root==NULL)
    {
        return -1;
    }
    if ((root->data == x || (d = depthmax(root->left, x)) >= 0 || (d = depthmax(root->right, x)) >= 0))
    {
        return d + 1;
    }

    return d;
}
int nonleaf(struct node* root)
{
    if(root==NULL)
    {
        return 0;
    }
    if(root->left == NULL && root->right==NULL)
    {
        return 0;
    }
    return (nonleaf(root->left) + nonleaf(root->right) +1);
}
int depth(struct node* root, int x)
{
    int d;
    if (root == NULL)
    {
        return -1;
    }
    if ((root->data == x || (d = depthmax(root->left, x)) >= 0 || (d = depthmax(root->right, x)) >= 0))
    {
        return d + 1;
    }

    return d;
}
int nodes(struct node* root)
{
    if(root == NULL)
    {
        return 0;
    }//base case
    int count1 = 0,count2 = 0;
    int l = nodes(root->left);
    count1++;
    int r = nodes(root->right);
    count2++;
    return l+r+ 1;
}
int sumnodes(struct node* root)
{
    if(root==NULL)
    {
        return 0;
    }
    int suml = sumnodes(root->left);
    int sumr = sumnodes(root->right);
    int sum = suml + sumr + root->data;
    return (root->data + suml + sumr);
}
int height(struct node* root)
{
    int left;
    int right;
    if(root == NULL)
    {
        return 0;
    }//base case 
    left = height(root->left);
    right = height(root->right);
    if(left > right)
    {
        return 1 + left;
    }
    else{
        return 1 + right;
    }
}

int main()
{
    
  
    struct node *p = createNode(4);
    struct node *p1 = createNode(1);
    struct node *p2 = createNode(6);
    struct node *p3 = createNode(5);
    struct node *p4 = createNode(2);
    // Linking the root node with left and right children
    p->left = p1;
    p->right = p2;
    p1->left = p3;
    p1->right = p4;
    printf("\nThe height of tree is : %d", height(p));
    printf("\nThe number of nodes are : %d",nodes(p));
    printf("\nThe maximum depth is : %d", depth(p));
    printf("\nThe number of leaf nodes are : %d", leafnode(p));
    printf("\nThe sum of nodes are : %d", sumnodes(p));
    printf("\nThe total non leaf nodes are : %d", nonleaf(p));
    int x;
    printf("\nEnter element whose depth is to be found : ");
    scanf("%d", &x);
    printf("\nThe depth is given by : %d", depthmax(p,x));
    return 0;
    
}