#include<stdio.h>
#include<stdlib.h>


typedef struct node{
    int value;
    struct node* next;
}node;


struct node* head= NULL;
struct node* tail = NULL;

void enque(int data){
    node* temp = malloc(sizeof(node));
    temp->value = data;
    if (head == NULL){
        head = temp;
        tail =temp;
    }else {
        tail->next = temp;
        tail = temp;
    }
}

void deque(){
    if (head == NULL){
        printf ("Nothing to deque....");
    }else {
        node* temp = head;
        head = head->next;
        free(temp);
    }
}

void print_list(){
    node* temp = head;
    while (temp != NULL){
        printf ("%d, ", temp->value);
        temp = temp->next;
    }
    printf ("\n");

}



int main(){
    node* temp;

    for(int i=0; i < 19; i++){
        enque(i);
    }
    print_list();
    
    while(head != NULL){
        deque();
        print_list();
    }
    


}
