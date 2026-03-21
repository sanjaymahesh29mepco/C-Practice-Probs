#include <stdio.h>
#include <string.h>

void solve() {
    int n;
    if (scanf("%d", &n) != 1) return;
    
    char s[n + 1];
    scanf("%s", s);

    int freq[26] = {0};
    for (int i = 0; i < n; i++) {
        freq[s[i] - 'a']++;
    }

    int odd_count = 0;
    for (int i = 0; i < 26; i++) {
        if (freq[i] % 2 != 0) {
            odd_count++;
        }
    }


    if (odd_count <= 1) {
        printf("0\n");
    } else {
        printf("%d\n", odd_count - 1);
    }
}

int main() {
    int t;
    if (scanf("%d", &t) != 1) return 0;
    while (t--) {
        solve();
    }
    return 0;
}
