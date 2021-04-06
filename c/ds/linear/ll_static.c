#include<stdio.h>
#include<stdlib.h>


typedef struct node{
    int value;
    struct node* next;
}node;


void print_list(node* head){

    node* temp = head;
    while (temp != NULL){
        printf ("%d, ", temp->value);
        temp = temp->next;
    }

}

// add element in the beginning 
//
//
int main(){
    node n1,n2,n3;
    node* head;

    n1.value =45;
    n2.value =18;
    n3.value =92;

    head = &n3;
    n3.next = &n2;
    n2.next = &n1;
    n1.next = NULL;
    print_list(head);

    printf ("\n");
}
