#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;

} node_type;
void insert(node_type **left, node_type **right)
{
    node_type *p;
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
        if (*right == NULL)
        {

            (*left) = p;
            (*right) = p;
        }
        else
        {

            (*right)->next = p;
            *right = p;
        }
    }
}
void search(node_type **left, node_type **right)
{
    node_type *temp = (*left);

    printf("enter the key\n");
    int key;
    scanf("%d", &key);
    if (*left == NULL)
    {
        printf("no element is there\n");
    }
    else
    {
        node_type *temp = (*left);
        node_type *prev;

        while (temp != NULL && (temp->data != key))
        {
            prev = temp;
            temp = temp->next;
        }

        if (temp == NULL)
        {
            printf("element not found\n");
        }
        else
        {

            if (temp == (*left))
            {
                if ((*left)->next == NULL)
                {
                    (*right) = NULL;
                    (*left) = NULL;
                }
                else
                {
                    (*left) = temp->next;
                    free(temp);

                }
            }
            else if ((temp->next == NULL))
            {

                prev->next = NULL;
                (*right) = prev;
                free(temp);
            }
            else
            {

                prev->next = temp->next;
                free(temp);
            }
        }
    }
}
void displayNodes(node_type *left)
{
    node_type *temp = left;
    printf("displaying node\n");
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}
int main()
{
    node_type *p;

    node_type *left = NULL;
    node_type *right = NULL;

    int input;
    do
    {

        printf("Enter 1 to add node\n");
        printf("Enter 2 to delete node\n");

        printf("Enter 2 to display list\n");
        printf("Enter 3 to exit\n");
        scanf("%d", &input);

        switch (input)
        {
        case 1:
            insert(&left, &right);
            break;
        case 2:
            search(&left, &right);

            break;

        case 3:
            displayNodes(left);

            break;

        default:
            printf("invalid input\n");
            break;
        }
    } while (input != 4);
    return 0;
}