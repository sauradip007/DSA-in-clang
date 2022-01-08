#include <stdio.h>
#include <stdlib.h>
#define MAX 100
struct node
{
    int data;
    struct node *left;
    struct node *right;
};
struct node *stack[MAX];
int top = -1;
void push_stack(struct node *item)
{
    if (top == (MAX - 1))
    {
        printf("\nStack Overflow");
    }
    top = top + 1;
    stack[top] = item;
}
struct node *pop_stack()
{
    struct node *item;
    if (top == -1)
    {
        printf("\nStack Undeflow");
    }
    item = stack[top];
    top = top - 1;
    return item;
}
int stack_empty()
{
    if (top == -1)
    {
        return 1;
    }
    return 0;
}
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
    struct node *ptr = root;
    if (ptr == NULL)
    {
        printf("\nEmpty tree");
        return;
    }

    
        while (ptr->left != NULL)
        {
            push_stack(ptr);
            ptr = ptr->left;
        }
        while (ptr->right == NULL)
        {
            printf("\t%d", ptr->data);
            if (stack_empty())
            {
                return;
            }
            ptr = pop_stack();
        }
        printf("\t%d", ptr->data);
        ptr = ptr->right;
    
    printf("\n");
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
    printf("\nThe inorder traversal is : \n");
    inorder(p);
}
