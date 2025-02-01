#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node*next;
};

void traversal(struct node*ptr){
    if(ptr==NULL){
        printf("Linked list is empty");

    }
    while(ptr!=NULL){
        printf("Element :  %d\n",ptr->data);
        ptr=ptr->next;
    }
}
struct node*insertelement(struct node*head,int data){
    struct node*ptr= (struct node*)malloc(sizeof(struct node));
    ptr ->next=head;
    ptr ->data=data;
    return ptr;
     
}

struct node*insertAtIndex(struct node*head,int data,int index){
    struct node*ptr=(struct node*)malloc(sizeof(struct node));
    struct node*p=head;
    int i=0;
    while(i!=index-1){
        p=p->next;
        i++;
    }
    ptr->data = data;
    ptr->next= p->next;
    p->next = ptr;
    return head;
}
int main(){

    struct node *head;
    head=(struct node*)malloc (sizeof(struct node));
    head->data=7;
    head->next=NULL;
    
    struct node*second=malloc(sizeof(struct node));
    second->data=11;
    second->next=NULL;
    head->next=second;

    struct node*third;
    third=(struct node*)malloc(sizeof(struct node));
    third->data=12;
    third->next=NULL;
    head->next->next=third;

    traversal(head);
    head=insertelement(head,56);
    traversal(head);
    head=insertAtIndex(head,44,1);
    traversal(head);

    return 0;


}