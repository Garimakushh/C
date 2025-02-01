//program for inserting a new element in the given array at position p
#include<stdio.h>
void insert_(int [],int,int,int );
int main()
{
    int a[100],n,i,p,x;
    printf("The value of n is : ");
    scanf("%d",&n);
    printf("Load the array : ");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    scanf("%d",&a[i]);
    printf("At which position : ");
    scanf("%d",&p);
    printf("New element : ");
    scanf("%d",&x);
    
    n= insert(a,n,p,x);
    printf("After insertion : ");
    for(i=0;i<n;i++)
    printf("%d",a[i]);

    return 0;
}
int insert (int b[],int m,int a,int y)
{
    int i;
    for (i=m-1;i>=a-1;i--)
    b[i+1] = b[i];
    b[a-1] = y;
    m = m+1;
    return m;
}