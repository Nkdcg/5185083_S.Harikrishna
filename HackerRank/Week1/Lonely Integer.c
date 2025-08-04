#include<stdio.h>
int main()
{
    int n;
    scanf("%d",&n);
    int a=0,num;
    for(int i=0;i<n;i++)
    {
        scanf("%d",&num);
        a^=num;
    }
    printf("%d",a);
    return 0;
}