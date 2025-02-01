#include<stdio.h>
int main(){
    int a,b;
    printf("\nEnter the value of a: ");
    scanf("%d",&a);
    printf("\nEnter the vslue of b: ");
    scanf("%d",&b);
    int m;
    printf("The value of Division: ");
    printf("%d",m=a/b);
    int r=a-b*m;
    printf("The remainder is: ");
    printf("%d",r);
    


    return 0;
}