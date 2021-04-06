#include<stdio.h>
#include<stdbool.h>
#include<limits.h>

#define STACK_LEN 5
#define STACK_EMPTY INT_MIN
#define EMPTY (-1)

int mystack[STACK_LEN];
int top = EMPTY;


bool push(int value){
    if (top >= (STACK_LEN -1))return false;

    top++;
    mystack[top] = value;
    return true;
}

int pop (){
    if (top == EMPTY) return STACK_EMPTY;

    int result = mystack[top];// to get the item that is popped.
    top--;
    return result;
}




int main(){
    push(56);
    push(78);
    push(29);
    push(32);
    push(7);
    push(8);


     while (top!= EMPTY ){
        int t = pop();
        printf ("%d, ",t);
    }
     printf ("\n");

}
