#include<stdio.h>
#include<stdlib.h>
int diagdiff(int n,int a[n][n])
{
    int p=0,s=0;
    for(int i=0;i<n;i++)
    {
        p+=a[i][i];
        s+=a[i][n-i-1];
    }
    return abs(p-s);
}
int main()
{
    int n;
    scanf("%d",&n);
    int a[n][n];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            scanf("%d",&a[i][j]);
        }
    }
    int r=diagdiff(n,a);
    printf("%d\n",r);
    return 0;
}