#include <stdio.h>
#include <stdlib.h>

#define MAXN 1000005
#define LOGN 21

typedef struct {
    int to;
    int next;
} Edge;

Edge edges[MAXN * 2];
int head[MAXN];
int edge_cnt;
long long guards[MAXN];
long long S[MAXN];
int up[MAXN][LOGN];
int queue[MAXN];

void add_edge(int u, int v) {
    edges[++edge_cnt].to = v;
    edges[edge_cnt].next = head[u];
    head[u] = edge_cnt;
}

void solve() {
    int N;
    if (scanf("%d", &N) != 1) return;

    edge_cnt = 0;
    for (int i = 1; i <= N; i++) {
        head[i] = 0;
        up[i][0] = -1; 
    }

    for (int i = 0; i < N - 1; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        add_edge(u, v);
        add_edge(v, u);
    }

    for (int i = 1; i <= N; i++) {
        scanf("%lld", &guards[i]);
    }

    int front = 0, back = 0;
    queue[back++] = 1;
    up[1][0] = 0; 
    S[1] = guards[1];

    while (front < back) {
        int u = queue[front++];
        for (int i = head[u]; i; i = edges[i].next) {
            int v = edges[i].to;
            if (up[v][0] == -1) {
                up[v][0] = u;
                S[v] = S[u] + guards[v];
                queue[back++] = v;
            }
        }
    }

    for (int j = 1; j < LOGN; j++) {
        for (int i = 1; i <= N; i++) {
            int mid = up[i][j - 1];
            if (mid != 0) up[i][j] = up[mid][j - 1];
            else up[i][j] = 0;
        }
    }

    int Q;
    scanf("%d", &Q);
    while (Q--) {
        int U;
        long long X;
        scanf("%d %lld", &U, &X);

        long long threshold = S[U] - X;
        int curr = U;

  
        for (int j = LOGN - 1; j >= 0; j--) {
            int ancestor = up[curr][j];
            if (ancestor != 0 && S[ancestor] > threshold) {
                curr = ancestor;
            }
        }
        printf("%d\n", curr);
    }
}

int main() {
    int T;
    if (scanf("%d", &T) != 1) return 0;
    while (T--) {
        solve();
    }
    return 0;
}
