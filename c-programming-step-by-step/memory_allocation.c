#include <stdio.h>
#include <stdlib.h>

int main() {
    int *p;
    int n;
    printf("How many numbers you want to allocate? ");
    scanf("%d", &n);

    p = (int *)calloc(n, sizeof(int));
    if (p == NULL) {
        printf("Unable to allocate memory\n Exiting the program...\n");
        exit(1);
    }

    printf("Enter numbers for the array:\n");
    int i;
    for (i = 0; i < n; i++) {
        printf("<%d/%d>: ", i+1, n);
        scanf("%d", p+i);
    }

    printf("Content of the array entered:\n[");
    for (i = 0; i < n; i++) {
        if (i != n-1) printf("%4d,", *(p+i));
        else printf("%4d]\n", *(p+i));
    }

    int new_n;
    printf("How many new elements you want to add? ");
    scanf("%d", &new_n);
    new_n += n;

    p = (int *)realloc(p, new_n * sizeof(int));
    if (p == NULL) {
        printf("Unable to allocate memory\n Exiting the program...\n");
        exit(1);
    }

    printf("Enter the new numbers for the array:\n");
    for (i = n; i < new_n; i++) {
        printf("<%d/%d>: ", i+1, new_n);
        scanf("%d", p+i);
    }

    printf("Content of the array entered:\n[");
    for (i = 0; i < new_n; i++) {
        if (i != new_n-1) printf("%4d,", *(p+i));
        else printf("%4d]\n", *(p+i));
    }
    free(p);

    return 0;
}