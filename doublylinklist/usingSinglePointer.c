#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    struct node *prev;
    int data;
    struct node *next;
} node_type;
void addNode(node_type **head)
{
    node_type *p;
    p = (node_type *)malloc(sizeof(node_type));
    if (p != NULL)
    {
        printf("Enter the data\n");
        scanf("%d", &p->data);
        p->next = NULL;
        if ((*head) == NULL )
        {
            (*head) = p;
           
            (*head)->prev = NULL;
        }
        else
        {
            node_type *temp = (*head);
            while(temp->next!=NULL){
                temp = temp->next;
            }
                p->prev= temp;
                temp->next= p;
                temp = p;
        }
    }
    else
    {
        printf("not enough memory\n");
    }
}
void leftToRight(node_type *left)
{
    node_type *temp = left;
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}
void rightToLeft(node_type *right)
{
    node_type *temp = right;
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->prev;
    }
    printf("\n");
}
int main()
{
    node_type *head;
    
    head = NULL;
    int option;
    do
    {
        printf("1 to add \n");
        printf("2 to display left to right \n");
        printf("3 to display right to left \n");
        printf("4 to exit \n");
        scanf("%d", &option);
        switch (option)
        {
        case 1:
            addNode(&head);
            break;
        case 2:
            leftToRight(head);
            break;
        case 3:
            rightToLeft(head);

            break;
        case 4:
            printf("exit successfully\n");
            break;
        default:
            break;
        }

    } while (option != 4);

    return 0;
}