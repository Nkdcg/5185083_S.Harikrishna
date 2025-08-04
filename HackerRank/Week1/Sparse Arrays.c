#include<stdio.h>
#include<string.h>
int main()
{
    int n,q;
    scanf("%d",&n);
    char str[n][101];
    for(int i=0;i<n;i++)
    {
        scanf("%s",str[i]);
    }
    scanf("%d",&q);
    char que[q][101];
    for(int i=0;i<q;i++)
    {
        scanf("%s",que[i]);
    }
    for(int i=0;i<q;i++)
    {
        int c=0;
        for(int j=0;j<n;j++)
        {
            if(strcmp(que[i],str[j])==0)
            {
                c++;
            }
        }
        printf("%d\n",c);
 
    }
}