#include <stdio.h>
#include <math.h>

int isPrime(int);

int main() {
    int counter;
    for (counter = 1; counter <= 100; counter++)
        if (isPrime(counter))
            printf("%d is Prime.\n", counter);

    return 0;
}

int isPrime(int n) {
    int i;
    for (i = 0; i < sqrt(n); i++)
        if (n % i == 0)
            return 0;

    return 1;
}