#include <stdio.h>
int graph[25][25] = {0};
int visit[25][25] = {0};
int queue[25], f = 0, r = -1;

void enque(int k) {
    queue[++r] = k;
}

int deque() {
    return queue[f++];
}
int isempty() {
    return f > r ? 0 : 1;
}

int main() {
    int n, p, a, b, h, i, j;
    printf("Enter no.of vertices and edges: ");
    scanf("%d %d", &n, &p);
    printf("Enter source and destination of the edge:\n");
    while (p--) {
        scanf("%d %d", &a, &b);
        graph[a][b] = 1;
        graph[b][a] = 1;
    }
    printf("Enter starting vertex index: ");
    scanf("%d", &h);
    enque(h);
    while (isempty()) {
        h = deque();
        for (i = 0; i < n; i++) {
            if (graph[h][i] && !visit[h][i]) {
                enque(i);
                visit[h][i] = 1;
                visit[i][h] = 1;
            }
        }
    }
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++)
            printf("%d ", visit[i][j]);
        printf("\n");
    }
    return 0;
}
