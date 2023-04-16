#include<stdio.h>
int main()
{
    char s[30];
    scanf("%s",s);
    printf("Day: %c%c\nMonth: ",s[7],s[8]);
    int n;
    n=(s[5]-'0')+(s[6]-'0');
    switch(n){
        case 1: printf("January");break;
        case 2: printf("February");break;
        case 3: printf("March");break;
        case 4: printf("April");break;
        case 5: printf("May");break;
        case 6: printf("June");break;
        case 7: printf("July");break;
        case 8: printf("August");break;
        case 9: printf("September");break;
        case 10: printf("October");break;
        case 11: printf("November");break;
        case 12: printf("December");break;
        }
        printf("\nYear: 20%c%c",s[3],s[4]);
    return 0;
}
