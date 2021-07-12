#include <stdio.h>

typedef struct {
    int age;
    char *name;
} PERSON;

int main(void) {
    PERSON flavio = { 37, "Flavio" };

    printf("%s, age %u", flavio.name, flavio.age);
}