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
    return 0;


}