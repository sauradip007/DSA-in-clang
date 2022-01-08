#include<stdio.h>
#include<stdlib.h>
struct stack{
    int size;
    int top;
    int* arr;//dynamically allocates array in the heap which holds stack
};
int isEmpty(struct stack* ptr)
{
    if(ptr-> top == -1)//denotes stack is empty
    {
        return 1; //is true
    }
    else{
    return 0;
    }
}
int isFull(struct stack* ptr)
{
    if (ptr->top == ptr->size - 1) //denotes stack is full (size of array -1 is last index)
    {
        return 1;
    }
    else{
    return 0;
    }

}
void push(struct stack* ptr, int val)//pushes val in
{
    if(isFull(ptr))
    {
        printf("\nStack overflow");
    }
    else{
        ptr->top++;
        ptr->arr[ptr->top] = val;
    }
}
int pop(struct stack* ptr)//pushes val in
{
    if(isEmpty(ptr))
    {
        printf("\nStack underflow");
        return -1;
    }
    else{
        int val = ptr->arr[ptr->top];
        ptr->top--;
        return val;
        
    }
}
int main()
{
    struct stack *s = (struct stack *)malloc(sizeof(struct stack));
    s->size = 10;
    s->top = -1;
   
    //s->arr = (int *)malloc(s->size * sizeof(int)); //default val of top is -1 implies array is empty
    s->arr = (int*)malloc(s->size * sizeof(int));
    printf("The stack has been created");
    printf("\n%d", isFull(s));
    printf("\n%d", isEmpty(s));
    push(s,56);
    printf("\n%d", isFull(s));
    printf("\n%d", isEmpty(s));

    printf("\nPopped %d from the stack\n", pop(s));
    return 0;
}