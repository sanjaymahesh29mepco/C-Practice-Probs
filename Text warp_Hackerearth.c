#include <stdio.h>
#include <stdlib.h>


int countLines(int W, int N, int L[]) {
    int lines = 1;
    int currentLineWidth = 0;
    for (int i = 0; i < N; i++) {
        if (L[i] > W) {
            return N + 1;
        }
        if (currentLineWidth == 0) {
            currentLineWidth = L[i];
        } else if (currentLineWidth + 1 + L[i] <= W) {
            currentLineWidth += 1 + L[i];
        } else {
            lines++;
            currentLineWidth = L[i];
        }
    }
    return lines;
}

int main() {
    int N, M;
    if (scanf("%d %d", &N, &M) != 2) return 1;

    int *L = (int *)malloc(N * sizeof(int));
    int maxL = 0;
    int sumL = 0;
    for (int i = 0; i < N; i++) {
        scanf("%d", &L[i]);
        if (L[i] > maxL) {
            maxL = L[i];
        }
        sumL += L[i] + (i == N - 1 ? 0 : 1);
    }

    int low = maxL;
    int high = sumL;
    int ans = high;

    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (countLines(mid, N, L) <= M) {
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    printf("%d\n", ans);

    free(L);
    return 0;
}
