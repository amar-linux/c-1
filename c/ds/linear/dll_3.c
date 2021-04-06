#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node* prev;
    struct node* next;
    
}dnode;

dnode* create_new_node(int x){
    dnode* result = (dnode*)malloc(sizeof(dnode));
    result->data = x;
    result->prev = result->next = NULL;
    return result;
}

dnode* insert_at_head(dnode** head, int x){
    dnode* newnode = create_new_node(x);
// head->next will save the pointer to head and head->prev will 
// save the pointer to tail.
    if ((*head)->next == NULL){
        (*head)->next = newnode;
        (*head)->prev = newnode;
        return (*head);
    }
    (*head)->next->prev = newnode;
    newnode->next = (*head)->next;
    (*head)->next = newnode;
    return (*head);

}

dnode* insert_at_tail(dnode** head, int x){
    dnode* newnode = create_new_node(x);
// head->next will save the pointer to head and head->prev will 
// save the pointer to tail.
    if ((*head)->next == NULL){
        (*head)->next = newnode;
        (*head)->prev = newnode;
        return (*head);
    }
    (*head)->prev->next = newnode;
    newnode->prev = (*head)->prev;
    (*head)->prev = newnode;
    return (*head);

}

void print_list(dnode* head){

    dnode* temp = head->next;
    
    while (temp != NULL){
        printf("%d, ", temp->data);
        temp = temp->next;
    }
    printf ("\n\n");

}

void print_reverse_list(dnode* head){

    dnode* temp = head->prev;
    
    while (temp != NULL){
        printf("%d, ", temp->data);
        temp = temp->prev;
    }
    printf ("\n\n");

}


int main(){
    dnode* head= malloc(sizeof(dnode));
    head->next = NULL;
    head->prev = NULL;

    print_list(head);
    head = insert_at_head(&head, 4);
    print_list(head);
    head = insert_at_head(&head, 5);
    head = insert_at_head(&head, 6);
    head = insert_at_head(&head, 7);
    head = insert_at_head(&head, 8);
    print_list(head);
    head = insert_at_tail(&head, 99);
    print_list(head);
    print_reverse_list(head);
   // print_reverse_list(head);


}
