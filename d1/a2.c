#include <stdio.h>
#include <stdlib.h>

int isP(int n) {
    if (n <= 1) return 0;
    for (int i = 2; i * i <= n; i++)
        if (n % i == 0) return 0;
    return 1;
}

int sumP(int *a, int n) {
    int s = 0;
    for (int i = 0; i < n; i++)
        if (isP(a[i])) s += a[i];
    return s;
}

int main() {
    int n, *a, s;
    scanf("%d", &n);
    a = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
    s = sumP(a, n);
    printf("%d\n", s);
    free(a);
    return 0;
}
