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
    static struct node *prev = NULL;
    if (root != NULL)
    {
        if (!isBST(root->left))
        {
            return 0;
        }
        if (prev != NULL && root->data <= prev->data)
        {
            return 0;
        }
        prev = root;
        return isBST(root->right);
    }
    else
    {
        return 1;
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
void insert(struct node *root, int key)
{
    struct node *prev = NULL;
    while (root != NULL)
    {
        prev = root; // assigns a previous pointer which equals root i.e. when root is null the previous val is taken up by prev
        if (key == root->data)
        {
            return;
        }
        else if (key < root->data) // as it is being traversed along the tree, it checks if the key entered is compared with the root data as it follows the loop , if less it traverses to the left subtree  of it
        {
            root = root->left;
        }
        else
        { // if greater it traverses to the right subtree of it
            root = root->right;
        }
    }
    // once root reaches null and prev pointer gets assigned , a new node which takes up the key value is created in the heap
    struct node *new = createNode(key);
    if (key < prev->data)
    { // if THAT value is less than the data stored in prev node , its inserted at the left
        prev->left = new;
    }
    else
    { // if its greater then its stored to the left
        prev->right = new;
    }
}
struct node* inOrderPredecessor(struct node* root){
    //it is the right most child of its left subtree 
    root = root->left;
    while( root->right != NULL)
    {
        //to traverse till right most child
        root = root->right;
    }
    return root;
}
struct node* deleteNode(struct node* root, int value)
{
    struct node* iPre;
    if(root == NULL)
    {
        return NULL;
    }
    if(root->left == NULL && root->right == NULL)
    //LEAF POSITION HAS BEEN REACHED
    {
        free(root);
        return NULL;
    }
    //search for the node to be deleted
    if(value < root->data){
      root->left =  deleteNode(root->left, value);

    }
    else if( value > root->data)
    {
       root->right =  deleteNode(root->right, value);
    }
    //deletion strategy when node IS found i.e. equal
    else{
        iPre = inOrderPredecessor(root);//represents its inorder predecessor of node to be deleted which behaves like the root
        root->data = iPre->data;
        root->left = deleteNode(root->left, iPre->data);//now that inorder predecessor present in the left subtree has replaced node to be deleted , now that predecessor is deleted
        //after replacement move till leaf req.d node and delete
    }
    return root;
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
    // inorder(p)
    inorder(p);
    deleteNode(p,3);
    printf("\n");
    inorder(p);

    return 0;
}
