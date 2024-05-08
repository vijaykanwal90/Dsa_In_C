#include <stdio.h>
#include <stdlib.h>
typedef struct binaryTree
{
    int data;
    struct binaryTree *left;
    struct binaryTree *right;
} node_type;
node_type * createNode(int data){
    node_type *newNode = (node_type *)malloc(sizeof(node_type));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;

}
node_type * insertNode(node_type **root, int data){
    if(*root == NULL){
        *root = createNode(data);
    }
    else if(data <= (*root)->data){
        insertNode(&(*root)->left, data);
    }
    else{
        insertNode(&(*root)->right, data);
    }
    return *root;

}
int main(){
    node_type *root = NULL;
    node_type *rt &root;
    printf("")

    return 0;
}