#include<stdio.h>
#include<stdlib.h>

typedef struct Node SLL ; 
struct Node{
	int data ;
	SLL *next ;
}*h = NULL ;
 

// 1. INSERT at BEGINNING
SLL *Insert_Beg(int x , SLL *h){
	SLL *t, *t1;
	t = (SLL*)malloc(sizeof(SLL));
	if(t!=NULL){
		t->data=x;
		t->next=NULL;
		t1=h;
		if(t1==NULL){
			t1=t;
			return t1;
		}
		else{
			t->next=t1;
			t1=t;
			return t1;
		}
	}
	else {
		printf("Out of memory\n");
	}
}
// 2. INSERT at END
SLL* Insert_End(int x, SLL* h) {
    SLL* new_node = (SLL*)malloc(sizeof(SLL));
    if (new_node != NULL) {
        new_node->next = NULL;
        new_node->data = x;
        if (h == NULL) {
            return new_node; // If the list is empty, return the new node as the new head.
        } else {
            SLL* t = h;
            while (t->next != NULL) {
                t = t->next;
            }
            t->next = new_node;
            return h; // Return the original head.
        }
    } else {
        printf("Out of Memory.\n");
        return h; // Return the original head if memory allocation fails.
    }
}



//3. INSERT before X
SLL* Insert_Bx(int x, int y, SLL* h) {
    SLL* new_node = (SLL*)malloc(sizeof(SLL));
    if (new_node != NULL) {
        new_node->data = y;
        new_node->next = NULL;
        SLL* t1 = h;
        if (t1 == NULL) {
            printf("List is empty.\n");
            return h;
        } else {
            if (t1->data == x) {
                new_node->next = t1;
                return new_node;
            } else {
                while (t1->next != NULL && t1->next->data != x) {
                    t1 = t1->next;
                }
                if (t1->next != NULL) {
                    new_node->next = t1->next;
                    t1->next = new_node;
                    return h;
                } else {
                    printf("Element is not present.\n");
                    free(new_node);
                    return h;
                }
            }
        }
    } else {
        printf("Out of memory.\n");
        return h;
    }
}

// 4. INSERT after X
SLL* Insert_Ax(int x, int y, SLL* h) {
    SLL* new_node = (SLL*)malloc(sizeof(SLL));
    if (new_node != NULL) {
        new_node->data = y;
        new_node->next = NULL;
        SLL* t1 = h;
        if (t1 == NULL) {
            printf("List is empty.\n");
            return h;
        } else {
            while (t1->next != NULL && t1->data != x) {
                t1 = t1->next;
            }
            if (t1->data == x) {
                new_node->next = t1->next;
                t1->next = new_node;
                return h;
            } else {
                printf("Element is not present.\n");
                free(new_node);
                return h;
            }
        }
    } else {
        printf("Out of memory.\n");
        return h;
    }
}

// 5. DELETE the Element X
SLL *Delete_X(SLL *h , int x ){
	SLL *t = h ; SLL *t1 ;
	if(t!=NULL){
		if(t->data == x){
			h = t->next ;
			free(t) ;
			return h ;
		}else{
			while(t->next != NULL && t->next->data != x){
				t = t->next ;
			}
			if(t->next != NULL){
				t1 = t->next ;
				t->next = t->next->next ;
				free(t1) ;
				return h ;
			}else{
				printf("Element not found.\n") ;
			}
		}
	}else{
		printf("Deletion not possible.\n") ;
	}
}

// 6. SEARCH an ELEMENT X
SLL *Search(SLL *h , int s){
	SLL *t = h ;
	while(t!=NULL){
		if(t->data == s ){
			printf("Element Found.") ;
			return t ;
		}
		t = t->next ;
	}
	printf("Element not found.\n") ;
	return NULL ;
}

// 7. TRAVERSING(DISPLAY) the LINKED LIST
void traverse(SLL *h){
	SLL  *t=h;
	if(t==NULL){
		printf("List is empty\n");
		return ;
	}
	while(t!=NULL){
		printf("%d \n",t->data);
		t=t->next;
	}
	return;
}

int main(){
	
	printf("1. Insert at the Beginning:-\n") ;
	printf("2. Insert at the End:-\n") ;
	printf("3. Insert after X:-\n") ;
	printf("4. Insert before X:-\n") ;
	printf("5. Delete X:-\n") ;
	printf("6. Traverse through the Linked List:-\n") ;
	printf("7. Search in the Linked List:-\n") ;
    printf("8. Exiting the program:-\n") ;
	printf("Choice = ? \n") ;
	int ch ;
	int x , y ;
	scanf("%d" , &ch) ;
	while(ch<=8){
		switch(ch){
			case 1:
				printf("Enter what you want to insert at begining:-\n");
				scanf("%d",&x);
				h = Insert_Beg(x,h) ;
				break ;
			case 2:
				printf("Enter what you want to insert  at end:-\n");
				scanf("%d" , &x) ;
				h = Insert_End(x,h) ;
				break ;
			case 3:
				printf("Enter the element after which you want to Insert:-\n") ;
				scanf("%d" , &x ) ;
                printf("Enter what you want to insert:-\n");
				scanf("%d" , &y) ;
				h = Insert_Ax(x,y,h) ;
				break ;
			case 4:
				printf("Enter the element before which you want to Insert:-\n") ;
				scanf("%d" , &x ) ;
                printf("Enter what you want to insert:-\n");
				scanf("%d" , &y) ;
				h = Insert_Bx(x,y,h) ;
				break ;
			case 5:
                printf("Enter what you want to delete:-\n");
				scanf("%d",&x);
				Delete_X(h , x) ;
				break ;
			case 6:
                printf("Traversing your Linked List:- \n");
				traverse(h) ;
				break ;
			case 7:
				printf("Enter what you want to search:-\n");
				scanf("%d",&x);
				h = Search(h,x) ;
				break ;
			case 8: {
				printf("Exited the program.....\n");
				exit(0);
				break;
			}
			default: {
				printf("Enter valid number between 1 to 8.\n");				
				break;
			}						
		}
        printf("Choice ? ");
		scanf("%d",&ch);
	}
	
	
	
	return 0;
}