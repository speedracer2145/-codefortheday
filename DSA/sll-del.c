#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node *next;
};
struct Node *head = NULL;
void insFirst (int num){
    struct Node *ins=(struct Node*)malloc(sizeof(struct Node));
    if(head==NULL){
        ins -> data = num;
        head = ins;
    }
    else{
        ins-> data = num;
        ins -> next = head;
        head = ins;
    }
}
void insLast (int num){
    struct Node * a;
   a = (struct Node*)malloc(sizeof(struct Node));
    if(head == NULL){
        a-> data = num;
        head = a;
    }
    else{
        struct Node * b = head; 
        while(b -> next!=NULL){
            b= b -> next;
        }
        b -> next = a;
        a -> data = num;
    }
}
void  display(){
    struct Node *a = head;
    if (a == NULL) {
        printf("Linked list is empty.\n");
        return;
    }
    printf("Elements in the linked list:\n");
    while(a != NULL){
        printf("%d", a -> data);
        if(a -> next != NULL){
            printf(" -> ");
        }
        a = a -> next;
    }
    printf("\n");
}
void deletefirst(){
    struct Node *temp = head;
    head = head -> next;
    free(temp);
}
void deleteLast(){
    struct Node *aa = head;
    struct Node *bb = head -> next;
    if (bb == NULL) {
        free(aa);
        head = NULL;
        return;
    }
    while(bb -> next!= NULL){
        aa = aa -> next;
        bb = bb -> next;
    }
    aa -> next = NULL;
    free(bb);
}
int main(void){
    char c = 'y';
    while(c=='y'){
        char cc;
        scanf(" %c",&cc);
        switch(cc){
            int num,num1;
            case 'b':
                scanf("%d ",&num);
                insFirst(num);
                break;
            case 'c':
                scanf("%d ",&num1);
                insLast(num1);
                break;
            case 'e':
                deletefirst();
                break;
            case 'f':
                deleteLast();
                break;
            case 'a':
                display();
                c='n';
                break;
            default:
                printf("!!!ERROR!!!");
                c='n';
                break;
        }
    }
    return 0;
}