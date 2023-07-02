#include<math.h>
#include<stdio.h>
#include<stdlib.h>
#define Max 10
int top=-1;
int stack[Max];
void push()
{
  int val;
 if(top==Max-1)
  printf("stack is full ");
 else 
 {
   scanf("%d",&val);
   top=top+1;
   stack[top]=val;
 }
}
void pop()
{
   if(top==-1)
    printf("THe stack is empty");
   else{
    top=top-1;
   }
    
}
void disp()
{
if(top==-1)
{
printf("Stack empty");
}
else
    printf("Top element is %d",stack[top]);
    exit(0);
}
int main()
{
    char choice;
   while(1)
{ 
  scanf("%c",&choice);
  switch(choice)
 {
  case 'a': push();
        break;
  case 'b': pop();
        break;
  case 'c': disp();
        exit(0);
}
   }
}