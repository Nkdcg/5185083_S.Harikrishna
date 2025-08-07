#include<stdio.h>
#include<stdlib.h>
int sock(int n,int a[])
{
    int c[101]={0};
    int p=0;
    for(int i=0;i<n;i++)
    {
        c[a[i]]++;
    }
    for(int i=0;i<101;i++)
    {
        p+=c[i]/2;
    }
    return p;
}
int main()
{
    int n;
    scanf("%d",&n);
    int* a=malloc(n*sizeof(int));
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    int r=sock(n,a);
    printf("%d\n",r);
    free(a);
    return 0;
}
