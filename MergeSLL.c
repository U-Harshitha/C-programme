#include<stdio.h>
#include<stdlib.h>

struct node {
    int x;
    struct node* next;
}*temp,*c,*nn,*f;

struct node* create(struct node* o) {
    int ch;
    do {
        nn = (struct node*)malloc(sizeof(struct node));
        printf("Enter Data: ");
        scanf("%d", &nn->x);
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
            printf("%d ", temp->x);
            temp = temp->next;
        }
    }
}

void merge(struct node* a, struct node* b) {
    temp = a;
    f = b;
    while (temp != NULL && f != NULL) {
        c = temp->next;
        temp->next = f;
        nn = f->next;
        f->next = c;
        temp = c;
        f = nn;
    }
    if (f != NULL) {
        temp->next = f;
    }
    printf("Done\n");
}

int main() {
    int x, y;
    struct node *a = NULL, *b = NULL;
    do {
        printf("\nChoice\n1. Create\n2. Display A\n3. Display B\n4. Merge\n0. Exit\n");
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
        case 4: merge(a, b); break;
        }
    } while (x != 0);
    return 0;
}
