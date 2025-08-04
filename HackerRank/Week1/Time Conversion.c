#include<stdio.h>
#include<string.h>
int main()
{
    char t[11];
    scanf("%s",t);
    int h;
    sscanf(t,"%2d",&h);
    if(t[8]=='A')
    {
        if(h==12)
        h=0;
    }
    else {
    
        if(h!=12)
        h+=12;
    }
    printf("%02d:%c%c:%c%c\n",h,t[3],t[4],t[6],t[7]);
    return 0;
}