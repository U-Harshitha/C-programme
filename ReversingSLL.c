#include<stdio.h>
#include <stdlib.h>
//Reversing a SLL
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
        do
        {
            printf("%3d",temp->x);
            temp=temp->next;
        }while(temp!=NULL);
    }
}
void reverse()
{
        struct node* a,*b,*c,*f;
        a=first;
        f=first;
        b=a->next;
        while(a!=last){
              c=b->next;
              b->next=a;
              a=b;
              b=c;
        }
        first->next=NULL;
        first=last;
        last=f;
        printf("Done");
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
case 3: reverse();
        }
    }while(x!=0);
}
