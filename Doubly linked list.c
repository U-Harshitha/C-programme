#include<stdio.h>
#include <stdlib.h>
//doubly linked list
struct node{
int x;
struct node * next, *prev;
}*first,*last,*nn,*temp;
int count(){
    int i;
    if (first==NULL)
        return 0;
    temp=first;
    for(i=0;temp!=NULL;i++)
        temp=temp->next;
    return i;
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
        first=first->next;
        temp->next=NULL;
        temp->prev=NULL;
        first->prev=NULL;
    }
    free(temp);
    return e;
}
int deletEnd()
{
    int e=0;
    if (first==NULL)
        printf("Empty");
    else{
        temp=last;
        e=temp->next->x;
        last=last->prev;
        last->next=NULL;
        temp->next=NULL;
        temp->prev=NULL;
        free(temp);
        }
    return e;
}
int deletePos()
{
    struct node * t;
    int e=0,p,c;
    printf("Position = ?");
    scanf("%d",&p);
    c=count();
    if(c==0||p>c)
        printf("Invalid");
    else if(p==1)
        e= deleteStart( );
    else if (p==c)
        deletEnd();
    else {
        temp=first;
        p-=2;
        while(p--)
        temp=temp->next;
        t=temp->next;
        temp->next=t->next;
        t->next->prev=temp;
        t->next=NULL;
        t->prev=NULL;
        free(t);
    }
}
void insertStart()
{
    nn=(struct node *)malloc(sizeof(struct node));
    printf("Enter Data");
    scanf("%d",&nn->x);
    if (first==NULL)
        nn->next=NULL;
    else{
        nn->next=first;
        first->prev=nn;
    }
    first=nn;
    first->prev=NULL;
}
void insertEnd()
{
    nn=(struct node *)malloc(sizeof(struct node));
    printf("Enter Data");
    scanf("%d",&nn->x);
    if (first==NULL){
        first=nn;
first->prev=NULL;}
    else{
        last->next=nn;
nn->prev=last;}
    last=nn;
    last->next=NULL;
}

void insertPos()
{
    int pos,c;
    c=count();
    printf("Enter Position");
    scanf("%d",&pos);
    if (pos==1)
        insertStart();
    else if (pos==c+1)
        insertEnd();
    else if (pos<=c)
    {
        nn=(struct node *)malloc(sizeof(struct node));
        printf("Enter Data\n");
        scanf("%d",&nn->x);
        temp=first;
        pos-=2;
        while(pos--)
            temp=temp->next;
        nn->next=temp->next;
        nn->prev=temp;
        temp->next->prev=nn;
        temp->next=nn;
    }
}
struct node* create(struct node *f)
{
    int ch;
    do{
        nn=(struct node *)malloc(sizeof(struct node));
        printf("Enter Data");
        scanf("%d",&nn->x);
        if (f==NULL){
            f=nn;
            f->prev=NULL;}
        else{
            temp->next=nn;
            nn->prev=temp;
    }
        temp=nn;
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
void displayB()
{
    if(first==NULL)
        printf("Empty");
    else
    {
        temp=last;
        do
        {
            printf("%3d",temp->x);
            temp=temp->prev;
        }while(temp!=NULL);
    }
}
int search()
{
    int ele,f=0;
    printf("Enter ele");
    scanf("%d",&ele);
    temp=first;
    do
    {
        if(temp->x==ele)
        f=1;
        temp=temp->next;
    }while(temp!=NULL);
    return f;
}

int main()
{
    int x,y,ch;
    do{
        printf("\nChoice\n1.Insert\n2.Delete\n3.Create\n4.Search\n5.Count\n6.Display\n0.Exit\n");
        scanf("%d",&x);
        switch(x)
        {
           case 1: printf("\nStarting\nEnding\nPosition\n");
                    scanf("%d",&y);
                    switch(y)
                    {
                        case 1: insertStart(); break;
                        case 2: insertEnd(); break;
                        case 3: insertPos();break;
                    }
                    break;
            case 2: printf("\nStarting\nEnding\nPosition");
                    scanf("%d",&y);
                    switch(y)
                    {
                        case 1: printf("deleted element = %d",deleteStart()); break;
                        case 2: printf("deleted element = %d",deletEnd()); break;
                        case 3: printf("deleted element = %d",deletePos());break;
                    }
                    break;
            case 3: first=create(first);
                    break;
           case 4: search()? printf("Found"):printf("Nope!"); break;
           case 5: printf("Number of Elements = %d",count());
                    break;
            case 6: printf("From\n1.Front\n2.Back");
          scanf("%d",&y);
          if(y==1)
          displayF();
          else
          displayB();
                  }
              }while(x!=0);
}
