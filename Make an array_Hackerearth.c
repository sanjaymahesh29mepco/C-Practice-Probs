#include <stdio.h>
#include <stdbool.h>
#include <malloc.h>

long long solve(int N, int* A) {
    long long sum = 0;
    int max_val = 0;


    for (int i = 0; i < N; i++) {
        sum += A[i];
        if (A[i] > max_val) {
            max_val = A[i];
        }
    }

    if (N == 1) {
        return (A[0] == 0) ? 0 : -1;
    }


    if (sum % (N - 1) != 0) {
        return -1;
    }

    long long K = sum / (N - 1);

    if (K < max_val) {
        return -1;
    }

    return K;
}

int main() {
    int T;
    if (scanf("%d", &T) != 1) return 0;
    for (int t_i = 0; t_i < T; t_i++) {
        int N;
        if (scanf("%d", &N) != 1) break;
        int *A = (int *)malloc(sizeof(int) * N);
        for (int i_A = 0; i_A < N; i_A++) {
            scanf("%d", &A[i_A]);
        }

        long long out_ = solve(N, A);
        printf("%lld\n", out_);
        free(A);
    }
    return 0;
}
