#include <stdio.h>
#include <string.h>
#define MOD 1000000007
#define MAX 1001

long long row[MAX];     
long long total[MAX];   
long long valid[MAX];   


long long modPow(long long base, long long exp) {
    long long result = 1;
    while (exp > 0) {
        if (exp % 2) result = (result * base) % MOD;
        base = (base * base) % MOD;
        exp /= 2;
    }
    return result;
}

int main() {
    int t, n, m;
    scanf("%d", &t);

   
    row[0] = 1;
    for (int w = 1; w < MAX; w++) {
        row[w] = 0;
        for (int b = 1; b <= 4; b++) {
            if (w - b >= 0) row[w] = (row[w] + row[w-b]) % MOD;
        }
    }

    while (t--) {
        scanf("%d %d", &n, &m);

        
        for (int i = 1; i <= m; i++) {
            total[i] = modPow(row[i], n);
        }

       
        valid[1] = total[1];
        for (int i = 2; i <= m; i++) {
            long long bad = 0;
            for (int k = 1; k < i; k++) {
                bad = (bad + valid[k] * total[i-k]) % MOD;
            }
            valid[i] = (total[i] - bad + MOD) % MOD; 
        }

        printf("%lld\n", valid[m]);
    }
    return 0;
}
