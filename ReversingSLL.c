#include<stdio.h>
#include <stdlib.h>
struct node{
int x;
struct node * next;
}*first,*last,*nn,*temp;
struct node* create(struct node *f)
{
    int ch;
    do{
        nn=(struct node *)malloc(sizeof(struct node));
        printf("Enter Data\n");
        scanf("%d",&nn->x);
        if (f==NULL)
            f=nn;
        else
            temp->next=nn;
        temp=nn;
        temp->next=NULL;
        printf("Continue ? 0/1");
        scanf("%d",&ch);
    } while(ch!=0);
    last=temp;
    temp->next=NULL;
    return f;
}
void displayF()
{
    if(first==NULL)
        printf("Empty");
    else
    {
        temp=first;
        while(temp!=NULL){
          printf("%3d",temp->x);
          temp=temp->next;
        }
    }
}
struct node* reverse(struct node *f){
    struct node *prev = NULL, *curr = f, *next;
    while(curr != NULL){
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}
int main()
{
    int x,y,ch;
    do{
        printf("\nChoice\n1.Create\n2.Display\n3.Reverse\n0.Exit\n");
        scanf("%d",&x);
        switch(x)
        {
            case 1: first=create(first);
                    break;
            case 2: displayF();break;
            case 3: first = reverse(first);
                    printf("Reversed\n"); break;
        }
    }while(x!=0);
}
