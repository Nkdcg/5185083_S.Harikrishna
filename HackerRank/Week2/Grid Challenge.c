#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int cmp(const void *a, const void *b)
{
    return (*(char*)a-*(char*) b);
}
void gridChallenge(int n,char grid[n][n+1])
{
    for(int i=0;i<n;i++)
    {
        qsort(grid[i],n,sizeof(char),cmp);
    }
    for(int c=0;c<n;c++)
    {
        for(int r=0;r<n-1;r++)
        {
            if(grid[r][c]>grid[r+1][c])
            {
                printf("NO\n");
                return;
            }
        }
    }
    printf("YES\n");
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n;
        scanf("%d", &n);
        char grid[n][n+1];
        for(int i=0;i<n;i++)
        {
            scanf("%s",grid[i]);
        }
        gridChallenge(n,grid);
    }
    return 0;
}
