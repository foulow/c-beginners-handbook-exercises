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

CLIENTE *__clientes;
size_t numero_clientes = 0;

void inicializar_manejador_cliente();
void mostrar_menu_manejador_cliente();

int main(int argc, char *argv[]) {
    printf("Programa para manejar clientes y sus telefonos:\n");

    inicializar_manejador_cliente();
    mostrar_menu_manejador_cliente();

    printf("Presiona la tecla Enter para salir...");
    getchar();

    return EXIT_SUCCESS;
}

void inicializar_manejador_cliente() {
    numero_clientes = obtener_clientes_con_telefonos(&__clientes);

}

void mostrar_menu_manejador_cliente() {
    mostrar_clientes_con_telefonos(numero_clientes, __clientes);
}