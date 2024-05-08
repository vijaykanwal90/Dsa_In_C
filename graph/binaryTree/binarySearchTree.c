#include <stdio.h>
#include <stdlib.h>
typedef struct binaryTree
{
    int data;
    struct binaryTree *left;
    struct binaryTree *right;
} node_type;


node_type * createNode(  int data)
{
    node_type *node;
    node = (node_type *)malloc(sizeof(node_type));
  

    node->data = data;
    node->left = NULL;
    node->right = NULL;
   

      
        
   
return node;
}
node_type *  insert(node_type *root, int data)
{
    if (root == NULL)
    {
        root = createNode(data);
    }
    else if(root->data > data){

      root->left =   insert(root->left,data);
    }else 
    {
       root->right =  insert(root->right,data);

        
    }
    return root;
   
}
void display(node_type* root){
   if(root==NULL){
    return ;
   }
//    inorder  traversel


    display(root->left);
    printf("%d\n",root->data);

    display(root->right);


}
int main()
{
    node_type *root = NULL;
    node_type *rt = root;
   root =  insert(root, 100);
   root =  insert(root, 50);
   root =  insert(root, 700);
   root =  insert(root, 200);
   root =  insert(root, 90);
   root =  insert(root, 11);
   
   display(root);
   

    return 0;
}
