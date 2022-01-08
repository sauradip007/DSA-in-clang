#include<stdio.h>
#include<stdlib.h>
struct Node{
    float coeff;
    int expo;
    struct Node* next;
};
struct Node* insert(struct Node* head , float co, int ex)
{
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    struct Node *newP = (struct Node *)malloc(sizeof(struct Node));
    newP->coeff = co;
    newP->expo = ex;
    newP->next = NULL;
    if(head == NULL || ex > head->expo)
    {
        newP->next = head;
        head = newP;
        }
        else{
            temp = head;
            while(temp->next != NULL && temp->next->expo >= ex)
            {
                temp = temp->next;//mistakepossible
            }
            newP->next = temp->next;
            temp->next = newP;
        }
        return head;

}
struct Node* create(struct Node* head)
{
    int n,i;
    float coeff;
    int expo;
    printf("\nEnter the no of terms : ");
    scanf("%d", &n);
    for(i = 0 ; i < n; i++)
    {
        printf("\nEnter the coefficient for term %d : ", i+1);
        scanf("%f", &coeff);
        printf("\nEnter the exponent for term % d : ",i+1);
        scanf("%d", &expo);
        head = insert(head,coeff,expo);
    }
    return head;
}
void print(struct Node* head)
{
    if(head == NULL)
    printf("\nNo Polynomial");
    else{
        struct Node *temp = head;
        while(temp != NULL)
        {
            printf("(%.1fx^%d)" , temp->coeff, temp->expo);
            temp = temp->next;
            if(temp!=NULL)
            {
                printf(" + ");
            }else{
                printf("\n");
            }
        }
    }
}
void polyAdd(struct Node* head1 , struct Node* head2)
{
    struct Node *ptr1 = (struct Node *)malloc(sizeof(struct Node));
    struct Node *ptr2 = (struct Node *)malloc(sizeof(struct Node));
    struct Node *head3 = (struct Node *)malloc(sizeof(struct Node));
    while(ptr1 != NULL && ptr2 !=NULL)
    {
        if(ptr1->expo == ptr2->expo)
        {
            head3 = insert(head3 , ptr1->coeff + ptr2->coeff, ptr1->expo);
            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
        }
        else if (ptr1->expo > ptr2->expo)
        {
            head3 = insert(head3 , ptr1->coeff, ptr1->expo);
            ptr1 = ptr1->next;
        }
        else if (ptr1->expo < ptr2->expo)
        {
            head3 = insert(head3, ptr2->coeff, ptr2->expo);
            ptr2 = ptr2->next;
        }
    }
        while(ptr1 != NULL)
        {
            head3 = insert(head3, ptr1->coeff , ptr1->expo);
        }
        while (ptr2 != NULL)
        {
            head3 = insert(head3, ptr2->coeff, ptr2->expo);
        }
        printf("\nAdded Polynomial is : ");
        print(head3);
    }
int main()
{
    struct Node *head1 = (struct Node *)malloc(sizeof(struct Node));
    head1 = NULL;
    struct Node *head2 = (struct Node *)malloc(sizeof(struct Node));
    head2 = NULL;
    printf("\nEnter first poly : ");
    head1 = create(head1);
    printf("\nEnter second poly : ");
    head2 = create(head2);
    polyAdd(head1,head2);
    return 0;

}