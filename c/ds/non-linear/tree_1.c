#include<stdio.h>
#include<stdlib.h>
#include<string.h>


typedef struct node{
    int data;
    struct node* left;
    struct node* right;
}node_t;

node_t* root = NULL;

node_t* create_node(int value){
    node_t* result = (node_t*)malloc(sizeof(node_t));
    result->data = value;
    result->left= result->right = NULL;
    return result;
}


int add_node(int value){
    node_t* temp = create_node(value);
    if (root == NULL){
        root = temp;
        return 0;
        
    }

    node_t* temp1;
    while (temp1 != NULL){
        if (temp1->data > value){
            if (temp1->right == NULL){
                temp1->right = temp;
                return 0;
            }temp1 = temp1->right;
        }else{
            if (temp1->left == NULL){
                temp1->left = temp;
                return 0;
            }temp1 = temp1->left;
        }

    }
    return 0;
}

void print_tree(){
    node_t* temp = root;

    if (temp  == NULL){
        return;
    }
    print_tree(temp->right);
    print_tree(temp->left);
    printf("%d ", temp->data);

}


int main(){


    char s[50];
    int input;
    while (1){
        printf ("Select option: ");
        printf ("1: adding number 2: deleting number 3: printing the tree");

        fgets(s, 50, stdin);
        input = atoi(s);

        switch(input)
        {
            case 1:
                printf("Enter the elemnet to be added: ");
                fgets(s, 50, stdin);
                input = atoi(s);
                add_node(input);
                break;
            case 2:
                printf ("\n\n\n\n");
                break;
            case 3:
                printf ("Printing the three:");
                print_tree();
                break;
            case 4:
                return 0;


        }


    }
}
