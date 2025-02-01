#include<stdio.h>

void display(int arr[],int n){
    for(int i=0;i< n;i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int Insertion(int arr[],int size,int element,int capacity,int index){
    //code for insertion
    if(size>=capacity){
        return -1;
    }
    for (int i =size-1;i>=index; i--)
    {
        arr[i+1]= arr[i];

    }
    arr[index]= element;
    return 1;
}

int main(){
    int arr[100] = {7,8,11,26,88};
    int size = 5, element = 30,index=3;
    display(arr,size);
    Insertion(arr, size, element, 100, index);
    size+=1;
    display(arr, size);

    return 0;
}