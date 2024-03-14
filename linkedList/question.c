#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;

} node_type;

void displayNodes(node_type *left)
{
    node_type *temp = left;
    printf("displaying node\n");
    while (temp != NULL)
    {
        printf("%d\n", temp->data);
        temp = temp->next;
    }
    free(temp);
}
int main()
{
    node_type *p;

    node_type *left = NULL;
    node_type *right = NULL;

    int input;
    while (input != 3)
    {

        printf("Enter 1 to add node\n");
        printf("Enter 2 to display list\n");
        printf("Enter 3 to exit\n");
        scanf("%d", &input);

        switch (input)
        {
        case 1:
            p = (node_type *)malloc(sizeof(node_type));
            if (p == NULL)
            {
                printf("space is not empty\n");
            }
            else
            {
                int value;
                printf("enter the data\n");
                scanf("%d", &value);
                p->data = value;
                p->next = NULL;
                if (left == NULL && right == NULL)
                {
                    // first node
                    left = p;
                    right = p;
                }
                else
                {

                    right->next = p;
                    right = p;
                }
            }
            break;
        case 2:
            displayNodes(left);
            break;

        case 3:
            break;

        default:
            printf("invalid input\n");
            break;
        }
    }

    return 0;
}