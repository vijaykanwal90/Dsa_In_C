#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    struct node *prev;
    int data;
    struct node *next;
} node_type;
void addNode(node_type **start)
{
    node_type *p;
    node_type *temp = p;
    p = (node_type *)malloc(sizeof(node_type));
    if (p != NULL)
    {
        printf("Enter the data\n");
        scanf("%d", &p->data);
        p->next = NULL;
        // p->prev = NULL;

        if ((*start) == NULL)
        {
            (*start) = p;
            temp = p;
            // (*start)->prev = NULL;
            
        }
        else
        {
            p->prev = temp;
            (*start)->next = p;
            // p->next = NULL;
        }
    }
    else
    {
        printf("not enough memory\n");
    }
}
void leftToRight(node_type *start)
{
    node_type * temp = start;
    while (temp!= NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}
void search(node_type ** start){

}
void delete(node_type ** start){

}
int main()
{
    node_type *start;
    
    start =  NULL;
    int option;
    do
    {
        printf("1 to add \n");
        printf("2 to search the key \n");
        printf("3 to display right to left \n");
        printf("4 to exit \n");
        scanf("%d", &option);
        switch (option)
        {
        case 1:
            addNode(&start);
            break;
        case 2:
            // search(start);
            leftToRight(start);
            break;
        
        case 4:
            printf("exit successfully\n");
            break;
        default:
            printf("invalid input\n");

            break;
        }

    } while (option != 4);

    return 0;
}