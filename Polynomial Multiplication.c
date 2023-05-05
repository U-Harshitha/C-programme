#include<stdio.h>
#include<stdlib.h>
struct node {
    int x,p;
    struct node* next;
}*temp,*c,*nn,*f,*first,*last;
struct node* create(struct node* o) {
    int ch;
    do {
        nn = (struct node*)malloc(sizeof(struct node));
        printf("Enter Data: ");
        scanf("%d%d", &nn->x,&nn->p);
        if (o == NULL)
            o = nn;
        else
            temp->next = nn;
        temp = nn;
        temp->next = NULL;
        printf("Continue? 0/1 ");
        scanf("%d", &ch);
    } while (ch != 0);
    last=temp;
    return o;
}
int count(){
    int i;
    if (first==NULL)
        return 0;
    temp=first;
    for(i=0;temp->next!=NULL;i++)
        temp=temp->next;
    return ++i;
}
void display(struct node* o) {
    if (o == NULL)
        printf("Empty");
    else {
        temp = o;
        while (temp != NULL) {
            printf(" %dx^%d ", temp->x,temp->p);
            if(temp->next!=NULL)
            printf("+");
            temp = temp->next;
        }
        printf("= 0");
    }
}
void insert(int xx, int pp)
{
    nn=(struct node *)malloc(sizeof(struct node));
    nn->x=xx;
    nn->p=pp;
    if (first==NULL)
        first=nn;
    else
        last->next=nn;
    nn->next=NULL;
    last=nn;
}
struct node * search(int ele)
{
struct node *hhh;
    hhh=first;
    while(hhh!=NULL)
    {
        if(hhh->p==ele)
        return hhh;
        hhh=hhh->next;
    }
    return 0;
}
void product(struct node* a, struct node* b) {
int h=1,i=1;
struct node *hh;
temp = a;
f = b;
    while (temp != NULL)
{
    f = b;
        while(f != NULL){
        hh=search(temp->p+f->p);
if(hh)
        hh->x+=temp->x*temp->x;
else
       insert(temp->x * f->x,temp->p+f->p);
       f=f->next;
}
temp=temp->next;
    }
    temp = first;
    f = first;
    printf("Done\n");
}

int main() {
    int x, y;
    struct node *a = NULL, *b = NULL;
    do {
        printf("\nChoice\n1. Create\n2. Display A\n3. Display B\n4. Product\n0. Exit\n");
        scanf("%d", &x);
        switch (x) {
        case 1:
            printf("\n1. First\n2. Second\n");
            scanf("%d", &y);
            if (y == 1)
                a = create(a);
            else
                b = create(b);
            break;
        case 2: display(a); break;
        case 3: display(b); break;
        case 4: product(a,b);
display(first); c=NULL; break;
        }
    } while (x != 0);
    return 0;
}
