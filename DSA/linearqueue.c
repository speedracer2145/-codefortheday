//ALOK P
//2022BCS0014
#include<stdio.h>
#include<stdlib.h>
#define n 100
int front=-1;
int rear=-1;
int q[n];
void ins(int ele)
{
    if(front==n-1)
     printf("Queue full");
    else
    {
        if(front==-1)
        front=0;
        rear=rear+1;
        q[rear]=ele;
    }
}
void del()
{
    if(front>rear||rear==-1)
        printf("Queue empty ");
    else 
    {
        front=front+1;
    }
    
}
void disp()
{
    if(front>rear||rear==-1)
    {
        printf("Queue empty");
    }
    else
    {
     printf("Front element is %d ",q[front]);
    }
}


void main()
{
     printf("a. Enqueue \nb. Dequeue \nc. Display front element \n");
     char ch;
     int ele;
    while(1)
    {
       scanf("%c",&ch);
       switch(ch)
       {
        case 'a':
        {
            scanf("%d",&ele);
            ins(ele);
            break;
        }
        case 'b':
        {
            del();
            break;
        }
        case 'c':
        {
            disp();
            exit(0);
        }       
        }
    }
}