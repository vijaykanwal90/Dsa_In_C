#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    int data;
    struct node *next;
} node_type;
void push(node_type **);
void pop(node_type **);
void display(node_type *);
int main()
{
    node_type *top;
    top = NULL;
    int option;
    do
    {
        printf("1 for push operation\n");
        printf("2 for pop operation\n");
        printf("3 for display operation\n");
        printf("4 for exit\n");
        scanf("%d", &option);
        switch (option)
        {
        case 1:
            push(&top);
            break;
        case 2:
            pop(&top);
            break;
        case 3:
            display(top);
            break;

        case 4:
            printf("exiting the program\n");
            break;
        default:

            printf("invalid input\n ");
            break;
        }
    } while (option != 4);

    return 0;
}
void push(node_type **tp)
{
    node_type *node;
    node = (node_type *)malloc(sizeof(node_type));

    if (node != NULL)
    {

        printf("Enter the value\n");
        scanf("%d", &node->data);
        node->next = *tp;
        *tp = node;
    }
    else
    {
        printf("memory is not allocated\n");
    }
}

void pop(node_type **tp)
{
    node_type *temp = *tp;

    if (temp == NULL)
    {
        printf("stack is empty\n");
    }
    else
    {
        printf("the data to be poped out is %d\n", temp->data);
        *tp = (*tp)->next;
        free(temp);
    }
}
void display(node_type *top)
{
    node_type *temp = top;
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}
