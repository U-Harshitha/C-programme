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
int deletEnd()
{
    int e=0;
    if (first==NULL)
        printf("Empty");
    else{
        temp=first;
        while(temp->link->link!=NULL)
            temp=temp->link;
        e=temp->link->x;
        free(temp->link);
        temp->link=NULL;
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
        temp=temp->link;
        t=temp->link;
        temp->link=temp->link->link; //deleting linkd thing
        t->link=NULL;
        free(t);
    }
}

void insertStart()
{
    nn=(struct node *)malloc(sizeof(struct node));
    printf("Enter Data");
    scanf("%d",&nn->x);
    if (first==NULL)
        nn->link=NULL;
    else
        nn->link=first;
    first=nn;
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
        printf("Enter Data");
        scanf("%d",&nn->x);
        temp=first;
        pos-=2;
        while(pos--)
            temp=temp->link;
        nn->link=temp->link;
        temp->link=nn;
    }
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
int search()
{
    int ele,f=0;
    printf("Enter ele");
    scanf("%d",&ele);
    temp=first;
    while(temp!=NULL)
    {
        if(temp->x==ele)
        f=1;
        temp=temp->link;
    }
    return f;
}

int main()
{
    int x,y,ch;
    do{
        printf("\nChoice\n1.Insert\n2.Delete\n3.Create\n4.Search\n5.Count\n6.Display\n0.Exit");
        scanf("%d",&x);
        switch(x)
        {
            case 1: printf("\nStarting\nEnding\nPosition");
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
            case 5: printf("Number of Elements = %d",count()); break;
            case 6: display(first);
        }
    }while(x!=0);
}
