#include <stdio.h>
#include <stdlib.h>

struct Node {
    int x;
    struct Node* prev;
}*top,*nn,*temp;

void push( int y) {
    nn = (struct Node*) malloc(sizeof(struct Node));
    nn->x = y;
    nn->prev = top;
    top = nn;
}
int pop() {
    int e=0;
    if (top == NULL) 
        printf("Stack is empty\n");
    else{
    temp=top;
    e=top->x;
    top = top->prev;
    free(temp); }
return(e);
}

void display() {
    if (top == NULL) 
        printf("Stack is empty\n");
    temp=top;
    while (temp != NULL) {
        printf("%d ", temp->x);
        temp = temp->prev;
    }
}
int main() {
    struct Node* top = NULL;
    int ch, y;

    do {
        printf("\nChoice\n1. Push\n2. Pop\n3. Display\n0. Exit\n");
        scanf("%d", &ch);

        switch (ch) {
            case 1: printf("Enter data to push: ");
                scanf("%d", &y);
                push(y); break;
            case 2: printf("Deleted element = %d",pop()); break;
            case 3: display();break;
            case 0: printf("Byeee...\n"); break;
            default: printf("Invalid choice\n");
        }
    } while (ch != 0);
    return 0;
}
