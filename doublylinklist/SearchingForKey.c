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
        p->next = NULL;
        if ( (*right) == NULL)
        {
            (*left) = p;
            (*right) = p;
            (*left)->prev = NULL;
        }
        else
        {

            (*right)->next = p;
            p->prev = (*right);
            (*right) = p;
        }
    }
    else
    {
        printf("not enough memory\n");
    }
}
void search(node_type ** start ){
    printf("enter the key you want to search in \n");
    int key;
    scanf("%d",&key);
    if((*start)==NULL){
        printf("no element is there\n");

    }
    else {

        // here we have to consider  three conditions
        // 1. key found at the first  node
        // 2. key found at the last node
        // 3. key found in between the elements
        node_type *temp = (*start);

        while(temp!=NULL && temp->data !=key ){
       
        temp = temp->next;
        }
        if(temp==NULL){
            printf("key not found\n");
        }
        else{
            
            if( temp == (*start)){
                if((*start)->next == NULL){
                    (*start) = NULL;
                }
                else {
                (*start) = temp->next;
                (*start)-> prev = NULL;

                free(temp);
                }
            }
           else if( temp->next == NULL){
               (temp->prev)->next = NULL;
               free(temp);
            }
            else{
               (temp->prev)->next = temp->next;
               (temp->next)->prev = temp->prev;
            }
        }

      }
    }

void leftToRight(node_type *left)
{
    
    node_type *temp = left;
    if(temp==NULL){
        printf("no element is there\n");
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
    node_type *left;
    node_type *right;
    right = left = NULL;
    int option;
    do
    {
        printf("1 to add \n");
        printf("2 to display  \n");
        printf("3 tosearch\n");
        printf("4 to exit \n");
        scanf("%d", &option);
        switch (option)
        {
        case 1:
            addNode(&left, &right);
            break;
        case 2:
            leftToRight(left);
            break;
        case 3:
            search(&left );

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