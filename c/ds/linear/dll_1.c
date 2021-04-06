#include<stdio.h>
#include<stdlib.h>


typedef struct node{
    int value;
    struct node* next;
    struct node* prev;
}dnode;

void print_list(dnode* head){
    dnode* temp = head;
    while(temp != NULL){
        printf ("%d - ",temp->value);
        temp = temp->next;
    }
    printf ("\n\n");
}

dnode* create_new_node(int value){
    dnode* result = (dnode*)malloc(sizeof(dnode));
    result->value = value;
    result->next = NULL;
    result->prev = NULL;
    return result;
}



dnode* insert_at_head(dnode** head, dnode* node_to_insert){
    node_to_insert->next = *head;
    if (*head != NULL){
    (*head)->prev = node_to_insert;

    }
    *head = node_to_insert;
    node_to_insert->prev = NULL;
    return node_to_insert;

}

void insert_after_node(dnode* node_to_insert_after, dnode* newnode){
    newnode->next = node_to_insert_after->next;
    if(newnode->next != NULL){
        newnode->next->prev = node_to_insert_after;
    }
    newnode->prev = node_to_insert_after;
    node_to_insert_after->next = newnode;
}

void remove_node(dnode** head, dnode* node_to_remove){
    if (*head == node_to_remove){
        *head = node_to_remove->next;
        if (*head != NULL){
        (*head)->prev = NULL;

        }
        return;
    }else{
        node_to_remove->prev->next=node_to_remove->next;
        if (node_to_remove->next != NULL){
            node_to_remove->next->prev = node_to_remove->prev;
        }
    }
    node_to_remove->next = NULL;
    node_to_remove->prev = NULL;
    return;
}

dnode* find_node(dnode* head, int value){
    dnode* temp = head;
    while(temp != NULL){
        if (temp->value == value) return temp;
        temp = temp->next;
    }
    return NULL;
}



int main(){

    dnode* head = NULL;
    dnode* temp;


    for (int i=0; i<25; i++){
        temp = create_new_node(i);
        insert_at_head(&head, temp);
    }
    temp = find_node(head, 13);
    printf ("Found node with value %d\n", temp->value);
    insert_after_node(temp, create_new_node(75));

    print_list(head);
    remove_node(&head, temp);
    remove_node(&head, head);
    print_list(head);

    return 0;

}
