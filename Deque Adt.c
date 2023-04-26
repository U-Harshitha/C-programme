#include <stdio.h>
#define max 15
int dq[max],e,f=0,r=-1;
void insertf(int s)
{
		dq[--f]=s;
}

void insertr(int s)
{
	dq[++r]=s;
}
int delf()
{
	int s=0;
	if(f==0 && r==-1)
	  printf("Empty\n");

	else
    s=dq[f++];
  return s;
}
int delr()
{
	int s;
	if(f==0 && r==-1)
	{
    printf("Invalid\n");
    return 0;
	}
	else if(f==r)
	{
		s=dq[r];
		f=0;r=-1;
		return x;
	}
	else
	{
		s=dq[r--];
		return s;
	}
}
void display()
{
	int i;
	for(i=f;i<=r;i++)
	printf("%3d",dq[i]);
}
void isfull()
{
  (r==max-1 && f==0)?printf("Full"):printf("Not Full");
}
void isempty()
{
   (f==0 && r==-1)?printf("Empty"):printf("Not Empty");
}
void main()
{
	int x;
	char ch;
	do {
        printf("Select \n1.Insert from front \n2.Insert from rear \n3.Delete from front \n4.Delete from rear \n5.Display \n6.Isfull \n7.Isempty\n");
        scanf("%d",&x);
        switch(choice)
        {
          case 1:if(f==0)
                  printf("Not Feesible");
                 else
              {
                   printf("Enter the element you want to insert from front\n");
                   scanf("%d",&e);
                   insertf(e);	
              }
                break;
          case 2:if(r==max-1)
                     printf("FULL\n");
               else
               {
                     printf("Enter the element you want to insert from rear\n");
                     scanf("%d",&e);
                     insertr(e);
               }
               break;		
          case 3:printf("Element deleted is %d",delf(););
               break;		
          case 4: printf("Element deleted is %d",delr(););
               break;	
          case 5:display();
               break;
          case 6:isfull();break;
          case 7:isempty();break;         
        }
        printf("Continue y\n");
        ch=getchar();
      }while(ch !='n');
		
}

