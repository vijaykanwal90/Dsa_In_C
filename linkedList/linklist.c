#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;

} node_type;


void displayNodes(node_type *left)
{    
    node_type * temp = left;
    printf("displaying node\n");
    while (temp != NULL)
    {
        printf("%d\n", temp->data);
        temp = temp->next;
    }
//   free(temp);
}

node_type * addNode(node_type *left, node_type *right)
{
    
    int dt;
    node_type *a = (node_type *)malloc(sizeof(node_type));

    printf("enter the data\n");
    scanf("%d", &dt);
    a->data = dt;
    a->next = NULL;
    if (left == NULL)
    {
// first node 
        left = a;
        right = a;
        // return left;
    }
    else
    {
        // after first node
        // left->next = right;
        right->next = a;
        right = a;
        // a->next = NULL;
    }
    // displayNodes(left);
    node_type *temp = left;
     while (temp != NULL)
    {
        printf("%d\n", temp->data);
        temp = temp->next;
    }
return left;
}


int main()
{

     node_type *left= NULL;
     node_type *right = NULL;
     int i;
    while (i!= 3)
    {

        printf("Enter 1 to add node\n");
        printf("Enter 2 to display list\n");
        printf("Enter 3 to exit\n");
        scanf("%d", &i);

        switch (i)
        {
        case 1:
           left =  addNode(left, right);
            break;
        case 2:
            // printf("%p",left);
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