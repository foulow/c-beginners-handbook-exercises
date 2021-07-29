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
#include "ext_tools/utilidad.h"

CLIENTE *__clientes;
size_t __cantidad_clientes = 0;

void inicializar_manejador_cliente();

void mostrar_menu_manejador_cliente();

void mostrar_sub_menu_registrar_cliente();
void mostrar_sub_menu_agregar_telefonos();
void mostrar_sub_menu_consulta_cliente();

int main(int argc, char *argv[]) {
    printf("Programa para manejar clientes y sus telefonos:\n");

    inicializar_manejador_cliente();

    char input = EOF;
    short option = 0;

    do
    {
        mostrar_menu_manejador_cliente();

        limpiar_buffer_entrada();
        option = pausar_confirmar_para_seguir();

        limpiar_pantalla();

    } while(option == -1);

    limpiar_pantalla();
    free(__clientes);

    return EXIT_SUCCESS;
}

void inicializar_manejador_cliente() {
    __cantidad_clientes = obtener_clientes_con_telefonos(&__clientes);
}

void mostrar_menu_manejador_cliente() {
    /*
        Lista de opciones:
            1- Registrar cliente.
            2- Consultar clientes.
            3- Salir.
    */

    short option = 0;
    do
    {
        limpiar_pantalla();

        printf("Seleccione una opcion <1-3>:\n");
        printf("\t1- Registrar cliente.\n");
        printf("\t2- Consultar clientes.\n");
        printf("\t3- Salir. <o EOF>\n\n");

        limpiar_buffer_entrada();
        scanf("%hd", &option);

        switch (option)
        {
        case 1:
            mostrar_sub_menu_registrar_cliente();
            limpiar_buffer_entrada();
            pausar_cualquier_input_para_seguir();
            break;
        case 2:
            mostrar_clientes_con_telefonos(__clientes, __cantidad_clientes);
            limpiar_buffer_entrada();
            pausar_cualquier_input_para_seguir();
            break;
        case 3:
            limpiar_buffer_entrada();
            option = -1;
            break;
        default:
            limpiar_buffer_entrada();
            break;
        }
    } while (option != -1);
}

void mostrar_sub_menu_registrar_cliente() {
    if (__cantidad_clientes >= MAX_CLIENTES) {
        printf("Error: Limite maximo de clientes alcanzado.\n");
        limpiar_buffer_entrada();
        pausar_cualquier_input_para_seguir();

        return;
    }

    limpiar_pantalla();

    // cc => cantidad de clientes agredados. [min = 0, max = 1]
    u_short cc = registrar_cliente(__clientes, __cantidad_clientes);

    if (cc) {
        // ct => cantidad de telefonos agregados. [min = 0, max = 20]
        u_short ct = agregar_telefono_cliente(&__clientes[__cantidad_clientes]);

        if (ct) {
            __clientes[__cantidad_clientes].cantidad_telefonos += ct;

            guardar_registro_clientes(__clientes, __cantidad_clientes);

            __cantidad_clientes += cc;
        }
    }
}

void mostrar_sub_menu_agregar_telefonos();

void mostrar_sub_menu_consulta_cliente() {
    /*
        Lista de opciones:
            1- Mostrar todos los clientes con telefonos.
            2- Mostrar cliente con telefonos.
            3- Mostrar telefonos cliente.
            4- Mostrar telefono cliente.
            5- Salir.
    */

    short option = 0;
    do
    {
        limpiar_pantalla();

        printf("Seleccione una opcion <1-6>:\n");
        printf("\t1- Mostrar todos los clientes con telefonos.\n");
        printf("\t2- Mostrar cliente con telefonos.\n");
        printf("\t3- Mostrar cliente\n");
        printf("\t4- Mostrar telefonos cliente.\n");
        printf("\t5- Mostrar telefono cliente.\n");
        printf("\t6- Salir. <o EOF>\n\n");

        limpiar_buffer_entrada();
        scanf("%hd", &option);

        switch (option)
        {
        case 1:
            mostrar_clientes_con_telefonos(__clientes, __cantidad_clientes);
            break;
        case 2:
            // mostrar_cliente_con_telefonos();
            break;
        case 3:
            // mostrar_cliente();
            break;
        case 4:
            // mostrar_telefonos_cliente();
            break;
        case 5:
            // mostrar_telefono_cliente();
            break;
        case 6:
            option = -1;
            break;
        default:
            break;
        }
        limpiar_buffer_entrada();
        pausar_cualquier_input_para_seguir();

    } while (option != -1);
}