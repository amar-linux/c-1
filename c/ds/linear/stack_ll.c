#include<stdio.h>
#include<stdbool.h>
#include<limits.h>
#include<stdlib.h>

#define STACK_LEN 5
#define STACK_EMPTY INT_MIN
#define EMPTY (-1)


typedef struct node{
    int value;
    struct node* next;
}node;

node* head = NULL;


void print_reverse(node* head){
    node*  temp1 = head;
    //base case,
    if (temp1 == NULL)
        return;
    // print the list after node.
    print_reverse(temp1->next);
    //in last iterattion print_reverse(NULL);
    //the function will return
    //control will come back again to the print_reverse 
    //and execution of next line follows.

    //After everything else is printed print head.
    printf ("%d ", temp1->value);

    
}

void push (int data){

    node* temp = (node*)malloc (sizeof(node));
    temp->value = data;
    temp->next = head;
    head = temp;
    
    
}
void pop(){

    node* temp = head;
    head = head->next;
    free(temp);
}

void print_list(){
    node* temp = head;
    while (temp != NULL){
        printf ("%d, ",temp->value);
        temp=temp->next;
    }
    printf ("\n");
}

int main(){


    printf ("Pushing the elenments on to the stack ......\n");
    for (int i=0; i < 10; i++){
        push(i);
        print_list();
    }
    printf ("\n\n");
    print_reverse(head);
    printf ("\n\n");
    printf ("Poping the elenments on to the stack ......\n");
    node* temp = head;
    //pop will change the head element.
    //we can check for head to be NULL. 
    //it only makes sense to copy head to a temp variable when you want to modify it 
    //for traversing.
    while (temp != NULL){
        pop();
        print_list();
    }



}
