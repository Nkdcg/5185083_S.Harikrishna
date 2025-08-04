#include<stdio.h>
void minmax(int arr[],int n)
{
    long int t=0;
    int min=arr[0];
    int max=arr[0];
    for(int i=0;i<n;i++)
    {
        t+=arr[i];
        if(arr[i]>max)
        {
            max=arr[i];
        }
        if(arr[i]<min)
        {
            min=arr[i];
        }
    }
    long int maxs=t-max;
    long int mins=t-min;
    printf("%lld %lld\n",maxs,mins);
}
int main()
{
    int a[5];
    for(int i=0;i<5;i++)
    {
        scanf("%d",&a[i]);
    }
    minmax(a,5);
}