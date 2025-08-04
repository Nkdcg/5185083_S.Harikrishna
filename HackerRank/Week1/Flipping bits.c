#include<stdio.h>
#include<stdint.h>
uint32_t  flipbit(uint32_t n)
{
    return ~n; 
}
int main()
{
    int a;
    scanf("%d",&a);
    while(a--)
    {
        uint32_t num;
        scanf("%u",&num);
        uint32_t r=flipbit(num);printf("%u\n",r);
    }
    return 0;
}