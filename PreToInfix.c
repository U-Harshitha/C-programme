#include <stdio.h>
#include <string.h>
char stack[100][100],temp[100];
int top = -1;

void push(char a[])
{
    top++;
    strcpy(stack[top], a);
}

void pop()
{
    strcpy(temp,stack[top--]);
}

int isOperator(char ch)
{
    if (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^')
        return 1;
    else
        return 0;
}



int main()
{
    char post[100];

    printf("Enter the Postfix Expression : ");
    gets(post);
    int i;
    char  op1[100], op2[100], pre[100],str[100];

    for (i = 0; post[i] != '\0'; i++)
    {
       str[0]=post[i];
        	str[1]='\0';

        if (isOperator(post[i]))
        {
            pop();
            strcpy(op2, temp);
            pop();
            strcpy(op1, temp);

            strcpy(pre, op1);
            strcat(pre, str);
            strcat(pre, op2);

            push(pre);
        }
        else
        {
            push(str);
        }
    }
   printf("The Infix Expression is : %s\n", stack[top]);
    return 0;
}