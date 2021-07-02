#include <stdio.h>

int main(void) {
    int prices[5];

    for (int i = 0; i < 5; i++) {
        prices[i] = i + 1;
        printf("prices[%d] = %d\n", i, prices[i]);
    }
}