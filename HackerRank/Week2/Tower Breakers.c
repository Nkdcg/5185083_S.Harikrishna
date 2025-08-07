#include<stdio.h>
int tb(int n,int m)
{
    if(m==1 || n%2==0)
    {
        return 2;
    }
    else {
    return 1;
    }
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n,m;
        scanf("%d %d",&n,&m);
        int w=tb(n,m);
        printf("%d\n",w);
    }
    return 0;
}