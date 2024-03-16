#include<stdio.h>
#include<stdlib.h>

typedef struct  node{
    struct node * prev;
    int data;
    struct node * next;
} node_type;
void addNode(node_type **left, node_type **right){
    node_type *p;
    p = (node_type *) malloc(sizeof(node_type));
    if(p!=NULL){
        if(right==NULL){
            
        }
    }
    else {
        printf("not enough memory\n");
    }
}
int main(){
    node_type * left;
    node_type * right;
    right = left = NULL;
    int option ;
    do
    {
        printf("1 to add \n");
        printf("2 to add \n");
        printf("3 to add \n");
        printf("4 to add \n");
        scanf("%d",&option);
        switch (option)
        {
        case 1:
            addNode(&left, &right);
            break;
        case 2:
            deleteNode(&left, &right);
            break;
        case 3:
            displayNode(left, right);
            break;
        case 4:
            printf("exit successfully\n");
            break;
        default:
            break;
        }

    } while (option!=4);
    
    return 0;
}