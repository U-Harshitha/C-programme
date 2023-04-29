
cse-d students <csedstudents2021@gmail.com>
14:14 (4 hours ago)
to me

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
    return o;
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


void sum(struct node* a, struct node* b) {
    temp = a;
    f = b;
   
    while (temp != NULL || f != NULL) {
        if(temp->p==f->p){
            insert(temp->x+f->x,f->p);
            temp=temp->next;
            f=f->next;
            }
            else if(temp->p>f->p){
                insert(temp->x,temp->p);
                temp=temp->next;}
                else if(temp->p<f->p){
                    insert(f->x,f->p);
                    f=f->next;}
                }
            printf("Done\n");
            }

int main() {
    int x, y;
    struct node *a = NULL, *b = NULL;
    do {
        printf("\nChoice\n1. Create\n2. Display A\n3. Display B\n4. Sum\n0. Exit\n");
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
        case 4: sum(a, b);
display(first); c=NULL; break;
        }
    } while (x != 0);
    return 0;
}
