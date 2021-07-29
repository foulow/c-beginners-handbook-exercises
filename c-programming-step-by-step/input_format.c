#include <stdio.h>
#include <stdlib.h>

int main() {
    char full_name[151] = {0};
    printf("Enter your full name\n <Max=150>: ");
    scanf("%150[A-Za-z ]", &full_name);
    printf("\nGreetings, %s!\n\n", full_name);

    char anything_but_enter_key[15] = {0};
    printf("Enter any keys (Enter to finish)\n <Max=14>: ");
    scanf(" %14[^\n]", &anything_but_enter_key);
    /*     ^
           |
           Leave one space to capture new line key (The '\n' character).
    */
    printf("\nYou wrote: %s\n\n", anything_but_enter_key);

    return 0;
}