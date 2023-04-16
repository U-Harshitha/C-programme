#include <stdio.h>

int a[200];
int b[100];
int n, m;

void insert(int ele, int p) {
    for (int i = n - 1; i >= p; i--) {
        a[i+1] = a[i];
    }
    a[p] = ele;
    n++;
}

int main() {
    int i, j, t;
    scanf("%d", &n);
    printf("Enter A: ");
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);
    scanf("%d", &m);
    printf("Enter B: ");
    for (i = 0; i < m; i++)
        scanf("%d", &b[i]);

    for (i = 0; i < n - 1; i++)
        for (j = 0; j < n - i - 1; j++)
            if (a[j] > a[j + 1]) {
                t = a[j];
                a[j] = a[j + 1];
                a[j + 1] = t;
            }
    for (j = 0; j < m; j++) {
        for (i = 0; i < n; i++) {
            if (b[j] < a[i]) {
                insert(b[j], i);
                break;
            }
        }
        if (i == n) {
            insert(b[j], n);
        }
    }
    printf("Merged and sorted array: ");
    for (i = 0; i < n ; i++)
        printf("%d ", a[i]);

    return 0;
}
