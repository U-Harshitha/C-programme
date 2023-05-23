#include<stdio.h>
#include<stdlib.h>
struct node
{
    int c;
    struct node *l,*r;
}*nn,*root,*temp,*ptr;
struct node* stack[100];
int top=-1;
void inorderR(struct node *t)
{
    if(t!=NULL){
        inorderR(t->l);
        printf("%d ", t->c);
        inorderR(t->r);
    }
}
void postorderR(struct node* t) {
    if (root == NULL)
        return;
    postorderR(t->l);
    postorderR(t->r);
    printf("%d ", t->c);
}
void preorderR(struct node* t) {
    if (root == NULL)
        return;
    printf("%d ", t->c);
    preorderR(t->l);
    preorderR(t->r);
}
void push(struct node* t) {
    (top)++;
    stack[top] = t;
}
struct node* pop() {
    return stack[top--];
}
struct node* create (struct node * t)
{
    char x;
    push(NULL);
    nn=(struct node *)malloc(sizeof(struct node));
    printf("Enter Root\n");
    scanf("%d",&nn->c);
    t=nn;
    temp=nn;
    while(temp!=NULL)
    {
        printf("Right of %d\n",temp->c);
        scanf("%c",&x);
        if(x=='y'){
            nn=(struct node *)malloc(sizeof(struct node));
            scanf("%d",&nn->c);
            temp->r=nn;
            push(temp->r);
        }
        else 
            temp->r=NULL;
        printf("Left of %d\n",temp->c);
        scanf("%c",&x);
        if(x=='y'){
            nn=(struct node *)malloc(sizeof(struct node));
            scanf("%d",&nn->c);
            temp->l=nn;
            temp=nn;
            }
        else {
            temp->l=NULL;
            temp=pop();
        }
    }
    return t;
}
int hieght(struct node* t) {
    int lh,rh;
    if (t == NULL)
        return 0;
    lh = hieght(t->l);
    rh = hieght(t->r);
    return (lh > rh?(lh+1):(rh+1));
}
int main() {
    struct node* root = NULL;
    int x = 1;
    while (x != 0) {
        printf("\n1.Create\n2.Inorder\n3.Postorder\n4.Preorder\n5.Height\n0.Exit\n");
        scanf("%d", &x);
        switch (x) {
            case 1:root = create(root);
                break;
            case 2:printf("Inorder traversal: ");
                inorderR(root);
                break;
            case 3:printf("Postorder traversal: ");
                postorderR(root);
                break;
            case 4:printf("Preorder traversal: ");
                preorderR(root);
                break;
            case 5: printf("\nHeight of the tree: %d", hieght(root));
                break;
        }
    }
    return 0;
}
