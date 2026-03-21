#include <stdio.h>
#include <string.h>


void solve() {
    char s[10005];
    if (scanf("%s", s) != 1) return;

    int freq[26] = {0};
    int i = 0;
    
 
    while (s[i] != '\0') {
        freq[s[i] - 'a']++;
        i++;
    }

    int max_palindromes = 0;
   
    for (int j = 0; j < 26; j++) {
        max_palindromes += freq[j] / 2;
    }

    printf("%d\n", max_palindromes);
}

int main() {
    int t;
    if (scanf("%d", &t) != 1) return 0;

    while (t--) {
        solve();
    }

    return 0;
}
