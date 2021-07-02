#include <stdio.h>

#define DEBUG 0

int main(int argc, char const *argv[])
{
    #if DEBUG
        printf("Debug message called!\n");
    #else
        printf("Production message called!\n");
    #endif

    return 0;
}
