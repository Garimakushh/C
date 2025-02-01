#include<stdio.h>
int binarySearch(int a[],int l,int h,int k){
    int m;
    if(l<=h){
        m=(l+h)/2;
        if(a[m]==k){
            printf("Element found at %d",m+1);
            //exit(0);
            //return 0;
        
    }
        return 0;
    }
    
        
		else if(a[m]>k){
            binarySearch(a,l,m-1,k);            
        }
        else{
            binarySearch(a,m+1,h,k);
        }
    
    printf("Element not found");
    return 0;
}

int main(){
    int arr[100];
    int n,i,k;
    printf("Enter the size of the array\n");
    scanf("%d",&n);
    printf("Enter the sorted element of the array \n");
    for(i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    int l,h;
    l=arr[0];
    h=arr[n-1];
    printf("Enter the key element\n");
    scanf("%d",&k);
    binarySearch(arr,l,h,k);
    
    
    
}