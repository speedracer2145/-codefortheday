#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node * prev;

    struct node * next;

};

void accessElements(struct node * head)
{
    struct node * a=head;
     printf("Elements in the linked list :\n");
    while(a->next!=NULL)
    {
        printf("%d<->",a->data);
        a=a->next;
    }
    printf("%d",a->data);
   

}

void insertAtfirst(struct node ** head,int data)
{

  struct node* a= (struct node*)malloc(sizeof(struct node));

  
  a->data = data;

 
  a->next = (*head);

 
  a->prev = NULL;


  if ((*head) != NULL)
    (*head)->prev = a;

  
  (*head) = a;


}

void insertAtend(struct node** head, int data) {
  
  struct node* a = (struct node*)malloc(sizeof(struct node));

  
  a->data = data;

 
  a->next = NULL;

  
  struct node* temp = *head;

  if (*head == NULL) {
    a->prev = NULL;
    *head = a;
    return;
  }

  while (temp->next != NULL)
    temp = temp->next;

 

  
  temp->next = a;

  
  a->prev = temp;
}

void deletefirstnode(struct node ** head)
{
    struct node * a=*head;
    
    (*head)=(*head)->next;
    a->next=NULL;
    (*head)->prev=NULL;
    free(a);
    
}

void deletelastnode(struct node ** head)
{
    struct node * a;
    struct node * b;
   
    a=*head;
    b=(*head)->next;
    
    while(b->next!=NULL)
    {
        a=a->next;
        b=b->next;
        
    }
    b->prev=NULL;
    a->next=NULL;
    free(b);
    
}



int main()
{
    struct node * head=NULL;
   
    
  
    

    char ch;
    
    int n;
    
    int d=0;
 while(d!=1)
    {
        scanf(" %c",&ch);
        switch(ch)
        {

            case 'b':
            
            scanf("%d ",&n);
            
            insertAtfirst(&head,n);
            break;

            case 'c':
            
            scanf("%d ",&n);
            
            insertAtend(&head,n);
            break;

            case 'a':
            accessElements(head);
            d=1;
            break;

           case 'e':
        
           deletefirstnode(&head);
           break;

           case 'f':
           deletelastnode(&head);
           break;
           
           


            
            default:
            printf("!!!ERROR!!!");
            d=1;            
            break;
           
            

          

            

        }
    }

   
}