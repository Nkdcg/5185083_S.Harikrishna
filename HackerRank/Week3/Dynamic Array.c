#include<stdio.h>
#include<stdlib.h>
int main()
{
    int n,q;
    scanf("%d %d",&n,&q);
    int **seql=malloc(n*sizeof(int *));
    int *seqs=calloc(n,sizeof(int));
    int *seqc=calloc(n,sizeof(int));
    int lastAnswer=0;
    for(int i=0;i<q;i++)
    {
        int t,x,y;
        scanf("%d %d %d",&t,&x,&y);
        int idx=(x^lastAnswer)%n
;
if(t==1)
{
    if(seqc[idx]==0)
    {
        seqc[idx]=2;
        seql[idx]=malloc(seqc[idx]*sizeof(int));
    }
    else if(seqs[idx]>=seqc[idx])
    {
        seqc[idx]*=2;
        seql[idx]=realloc(seql[idx],seqc[idx]*sizeof(int));
    }
    seql[idx][seqs[idx]++]=y;
}
else if(t==2)
{
    int pos= y % seqs[idx];
    lastAnswer=seql[idx][pos];
    printf("%d\n",lastAnswer);
}    }
for(int i=0;i<n;i++)
{
    free(seql[i]);
}
free(seql);
free(seqs);
free(seqc);
return 0;
}