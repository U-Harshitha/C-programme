#include<stdio.h>
#include <stdlib.h>
struct node{
int x;
struct node * link;
}*first,*last,*nn,*temp;
int count(){
    int i;
    if (first==NULL)
        return 0;
    temp=first;
    for(i=0;temp->link!=NULL;i++)
        temp=temp->link;
    return ++i;
}
int deleteStart( )
{
    int e=0;
    if (first==NULL)
        printf("Empty");
    else
    {
        temp=first;
        e=first->x;
        first=first->link;
        temp->link=NULL;
    }
    free(temp);
    return e;
}
void insertEnd()
{
    nn=(struct node *)malloc(sizeof(struct node));
    printf("Enter Data");
    scanf("%d",&nn->x);
    if (first==NULL)
        first=nn;
    else
        last->link=nn;
    nn->link=NULL;
    last=nn;
}

struct node* create(struct node *f)
{
    int ch;
    do{
        nn=(struct node *)malloc(sizeof(struct node));
        printf("Enter Data");
        scanf("%d",&nn->x);
        if (f==NULL)
            f=nn;
        else
            temp->link=nn;
        temp=nn;
        printf("Continue ? 0/1");
        scanf("%d",&ch);
    } while(ch!=0);
    temp->link=NULL;
    return f;
}
void display(struct node *f)
{
    if(f==NULL)
        printf("Empty");
    else
    {
        temp=f;
        while(temp!=NULL)
        {
            printf("%3d",temp->x);
            temp=temp->link;
        }
    }
}
int main()
{
    int x,y,ch;
    do{
        printf("\nChoice\n1.Insert\n2.Delete\n3.Create\n4.Count\n6.Display\n0.Exit\n");
        scanf("%d",&x);
        switch(x)
        {
            case 1: insertEnd(); break;      
            case 2: printf("\nDeleted element = %d\n",deleteStart());break;
            case 3: first=create(first); break;
            case 4: printf("\nNumber of Elements = %d\n",count()); break;
            case 6: display(first);
        }
    }while(x!=0);
}
