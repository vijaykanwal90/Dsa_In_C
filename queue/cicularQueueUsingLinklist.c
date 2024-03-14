#include<stdio.h>
#include<stdlib.h>
typedef struct node{
    int data;
    struct node *next;
} node_type;

void insert(node_type **, node_type **);
void delete(node_type **, node_type **);
void display(node_type *, node_type *);

int main(){
    node_type *front ;
    node_type *rear;
    front = rear = NULL;
    int option;
    do
    {
        printf("1 to insert\n");
        printf("2 to delete\n");
        printf("3 to display\n");   
        printf("4 to exit\n");
        scanf("%d", &option);
    switch(option){
        case 1:
             insert(&front, &rear);
             break;
        case 2:
                delete(&front , &rear);
                break; 
        case 3:
                display(rear , front);
                break;
        case 4:
                printf("exiting\n");
                break;
        default:
                printf("invalid option\n");
                break;
    }
    } while (option!=4);
    
    return 0;
}
void insert(node_type **front , node_type **rear){
    node_type * node;
    node = (node_type *)malloc(sizeof(node_type));
    node_type * last ;

    if(node !=NULL){
        printf("enter the data\n");
        scanf("%d", &node->data);
        if(*front==NULL){
            *front = (*rear )= node;
            last = node;
            last->next = node;
        }
        else{
            (*rear)->next = node;
            *rear = node;
            last = (*rear);
            last->next = (*front);

        }
    }
    else {
        printf("memory not available\n");
    }

}
void delete(node_type **front, node_type **rear){
    node_type *temp = *front;
    if((*front) == NULL){
        printf("queue is empty\n");
    }
    else if((*front) == (*rear)){
        printf("dequeued element is %d\n",temp->data);
        *front = *rear = NULL;
        free(temp);
    }
    else {
        printf("dequeued element is %d\n",temp->data);
        *front = temp->next;
        (*rear)->next = *front;
        free(temp);
    }


}
void display(node_type *rear,node_type * front){
node_type *temp;
temp = rear;
if(temp == NULL){
    printf("queue is empty\n");
}
else{
    do{
       printf("%d  ", temp->data);
        temp = temp->next;
    }
    while(temp!=rear);
    printf("\n");
}
}

