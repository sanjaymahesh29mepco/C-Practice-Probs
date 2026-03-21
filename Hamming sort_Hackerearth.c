#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int value;
    int distance;
} Element;

int get_hamming_distance(int n) {
    int count = 0;
    while (n > 0) {
        n &= (n - 1);
        count++;
    }
    return count;
}

int compare(const void *a, const void *b) {
    Element *e1 = (Element *)a;
    Element *e2 = (Element *)b;

    if (e1->distance != e2->distance) {
        return e1->distance - e2->distance;
    }
   
    return e1->value - e2->value;
}

void solve() {
    int N, K;
    if (scanf("%d %d", &N, &K) != 2) return;

    Element *arr = (Element *)malloc(N * sizeof(Element));
    
    for (int i = 0; i < N; i++) {
        scanf("%d", &arr[i].value);

        arr[i].distance = get_hamming_distance(arr[i].value ^ K);
    }

    qsort(arr, N, sizeof(Element), compare);

    for (int i = 0; i < N; i++) {
        printf("%d%c", arr[i].value, (i == N - 1 ? '\n' : ' '));
    }

    free(arr);
}

int main() {
    int T;
    if (scanf("%d", &T) != 1) return 0;
    while (T--) {
        solve();
    }
    return 0;
}
