#include <stdio.h>
/*
    Count number of set bits in a number.
    for type int with size of 32 bits:
        -1 will have 32 bits set.
         5 will have  5 bits set.
         ...
*/
void printBinary(int n);

int main() {
    printf("Enter a number to count the number of bits set: ");
    int x;
    scanf("%d", &x);

    int i, count = 0;
    for (i = 0; i < sizeof(int) * 8; ++i) {
        if ( (x & (1 << i)) == (1 << i))
            count++;
    }

    printf("Total set bits for %d is: %d\n", x, count);
    printBinary(x);
    return 0;
}

void printBinary(int n) {
    int i;
    unsigned k = 1 << 31;
    for (i = 0; i < sizeof(int) * 8; i++) {
        // Prints a 1 or 0 if set on given number.
        if ( (n & (k >> i)) == (k >> i) )
            printf("1");
        else
            printf("0");

        // Prints a white space on each 8 bits.
        if ( (i+1) % 8 == 0)
            printf(" ");
    }
    printf("\n");
}
