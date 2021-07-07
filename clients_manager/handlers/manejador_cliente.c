#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <libgen.h>
#include <errno.h>
#include <string.h>
#include <getopt.h>
#include <sys/types.h>
#include <json-c/json.h>

#include "../data/cliente.h"
#include "./manejador_cliente.h"

#define MEGA_BYTE 1048576 // 1024 x 1024 BYTES

size_t obtener_clientes_con_telefonos(CLIENTE **out_clientes) {
    CLIENTE *clientes = (CLIENTE*)malloc(MAX_CLIENTES * sizeof(CLIENTE));
    *out_clientes = clientes;

    for (size_t i = 0; i < MAX_CLIENTES; i++)
    {
        clientes[i].telefonos = (TELEFONO*)malloc(MAX_TELEFONOS * sizeof(TELEFONO));
    }

    FILE *fp;
    char buffer[MEGA_BYTE]; // buffer can read up to 1MB of characters.

    struct json_object *parsed_json;
    struct json_object *clientes_obj;
    struct json_object *telefonos_obj;

    struct json_object *cliente_obj;
    struct json_object *codigo_cliente_obj;
    struct json_object *nombre_cliente_obj;
    struct json_object *apellido1_cliente_obj;
    struct json_object *apellido2_cliente_obj;
    struct json_object *usuario_obj;
    struct json_object *programa_obj;
    struct json_object *fecha_actual_obj;

    struct json_object *telefono_obj;
    struct json_object *codigo_felefono_obj;
    struct json_object *numero_obj;

    fp = fopen("lista_clientes_prueba.json", "r");
    fread(buffer, MEGA_BYTE, 1, fp);
    fclose(fp);

    parsed_json = json_tokener_parse(buffer);

    json_object_object_get_ex(parsed_json, "clientes", &clientes_obj);

    size_t cantidad_clientes = json_object_array_length(clientes_obj);

    for (size_t j = 0; j < cantidad_clientes; j++) {
        cliente_obj = json_object_array_get_idx(clientes_obj, j);
        CLIENTE *cliente = (clientes + j);

        json_object_object_get_ex(cliente_obj, "codigo_cliente", &codigo_cliente_obj);
        cliente->codigo_cliente = json_object_get_int(codigo_cliente_obj);

        json_object_object_get_ex(cliente_obj, "nombre_cliente", &nombre_cliente_obj);
        strcpy(cliente->nombre_cliente, json_object_get_string(nombre_cliente_obj));

        json_object_object_get_ex(cliente_obj, "apellido1_cliente", &apellido1_cliente_obj);
        strcpy(cliente->apellido1_cliente, json_object_get_string(apellido1_cliente_obj));

        json_object_object_get_ex(cliente_obj, "apellido2_cliente", &apellido2_cliente_obj);
        strcpy(cliente->apellido2_cliente, json_object_get_string(apellido2_cliente_obj));

        json_object_object_get_ex(cliente_obj, "usuario", &usuario_obj);
        strcpy(cliente->usuario, json_object_get_string(usuario_obj));

        json_object_object_get_ex(cliente_obj, "programa", &programa_obj);
        strcpy(cliente->programa, json_object_get_string(programa_obj));

        json_object_object_get_ex(cliente_obj, "fecha_actual", &fecha_actual_obj);
        strcpy(cliente->fecha_actual, json_object_get_string(fecha_actual_obj));

        json_object_object_get_ex(cliente_obj, "telefonos", &telefonos_obj);

        size_t cantidad_telefonos = json_object_array_length(telefonos_obj);

        for (size_t k = 0; k < cantidad_telefonos; k++) {
            telefono_obj = json_object_array_get_idx(telefonos_obj, k);
            TELEFONO *telefono = (cliente->telefonos + k);

            json_object_object_get_ex(telefono_obj, "codigo_telefono", &codigo_felefono_obj);
            telefono->codigo_felefono = json_object_get_int(codigo_felefono_obj);

            json_object_object_get_ex(telefono_obj, "numero", &numero_obj);
            strcpy(telefono->numero, json_object_get_string(numero_obj));

            strcpy(telefono->usuario, cliente->usuario);
            strcpy(telefono->programa, cliente->programa);
            strcpy(telefono->fecha_actual, cliente->fecha_actual);
        }
    }

    return cantidad_clientes;
}

void obtener_cliente(long codigo_cliente, CLIENTE **out_cliente);
void registrar_cliente(CLIENTE *cliente);
void actualizar_cliente(long codigo_cliente, CLIENTE *cliente);
void eliminar_cliente(long codigo_cliente);

size_t obtener_telefonos_cliente(long codigo_cliente, TELEFONO **out_telefono);

void obtener_telefono_cliente(long codigo_cliente, long codigo_telefono, TELEFONO **out_telefono);
void agregar_telefono_cliente(TELEFONO *telefono, CLIENTE *cliente);
void actualizar_telefono_cliente(long codigo_telefono, TELEFONO *telefono);
void eliminar_telefono_cliente(long codigo_cliente);

void mostrar_clientes_con_telefonos(size_t numero_clientes, CLIENTE *clientes) {
    printf("\t Lista de clientes:\n");
    for (size_t i = 0; i < numero_clientes; i++) {
        CLIENTE *cliente = &*(clientes + i);

        printf("cliente: %lu\n", cliente->codigo_cliente);
        printf(" %s, %s,\n %s, %s,\n %s, %s\n",
            cliente->nombre_cliente, cliente->apellido1_cliente, cliente->apellido2_cliente, cliente->usuario, cliente->programa, cliente->fecha_actual);

        printf("\t Telefonos registrados para cliente: %lu\n", cliente->codigo_cliente);
        for (size_t j = 0; j < MAX_TELEFONOS; j++) {
            TELEFONO *telefono = &*(cliente->telefonos + j);

            if (telefono->codigo_felefono != j) break;

            printf("telefono: %lu\n", telefono->codigo_felefono);
            printf(" %s, %s,\n %s, %s\n",
                telefono->numero, telefono->usuario, telefono->programa, telefono->fecha_actual);
        }
        printf("\n\n");
    }
}