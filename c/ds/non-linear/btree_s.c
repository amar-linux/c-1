#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>


typedef struct node{
    int data;
    struct node* left;
    struct node* right;
}node_t;

//node_t* root;// to store the address of the tree.
//thi is pointer to root and not root

node_t* create_new_node(int value){
    node_t* newnode = (node_t*)malloc(sizeof(node_t));
    newnode->data = value;
    newnode->right = NULL;
    newnode->left = NULL;
    return newnode;
}

void insert_node(node_t** root, int value){
    if (*root == NULL){ // empty tree .``
        *root = create_new_node(value);
    }else if ( value <= (*root)->data ){
        insert_node(&(*root)->left, value);

    }else {
        insert_node(&(*root)->right, value);

    }

}

bool search_node(node_t* root, int data){
    if (root == NULL)return false;
        else if (root->data == data) return true;
        else if (root->data <= data) return search_node(root->left, data);
        else return search_node(root->right, data);


    
}


int main(){
    node_t* root = NULL;// creating newnode
    int value;

    insert_node(&root,15);
    insert_node(&root,10);
    insert_node(&root,20);
    insert_node(&root,33);
    printf ("Enter the number to be searched:");
    scanf("%d",&value);
    bool result = search_node(root, value);
    if (result == true ){
        printf ("Number found");
    }else{
        printf ("Number not found");

    }
    printf ("\n\n");




}
