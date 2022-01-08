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
void push(struct stack* ptr, char val)//pushes val in
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
char pop(struct stack* ptr)//pushes val in
{
    if(isEmpty(ptr))
    {
        printf("\nStack underflow");
        return -1;
    }
    else{
        char val = ptr->arr[ptr->top];
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
int parenthesisMatch(char* exp)
{
    //creating and initialising stack
    struct stack* s = (struct stack *)malloc(sizeof(struct stack));
    s->size = 100;
    s->top = -1;
    s->arr = (char*)malloc(s->size * sizeof(char));

    for(int i = 0 ;  exp[i] != '\0'; i++)
    {
        if(exp[i] == '(')
        {
            push(s,'(');

        }
        else if (exp[i] == ')')
        {
            if(isEmpty(s))
            {
                return 0; //not balanced parenthesis 
            }
            pop(s);

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
  char* exp= (char*)malloc(100*sizeof(char));
  char* exp2= (char*)malloc(100*sizeof(char));
  exp = "{[()]}";
  exp2 = "{[(])}";
   //checks if stack empty
   if(parenthesisMatch(exp))
   {
       printf("\nYES");
   }
   else{
       printf("\nNO");
   }
     if(parenthesisMatch(exp))
   {
       printf("\nYES");
   }
   else{
       printf("\nNO");
   }
    return 0;
}