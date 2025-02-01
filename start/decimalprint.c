#include<stdio.h>
int main(){
    float n;
    printf("The decimal num: ");
    scanf("%f",&n);
    
    int x;
    x=n;
    
    printf("The integer num: ");
    printf("%d",x);
    
    printf("\nThe decimal part is: ");
    float m;
    m=n-x;
    printf("%f",m);

    return 0;
}