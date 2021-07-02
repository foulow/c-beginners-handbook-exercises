#include <stdio.h>

void showName(char *name) {
    printf("you entered name: %s\n", name);
}

int main(void) {
    char name[150];

    printf("Enter your name: ");
    while(!scanf("%s", name));

    showName(name);
}