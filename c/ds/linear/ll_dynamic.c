#include<stdio.h>
#include<stdlib.h>


typedef struct node{
    int value;
    struct node* next;
}node;

node* add_node(node** head, int data){
    node* temp;
    temp =(node*)malloc(sizeof(node));
    temp->value = data;
    temp->next = *head;
    *head = temp;
    return (*head);

    
}
void print_list(node** head){
    node* temp = *head;
    while (temp != NULL){
        printf ("%d, ", temp->value);
        temp = temp->next;
    }
    printf ("\n");
}

node* delete_node(node** head, int position){
    node* temp = *head;
    if (position ==1){
        *head = temp->next;
        free(temp);
    }
    int i=0;
    while (i != (position-1) && temp->next != NULL){
        temp = temp->next;
        i++;
    }
    if (temp->next != NULL){
        node*temp2 = temp->next;
        temp->next = temp->next->next;
        free(temp2);
    }
    return (*head);
}

node* add_node_in_middle(node** head, int position, int data){
    node* temp = *head;
    
    if (position ==0){
        temp = add_node(head,data);
        return temp;
    }
    int i=0;
    while (i != position-1 && temp->next){
        temp=temp->next;
        i++;
    }if (temp->next != NULL){
        node* temp2 = (node*) malloc(sizeof(node));
        temp2->value = data;
        temp2->next = temp->next;
        temp->next = temp2;

    }
    return (*head);
}

int main(){
     node* head = NULL;

    for (int i=0; i<9; i++){
        head = (node*)add_node(&head, i );
    }
    print_list(&head);
    head = (node*)delete_node(&head, 6);
    print_list(&head);
    head = (node*)add_node_in_middle(&head, 5,92);
    print_list(&head);


}
