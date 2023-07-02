#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
int queue[100],front=-1,rear=-1,choice = 0,itemcount=0,n=5;
int del();
int ins(int num);
int disp();
bool isFull();
bool isEmpty();
int main()
{
    char c;
    scanf("%c",&c);
    while(c!='c')
    {
        if (c=='a')
        {
                scanf(" %c",&c);
                int num = c;
                num=num-48;
                ins(num);
            }
            else if (c=='b')
            {
                del();
            }
            scanf("%c",&c);
    }
    disp();
}

int ins(int num)
{
    if(front==-1)
    {
        front++;
        rear++;
    }
    else if(isFull())
    {
        printf("Queue is full\n");
        return 0;
    }
    else
    {
        rear=(rear+1)%n;
    }
    queue[rear]=num;
}

int del()
{
    if (isEmpty())
    {
        printf("Queue is Empty\n");
    }
    else if(front==rear)
    {
        front=-1;
        rear=-1;
    }
    else
    {
        int val=queue[front];
        front = (front+1)%n;
    }
    return 0;
}

int disp()
{
    printf("Elements in a Queue are :");
    if(isEmpty())
    {
        printf("Queue is Empty.\n");
    }
    else if(front<=rear){
        int i=front;
        while (i<=rear)
        {
            printf("%d",queue[i]);
            i++;
        }
    }
    else {
        int i=front;
        while (i<n)
        {
            printf("%d",queue[i]);
            i++;
        }
        i=0;
        while (i<=rear)
        {
            printf("%d",queue[i]);
            i++;
        }
    }
}

bool isEmpty(){
    return front==-1;
}

bool isFull(){
    return front==(rear+1)%n;
}