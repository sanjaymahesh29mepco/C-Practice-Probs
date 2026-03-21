#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MOD 1000000007
#define MAX_NODES 2000005

int trie[MAX_NODES][2];
int zeros_count[MAX_NODES];
int node_count = 1;

void insert(char *s) {
    int curr = 0;
    int z = 0;
    for (int i = 0; s[i] != '\0'; i++) {
        int bit = s[i] - '0';
        if (bit == 0) z++;
        
        if (!trie[curr][bit]) {
            trie[node_count][0] = trie[node_count][1] = 0;
            zeros_count[node_count] = z;
            trie[curr][bit] = node_count++;
        }
        curr = trie[curr][bit];
    }
}

int main() {
    int N;
    if (scanf("%d", &N) != 1) return 0;


    trie[0][0] = trie[0][1] = 0;
    zeros_count[0] = 0;

    char *S = (char *)malloc(100005 * sizeof(char));
    for (int i = 0; i < N; i++) {
        scanf("%s", S);
        insert(S);
    }
    free(S);

    long long total_sum = 0;

    for (int i = 1; i < node_count; i++) {
        int z = zeros_count[i];
        if (z > 1) {
            total_sum = (total_sum + (z - 1)) % MOD;
        }
    }

    printf("%lld\n", total_sum);

    return 0;
}
