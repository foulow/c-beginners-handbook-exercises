#include <stdio.h>
#include <stdlib.h>

int main() {
    int *p;
    int n;
    printf("Enter how many numbers you want to allocate: ");
    scanf("%d", &n);

    p = (int *)malloc(n * sizeof(int));
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
    free(p);

    return 0;
}