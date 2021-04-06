#include<stdio.h>
#include<stdlib.h>



typedef struct node{
    struct node* left;
    struct node* right;
    int data;
}node_t;


node_t* create_node(int value){
    node_t* result = malloc(sizeof(node_t));
    if (result != NULL){
        result->left = result->right = NULL;
        result->data = value;
    }
    return result;
}

void print_tabs(int numtabs){
    for (int i=0; i< numtabs; i++){
        printf ("\t");
    }
}



//postorder trversal;
void print_tree_rec(node_t* root, int level){
    if (root ==NULL){
    print_tabs(level);
        printf ("-----Empty-----\n\n");
        return;
    }

    print_tabs(level);
    printf ("value = %d\n", root->data);
    print_tabs(level);
    printf ("left\n");
    
    print_tree_rec(root->left, level+1);
    print_tabs(level);
    printf("right\n");
    
    print_tree_rec(root->right, level+1);
    print_tabs(level);
    printf("done\n");
}

void print_tree(node_t* root){
    print_tree_rec(root,0);

}

int main(){

    node_t* n1 = create_node(10);
    node_t* n2 = create_node(11);
    node_t* n3 = create_node(12);
    node_t* n4 = create_node(13);
    node_t* n5 = create_node(14);

    n1->left = n2;
    n1->right = n3;
    n3->left = n4;
    n4->left = n5;

    print_tree(n1);


}
