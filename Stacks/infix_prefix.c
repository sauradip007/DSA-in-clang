#include <stdio.h>
#include <string.h>
#include <stdlib.h>
struct stack
{
    int size;
    int top;
    char *arr; // dynamically allocates array in the heap which holds stack
};
int isEmpty(struct stack *ptr)
{
    if (ptr->top == -1) // denotes stack is empty
    {
        return 1; // is true
    }
    else
    {
        return 0;
    }
}
int isFull(struct stack *ptr)
{
    if (ptr->top == ptr->size - 1) // denotes stack is full (size of array -1 is last index)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
void push(struct stack *ptr, int val) // pushes val in
{
    if (isFull(ptr))
    {
        printf("\nStack overflow");
    }
    else
    {
        ptr->top++;
        ptr->arr[ptr->top] = val;
    }
}
int pop(struct stack *ptr) // pushes val in
{
    if (isEmpty(ptr))
    {
        printf("\nStack underflow");
        return -1;
    }
    else
    {
        int val = ptr->arr[ptr->top];
        ptr->top--;
        return val;
    }
}
int peek(struct stack *ptr, int i)
{
    if (ptr->top - i + 1 < 0)
    {
        printf("\nNot valid");
        return -1;
    }
    else
    {
        return ptr->arr[ptr->top - i + 1];
    }
}
int stackTop(struct stack *ptr)
{
    return ptr->arr[ptr->top];
}
int stackBottom(struct stack *ptr)
{
    return ptr->arr[0];
}
int length(char a[])
{
    int count = 0;
    for (int i = 0; a[i] != '\0'; i++)
    {
        count++;
    }
    return count;
}
 void reversestring(char *a)
{
    int i = 0;
    int j = length(a) - 1;
    while (i < j)
    {
        char temp = a[i];
        a[i] = a[j];
        a[j] = temp;

        i++;
        j--;
    }
    
}
int precedence(char ch)
{
    if (ch == '*' || ch == '/')
    {
        return 3; // 3 denotes greater precedence(say)
    }
    else if (ch == '+' || ch == '-')
    {
        return 2;
    }
    else
    {
        return 0;
    }
}
int isOperator(char ch)
{
    if (ch == '+' || ch == '-' || ch == '*' || ch == '/')
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
char *infixToprefix(char *infix){
    infix = (char *)malloc(100 * sizeof(char));
    struct stack *s = (struct stack *)malloc(sizeof(struct stack));
    s->size = 100;
    s->top = -1;
    s->arr = (char *)malloc(s->size * sizeof(char));
    char *prefix = (char *)malloc(strlen(infix) + 1 * sizeof(char));
    //  reversestring(infix);
     int i = 0;
     int j = length(infix) - 1;
     while (i < j)
     {
         char temp = infix[i];
         infix[i] = infix[j];
        infix[j] = temp;

         i++;
         j--;
     }
    int p = 0; // traversing infix
    int q = 0; // traversing prefix
    while(infix[p] != '\0')
    {
        if(!isOperator(infix[i]))
        {
            prefix[q] = infix[p];
            p++;
            q++;
        }
        else{
            if(precedence(infix[p])> precedence(stackTop(s)))
            {
                push(s, infix[p]);
                p++;
            }
            else{
                prefix[q] = pop(s);
                q++;
            }
        }
    }
    while(!isEmpty(s))
    {
        prefix[q] = pop(s);
        q++;
    }
    prefix[q] = '\0';
//    reversestring(prefix);
// int r = 0;
// int s = length(prefix) - 1;
// while (r < s)
// {
//     char temp = prefix[r];
//     prefix[r] = prefix[s];
//     prefix[s] = temp;

//     r++;
//     s--;
// }
    return prefix;

}

    int main()
{
    char *infix = (char *)malloc(100 * sizeof(char));
    infix = "a - b";
    printf("\nThe prefix expression is : %s ", infixToprefix(infix));
}