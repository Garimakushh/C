//program for linear search 
#include<stdio.h>
//#include<conlo.h>
int binarySearchh(int arr[],int key,int n){
    int store=-1;
    for(int i=0;i<n;i++){
        if(arr[i]==key){
            store=i;
            break;
        }
    }
    return store;
}
int main(){
    int arr[100];
    int n;
    printf("Enter the size of the array\n");
    scanf("%d",&n);
    printf("Enter the element you want to search\n");
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    int key;
    printf("Enter the element you want to search\n");
    scanf("%d",&key);
    int p=binarySearch(arr,key,n);
    printf("The element is present in the array and its index is");
    printf("%d",p);
}

