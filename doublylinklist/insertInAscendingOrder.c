#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    struct node *prev;
    int data;
    struct node *next;
} node_type;
void addNode(node_type **left, node_type **right)
{
    node_type *p;
    p = (node_type *)malloc(sizeof(node_type));
    if (p != NULL)
    {

        
        printf("Enter the data\n");
        scanf("%d", &p->data);
        if ((*right) == NULL)
        {
            (*left) = p;
            (*right) = p;
            
        }
        else
        {

            if (p->data < (*left)->data)
            {
                p->next = (*left);
                (*left)->prev = p;
                (*left) = p;
            }
            else if (p->data > (*right)->data)
            {
                (*right)->next = p;
                p->prev = (*right);
                (*right) = p;
                (*right)->next = NULL;
            }
            else
            {
                node_type *temp = (*left);
                while (temp != NULL)
                {
                    if (p->data < temp->data)
                    {
                printf("%d", temp->data);

                        (temp->prev)->next = p;
                        p->next = temp;
                        p->prev = temp->prev;

                        temp->prev = p;

                        break;
                    }

                    temp = temp->next;
                }
            }
        }
    }
    else
    {
        printf("not enough memory\n");
    }
}
void pringInAscendingOrder(node_type *left)
{
    node_type *temp = left;
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}
void pringInDescendingOrder(node_type *right)
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
    node_type *left;
    node_type *right;
    right = left = NULL;
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
            addNode(&left, &right);
            break;
        case 2:
            pringInAscendingOrder(left);
            break;
        case 3:
            pringInDescendingOrder(right);

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