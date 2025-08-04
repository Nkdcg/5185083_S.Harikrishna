#include<stdio.h>
void plusminus(int a[],int n)
{
    int pos=0,neg=0,z=0;
    for(int i=0;i<n;i++)
    {
        if(a[i]>0){
       pos++; 
    }
    else if(a[i]<0){
        neg++;
    }
    else{
        z++;
    }
    }
printf("%.6f\n",(float)pos/n);
printf("%.6f\n",(float)neg/n);
printf("%.6f\n",(float)z/n);
}
int main()
{
    int n;
    scanf("%d",&n);
    int a[n];
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    plusminus(a,n);
    return 0;
}