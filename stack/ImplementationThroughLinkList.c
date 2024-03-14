#include <stdio.h>
#include <stdlib.h>
typedef struct Node
{
    int data;
    struct Node *next;

} node_type;

node_type * push(node_type *top)
{
    node_type *node = (node_type *)malloc(sizeof(node_type));
    // int value;
    printf("Enter the data for node");
    if (node == NULL)
    {
        printf("Space is not available\n");
    }
    else
    {

        scanf("%d", &node->data);
        
        node->next = NULL;

        if (top == NULL)
        {

            top = node;
            
            return top;
        }
        else
        {
            node->next = top;
            top = node;
            
            return top;
        }
    }
}

node_type * pop(node_type *top)
{
    node_type *temp = top;
    if (temp == NULL)
    {
        printf("Link list is empty\n");
        return temp;
    }
    else
    {
        printf("the data to be poped out is %d\n", temp->data);
        temp= top->next;

        return temp;
    }
}
void display(node_type *top)
{

    node_type *temp = top;
    
   
    if (temp == NULL)
    {
        printf("stack is empty now");
    }
    while (temp != NULL)
    {
       
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main()
{
    // node_type *node;
    node_type *top;
    top = NULL;
    int option;

    do
    {
        printf("1 to push\n");
        printf("2 to pop function\n");
        printf("3 to display nodes\n");
        printf("4 to exit the menu\n");
        scanf("%d", &option);

        switch (option)
        {
        case 1:
            top = push(top);
            
            break;
        case 2:
           top =  pop(top);
            break;
        case 3:
            display(top);
            break;
        default:
            break;
        }

    } while (option != 4);

    return 0;
}