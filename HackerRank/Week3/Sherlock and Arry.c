#include <stdio.h>

int main() 
{
    int t;
    scanf("%d", &t);
    while (t--) {
        int n;
        scanf("%d", &n);
        int a[n];
        long total = 0, ls = 0;
    
        for (int i = 0; i < n; i++) {
            scanf("%d", &a[i]);
            total += a[i];
        }

        int found = 0;
        for (int i = 0; i < n; i++) {
            total -= a[i];
            if (ls == total) {
                found = 1;
                break;
            }
            ls += a[i];
        }

        if (found) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}
