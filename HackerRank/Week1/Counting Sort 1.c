#include<stdio.h>
#include<stdlib.h>
void countingSort(int arr[],int n, int freq[])
{
    for(int i=0;i<100;i++)
    {
        freq[i]=0;
    }
    for(int i=0;i<n;i++)
    {
        if(arr[i]>=0 && arr[i]<100)
        {
            freq[arr[i]]++;
        }
    }
}
int main()
{
    int n;
    scanf("%d",&n);
    int *arr=(int *)malloc(n*sizeof(int));
    int freq[100];
    for(int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    countingSort(arr,n,freq);
    for(int i=0;i<100;i++){
    printf("%d ",freq[i]);
}
free(arr);
return 0;
}
