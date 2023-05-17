#include<stdio.h>
#include<stdlib.h>
//stack adt
#define MAX_SIZE 100

int Stack[100],top=-1;

int isEmpty() {
    return (top == -1);
}

int isFull() {
    return (top == MAX_SIZE - 1);
}

void push(int item) {
    Stack[++top] = item;
}

int pop() {   
    return Stack[top--];
}

void display(){
    for(int i=top;i>-1;i--)
    printf("%d\n",Stack[i]);
}
int main()
{
    int x=1,y;
    while(x!=0){
        printf("\n1.Push\n2.Pop\n3.isFull\n4.isEmpty\n5.Display\n");
        scanf("%d",&x);
        switch(x)
        {
            case 1:scanf("%d",&y); 
            push(y);break;
            case 2: printf("%d",pop());break;
            case 3: printf("%d",isFull());break;
            case 4: printf("%d",isEmpty());break;
            case 5: display();break;
        }
    }    
    return 0;
}
