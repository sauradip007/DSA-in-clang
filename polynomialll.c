#include <stdio.h>
#include <stdlib.h>
struct Node
{
   float coefficient;
   int exponent;
   struct Node* next;
};

struct Node* insert(struct Node* head,float co , int ex)
{
    struct Node *temp = (struct Node*)malloc(sizeof(struct Node));
    struct Node *newP = (struct Node *)malloc(sizeof(struct Node));
    newP->coefficient = co;
    newP->exponent = ex;
    newP->next = NULL;
    if(head == NULL || ex > head->exponent)
    {
        newP->next = head;
        head = newP;
    }
    else{
        temp = head;
        while(temp->next != NULL && temp->next->exponent > ex)
        {
            temp = temp->next;
        }
        newP->next = temp->next;
        temp->next = newP;
    }
    return head;

}
struct Node* create(struct Node* head)
{
    int n;
    int i;
    float coefficient;
    int exponent;

    printf("\nEnter the number of terms : ");
    scanf("%d", &n);//no of terms in polynomial 
    for(i = 0 ; i < n; i++)
    {
        printf("Enter the coefficient for term %d : ", i+1);
        scanf("%f", &coefficient);
        printf("Enter the exponent for term %d :  ", i+1);
        scanf("%d", &exponent);
        head = insert(head,coefficient,exponent);
    }
    return head;
}
void print(struct Node *head)
{
    if (head == NULL)
    {
        printf("\nNo Polynomial");
    }
    else
    {
        struct Node *temp = head;
      
        while (temp != NULL)
        {
            printf("(%.1fx^%d)", temp->coefficient, temp->exponent);
            temp = temp->next;

            if (temp != NULL)
            {
                printf(" + ");
            }
            else
            {
                printf("\n");
            }
        }
    }
}

int main()
{
    struct Node* head = (struct Node*)malloc(sizeof(struct Node));
    printf("\nEnter the polynomial : ");
    head = create(head);
    print(head);
    return 0;
}