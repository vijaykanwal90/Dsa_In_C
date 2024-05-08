#include<stdio.h>
#include<stdlib.h>
typedef struct Node{
    int data;
    struct Node *next;
}node_type;
void   insert(node_type **top){
    node_type *node ;
    node = (node_type *) malloc(sizeof(node_type));
    if(node==NULL){
        printf("memory not available\n");
    }
    else {
        printf("enter the data for node\n");
        scanf("%d",&node->data);
        node->next= NULL;
        
        if((*top)==NULL){
            (*top) = node;


        }
        else {
            node_type *temp = (*top);
            while(temp->next!=NULL){
                temp = temp->next;
            }
            temp->next=node;

        }
    }

}
void display(node_type *p){
    node_type *temp = p;
    while(temp!=NULL){
        printf("%d ",temp->data);
        temp = temp->next;
    }
}
void displayAlternateNode(node_type*p){
    node_type *temp = p;
    int count = 1;
     while(temp!=NULL){
        if(count%2!=0){
        printf("%d ",temp->data);

        }
        count++;
        temp = temp->next;
    }
}
void merge(node_type **p,node_type **m){
    node_type *temp = (*p);
    while(temp->next !=NULL){
        temp = temp->next;
    }
    if((*p)!=NULL && (*m)!=NULL){
        temp->next= (*m);
    }
    }
int main(){

    node_type * p=NULL;
    node_type * m=NULL;

    int num ;
    printf("enter how many numbers you want to insert in linkedlist\n");
    scanf("%d",&num);

    for(int i=0;i<num;i++){
      insert(&p);

    }
   for(int i=0;i<num;i++){
      insert(&m);

    }


    display(p);
    display(m);

    printf("\n");
    merge(&p,&m);
    display(p);

    // displayAlternateNode(p);
    return 0;
}