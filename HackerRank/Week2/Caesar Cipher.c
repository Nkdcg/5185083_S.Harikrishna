#include<stdio.h>
#include<string.h>
#include<ctype.h>
void cipher(char *s,int k)
{
    int l=strlen(s);
    k=k%26;
    for(int i=0;i<l;i++)
    {
        char c=s[i];
        if(isalpha(c))
        {
            char b=islower(c)?'a':'A';
            s[i]=((c-b+k)%26)+b;
        }
    }
    printf("%s\n",s);
}
int main()
{
    int n,k;
    scanf("%d",&n);
    char s[1001];
    scanf("%s",s);
    scanf("%d",&k);
    cipher(s,k);
    return 0;
}