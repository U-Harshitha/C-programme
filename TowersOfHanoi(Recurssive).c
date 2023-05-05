#include<stdio.h>
void Hanoi(int n,char a,char b,char c)
{
    if(n==1) {
        printf("From %c --> %c\n",a,c);
        return;
    }
    Hanoi(n-1,a,c,b);
    printf("From %c --> %c\n",a,c);
    Hanoi(n-1,b,a,c);
}
int main()
{
    int num;
    char a,b,c;
    printf("No of Disks: ");
    scanf("%d",&num);
    Hanoi(num,'a','b','c');
    return 0;
}
