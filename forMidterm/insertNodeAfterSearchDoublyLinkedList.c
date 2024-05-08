#include<stdio.h>
#include<stdlib.h>

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
        if ((*right) == NULL && (*right) == NULL)
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
void display(node_type*front){
    node_type *temp = front;
    while(temp!=NULL){
        printf("%d ",temp->data);
        temp = temp->next;
    }
}
void search(node_type **front , node_type **rear, int key){
    // three conditions if key found at first , middle or last
    node_type *temp = *front;
    while(temp!=NULL && temp->data!=key){
        
        temp = temp->next;
    }
    if(temp==NULL){
        printf("key not found\n");
    }
    else {
    if(temp==*front){
        if(temp->next ==NULL){
            // means single element is there
            *front = NULL;
            *rear = NULL;

        }
        else {
            *front = (*front)->next;
            (*front)->prev=NULL;
            free(temp);
        }

    }
    else if(temp->next ==NULL){
        // key found at last node
        (*rear) = temp->prev;

        temp->prev->next = NULL;
        free(temp);

    }
    else {
        // key found at middle
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;

    }
    }
}
int main(){
    node_type * front = NULL ;
    node_type * rear  = NULL;

      int num ;
    printf("enter how many numbers you want to insert in linkedlist\n");
    scanf("%d",&num);

    for(int i=0;i<num;i++){
      addNode(&front,&rear);

    }
    display(front);
    search(&front,&rear,15);
    printf("\n");
    display(front);

    return 0;
}