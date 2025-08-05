#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int cmpasc(const void *a,const void *b)
{
    return (*(int *)a- *(int *)b);
}
int cmpdesc(const void *a,const void *b)
{
    return (*(int *)b- *(int *)a);
}
char* two(int k,int A[],int B[],int n)
{
    qsort(A,n,sizeof(int),cmpasc);
    qsort(B,n,sizeof(int),cmpdesc);

for(int i=0;i<n;i++)
{
    if(A[i]+B[i]<k)
    {
        return "NO";
    }
}
return "YES";
}
int main()
{
    int q;
    scanf("%d",&q);
    while(q--)
    {
        int  n,k;
        scanf("%d %d",&n,&k);
        int A[n],B[n];
        for(int i=0;i<n;i++)
        {
            scanf("%d",&A[i]);
        }
        for(int i=0;i<n;i++)
        {
            scanf("%d",&B[i]);
        }
        printf("%s\n",two(k,A,B,n));
    }
    return 0;
}

