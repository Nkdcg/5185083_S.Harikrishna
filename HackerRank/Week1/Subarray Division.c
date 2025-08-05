#include<stdio.h>
int birth(int s[],int n,int d,int m)
{
    int c=0;
    for(int i=0;i<=n-m;i++)
    {
        int sum=0;
    for(int j=0;j<m;j++)
    {
        sum+=s[i+j];
    }
    if(sum==d)
    {
        c++;
    }
}
return c;
}
int main()
{
    int n;
    scanf("%d",&n);
    int s[n];
    for(int i=0;i<n;i++)
    {
        scanf("%d",&s[i]);
    }
    int d,m;
    scanf("%d %d",&d,&m);
    printf("%d\n",birth(s,n,d,m));
    return 0;
}