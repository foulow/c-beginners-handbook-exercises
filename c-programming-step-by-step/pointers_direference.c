#include <stdio.h>

int main() {
    int x[] = {10, 20, 30};
    int *p, k;
    p = x;
    printf("x[] = {%d,%d,%d} | ", x[0], x[1], x[2]);
    printf("p=&x => %lu\n", p);

    k = ++(*p);
    printf("k = ++(*p) => k=%d *p=%d p=%lu x[0]=%d x[1]=%d x[2]=%d\n", k, *p, p, x[0], x[1], x[2]);
    k = *++p;
    printf("k = *++p   => k=%d *p=%d p=%lu x[0]=%d x[1]=%d x[2]=%d\n", k, *p, p, x[0], x[1], x[2]);
    k = *p++;
    printf("k = *p++   => k=%d *p=%d p=%lu x[0]=%d x[1]=%d x[2]=%d\n", k, *p, p, x[0], x[1], x[2]);
    k = (*p)++;
    printf("k = (*p)++ => k=%d *p=%d p=%lu x[0]=%d x[1]=%d x[2]=%d\n", k, *p, p, x[0], x[1], x[2]);

    return 0;
}