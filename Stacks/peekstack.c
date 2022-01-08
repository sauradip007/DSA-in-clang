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
        ptr->top++;//incrementing top
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
int peek(struct stack* ptr, int i)
{
    if(ptr->top-i+1 < 0){
        printf("\nNot valid");
        return -1;
    }
    else{
        return ptr->arr[ptr->top-i+1];
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
    push(s,23);
    push(s,99);
    push(s,17);
    push(s,8);
    push(s,1);
    push(s,77);
    push(s,23);
    push(s,11);
    push(s,13);
    //printing values from the stack
    for(int i = 1 ; i <= s->top+1 ;i++){
    printf("\nThe value at index %d is %d ",i,peek(s,i));
    }
    return 0;
}