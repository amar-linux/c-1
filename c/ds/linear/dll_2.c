#include<stdio.h>
#include<stdlib.h>



typedef struct node{
    struct node* next;
    struct node* prev;
    int data;
}dnode;

dnode* head; // global head variables.
dnode* tail;


dnode* create_new_node(int x){
    dnode* result = (dnode*)malloc(sizeof(dnode));
    result->data = x;
    result->next = NULL;
    result->prev = NULL;
    return result;
}

void insert_at_head(int x){
    dnode* new_node = create_new_node(x); 
    if (head == NULL){
        head = new_node;
        tail = new_node;
        return;
    } 
    head->prev = new_node;
    new_node->next = head;
    head = new_node;

}

void insert_at_tail(int x){
    dnode* new_node = create_new_node(x); 
    if (head == NULL){
        head = new_node;
        tail = new_node;
        return;
    }
    tail->next = new_node;
    new_node->prev = tail;
    tail = new_node;

}

void print_list(){
    dnode* temp = head;
    while (temp != NULL){
        printf ("%d, ",temp->data);
        temp= temp->next;
    }
    printf ("\n");
}

void print_reverse_list(){
    dnode* temp = tail;
    while (temp != NULL){
        printf ("%d, ",temp->data);
        temp= temp->prev;
    }
    
    printf ("\n\n");


}


int main(){
   insert_at_head(2);print_list();print_reverse_list();
   insert_at_head(5);print_list();print_reverse_list();
   insert_at_head(7);print_list();print_reverse_list();
   insert_at_head(9);print_list();print_reverse_list();
   insert_at_tail(99);print_list();print_reverse_list();

}

