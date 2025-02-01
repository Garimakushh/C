//write a program to delete an element at specified position
#include<stdio.h>
int main(){
    int  arr[100];
    int n;
    printf("Enter the size of the array\n");
    scanf("%d",&n);
    //taking input in the array
    printf("Enter the element of the array\n");
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    int p;
    printf("Enter the position to remove the element starting from one\n");
    scanf("%d",&p);
    if(p>0 && p<n){
        for(int i=p-1;i<n;i++){
            arr[i]=arr[i+1];

        }
        n=n-1;
        //printing the array after deletion 
        for(int i=0;i<n;i++){
            printf("%d",arr[i]);
        }
    }
    else{
        printf("Invalid input of position");
    }
}
