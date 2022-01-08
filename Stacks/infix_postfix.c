#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct stack{
    int size;
    int top;
    char* arr;//dynamically allocates array in the heap which holds stack
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
int stackTop(struct stack* ptr)
{
    return ptr->arr[ptr->top];
}
int stackBottom(struct stack* ptr)
{
    return ptr->arr[0];
}
int precedence(char ch)
{
    if(ch == '*' || ch == '/')
    {
        return 3; //3 denotes greated precedence(say)
    }
    else if (ch == '+' || ch == '-')
    {
        return 2;
    }
    else{
        return 0;
    }

}
int isOperator(char ch)
{
    if(ch == '+' || ch == '-' || ch =='*' || ch == '/')
    {
        return 1;
    }
    else{
        return 0;
    }

}
char* infixTopostfix(char* infix ){
    struct stack* s = (struct stack*)malloc(sizeof(struct stack));
    s->size = 100;
    s->top = -1;
    s->arr = (char*)malloc(s->size* sizeof(char));
    char* postfix = (char*)malloc(strlen(infix)+1* sizeof(char)); //size of postfix expression will be strlen + 1 as it has to incorporate '\0' at the end since it is a character array
    int i = 0; //traversing from infix
    int j = 0; //adds to postfix final expression
    while(infix[i] != '\0')
    {
        if(!isOperator(infix[i]))
        {
            postfix[j] = infix[i];
            j++;
            i++;
        }
        else{
            if(precedence(infix[i])> precedence(stackTop(s)))
            {
                push(s,infix[i]);
                i++;
            }
            else{
                postfix[j] = pop(s); //if precedence in stack top is more , it is popped from the stack and added to postfix expression
                j++;
            }   
        }

    }
    while(!isEmpty(s))
    {
        postfix[j] = pop(s); //remaining elements in stack is popped into postfix expression
        j++;
    }
    postfix[j] = '\0'; //after elements are popped , the array will be terminated by a null character
    return postfix;
}

int main()
{
    char* infix = (char*)malloc(100*sizeof(char));
    infix = "3 + 8 / 4 / 2 - 7";
    printf("\nThe postfix expression is : %s ", infixTopostfix(infix));
   
}