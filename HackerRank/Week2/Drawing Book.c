#include<stdio.h>
int pc(int n, int p)
{
    int fr=p/2;
    int ba=(n/2)-(p/2);
    return (fr<ba)?fr:ba;
}
int main()
{
    int n,p;
    scanf("%d",&n);
    scanf("%d",&p);
    int result=pc(n,p);
    printf("%d\n",result);
    return 0;
}