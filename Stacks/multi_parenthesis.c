#include<stdio.h>
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
char stackTop(struct stack* ptr)
{
    return ptr->arr[ptr->top];
}
char stackBottom(struct stack* ptr)
{
    return ptr->arr[0];
}
int match(char a , char b)
{
    if(a == '{' && b == '}')
    {
        return 1;
    }
    if(a == '(' && b == ')')
    {
        return 1;
    }
    if(a == '[' && b == ']')
    {
        return 1;
    }
    return 0;
}
int parenthesisMatch(char* exp)
{
    //creating and initialising stack
    struct stack* s = (struct stack *)malloc(sizeof(struct stack));
    s->size = 100;
    s->top = -1;
    s->arr = (char*)malloc(s->size * sizeof(char));
    char pop_ch;
        for(int i = 0 ;  exp[i] != '\0'; i++)
    {
        if(exp[i] == '(' || exp[i] == '{' || exp[i] == '[')
        {
            push(s,exp[i]);

        }
        else if (exp[i] == ')'|| exp[i] == '}' || exp[i] == ']')
        {
            if(isEmpty(s))
            {
                return 0;
            }
            pop_ch = pop(s);
            if(!match(pop_ch,exp[i]))
            {
                return 0;

            }
        }
    }
   if(isEmpty(s)) //checks if stack is empty at the end of expression
    {
        return 1;

    }
    else{
        return 0;
    }

    }
int main()
{
struct stack *s = (struct stack *)malloc(sizeof(struct stack));
char* exp= (char*)malloc(100*sizeof(char));
exp = "{[()]}";
  

   if(parenthesisMatch(exp))
   {
       printf("\nYES");
   }
   else{
       printf("\nNO");
   }
  
    return 0;
}