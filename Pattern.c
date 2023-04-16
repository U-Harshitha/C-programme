# include<stdio.h>
int main()
{
    int n,i,j,k;
    scanf("%d",&n);
    for(i=1;i<=n+1;i++)
    {
        for(j=1;j<i;j++)
            printf("* ");
        for(k=-1;k<=2*n-2*i;k++)
            printf("  ");
        for(j=1;j<i;j++)
            printf(" *");
        printf("\n");
    }
    for(i=n;i>0;i--)
    {
        for(j=i;j>0;j--)
            printf("* ");
        for(k=1;k<=2*n-2*i;k++)
            printf("  ");
        for(j=0;j<i;j++)
            printf(" *");
        printf("\n");
    }
    return 0;
}
