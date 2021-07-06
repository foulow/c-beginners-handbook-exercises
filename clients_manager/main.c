#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <libgen.h>
#include <errno.h>
#include <string.h>
#include <getopt.h>
#include <sys/types.h>

#include "data/cliente.h"
#include "handlers/manejador_cliente.h"

int main(int argc, char *argv[]) {
    printf("Program to manage clients and their phone numbers:\n");

    // code here.

    printf("Press any key to exit.");
    getchar();

    return EXIT_SUCCESS;
}