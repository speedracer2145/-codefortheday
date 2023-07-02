#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node * next;
};

void Access(struct node * head)
{
    struct node * temp=head;
    while(temp!=NULL)
    {
        printf("%d->",temp->data);
        temp=temp->next;
    }
    printf("NULL");

}

struct node * insFirst(struct node * head,int data)
{
    struct node * new=(struct node *)malloc(sizeof(struct node));
    new->next=head;
    new->data=data;
    return new;

}

struct node * insEnd(struct node * head,int data)
{
    struct node * new=(struct node *)malloc(sizeof(struct node));
    struct node * a=(struct node *)malloc(sizeof(struct node));
    a=head;
    new->data=data;
    new->next=NULL;
    while(a->next!=NULL)
    {
        a=a->next;
    }
    a->next=new;
    
    return head;

}

struct node *insAny(struct node *head,unsigned int ele)
{
    unsigned int pos;
    int c=0;
    struct node *temp,*curr;
    temp=(struct node *)malloc(sizeof(struct node));
    temp->data=ele;
    scanf("%d",&pos);
    if(head==NULL)
        temp->next=NULL;
    else 
    {
        if(pos==1)
        {
            temp->next=head;
            head=temp;
        }
        else 
        {
            c=1;
            curr=head;
            while(c<pos-1 && curr->next!=NULL)
            {
                c++;
                curr=curr->next;
            } 
            if(curr->next==NULL)
            {
                temp->next=NULL;
                curr->next=temp;
            }
            else
            {
                temp->next=curr->next;
                curr->next=temp;
            }
        }
    }
}
int main()
{
    struct node * head=NULL;
    
  
    

    char ch;
    unsigned int ele;
    int n;
    int d=0;
 while(d!=1)
    {
        ch=getchar();
        switch(ch)
        {

            case 'b':
            
            scanf("%d ",&n);
            
            head=insFirst(head,n);
            break;

            case 'c':
            
            scanf("%d ",&n);
            
            insEnd(head,n);
            break;

            case 'a':
            Access(head);
            d=1;
            break;

            case 'd':
            scanf("%d",&ele);
            insAny(head,ele);
            break;


            case 'e':
            d=1;
            break;
        }
    }
}
