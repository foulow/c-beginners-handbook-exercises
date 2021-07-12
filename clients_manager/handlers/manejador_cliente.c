#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <libgen.h>
#include <errno.h>
#include <string.h>
#include <getopt.h>
#include <sys/types.h>
#include <json-c/json.h>
#include <time.h>

#include "../data/cliente.h"
#include "../ext_tools/utilidad.h"
#include "./manejador_cliente.h"

#define MEGA_BYTE 1048576 // 1024 x 1024 BYTES
#define JSON_FILE_NAME "lista_clientes_prueba.json"

struct json_object *__parsed_json_obj;
struct json_object *__cantidad_clientes_obj;

void _mostrar_datos_cliente(CLIENTE const cliente) {
    printf("Datos para cliente: %lu\n", cliente.codigo_cliente);
        printf(" %s, %s,\n %s, %s,\n %s, %s\n",
            cliente.nombre_cliente, cliente.apellido1_cliente,
            cliente.apellido2_cliente, cliente.usuario,
            cliente.programa, cliente.fecha_actual);
}

void _mostrar_datos_telefono(TELEFONO const telefono) {
    printf("Datos del telefono: %lu\n", telefono.codigo_felefono);
    printf(" %s, %s,\n %s, %s\n",
        telefono.numero, telefono.usuario,
        telefono.programa, telefono.fecha_actual);
}

// Funciones para el muestreo de datos
void mostrar_clientes_con_telefonos(CLIENTE *from_clientes, size_t numero_clientes) {
    printf("\t Lista de clientes:\n");
    for (size_t i = 0; i < numero_clientes; i++) {
        CLIENTE *cliente = &*(from_clientes + i);

        _mostrar_datos_cliente(*cliente);

        printf("\t Telefonos registrados para cliente: %lu\n", cliente->codigo_cliente);
        for (size_t j = 0; j < MAX_TELEFONOS; j++) {
            TELEFONO *telefono = &*(cliente->telefonos + j);

            if (telefono->codigo_felefono != j) break;

            _mostrar_datos_telefono(*telefono);
        }
        printf("\n\n");
    }
    limpiar_buffer_entrada();
    pausar_cualquier_input_para_seguir();
}

void mostrar_cliente_con_telefonos(CLIENTE *from_clientes, long codigo_cliente) {
    CLIENTE *cliente = &*(from_clientes + codigo_cliente);

    _mostrar_datos_cliente(*cliente);

    printf("\t Telefonos registrados para cliente: %lu\n", cliente->codigo_cliente);
    for (size_t j = 0; j < MAX_TELEFONOS; j++) {
        TELEFONO *telefono = &*(cliente->telefonos + j);

        if (telefono->codigo_felefono != j) break;

        _mostrar_datos_telefono(*telefono);
    }
    printf("\n\n");
}

void mostrar_cliente(CLIENTE *from_clientes, long codigo_cliente) {
    CLIENTE *cliente = &*(from_clientes + codigo_cliente);

    _mostrar_datos_cliente(*cliente);

    printf("\n\n");
}

void mostrar_telefonos_cliente(CLIENTE *from_clientes, long codigo_cliente) {
    CLIENTE *cliente = &*(from_clientes + codigo_cliente);

    printf("\t Telefonos registrados para cliente: %lu\n", cliente->codigo_cliente);
    for (size_t j = 0; j < MAX_TELEFONOS; j++) {
        TELEFONO *telefono = &*(cliente->telefonos + j);

        if (telefono->codigo_felefono != j) break;

        _mostrar_datos_telefono(*telefono);
    }
    printf("\n\n");
}

void mostrar_telefono_cliente(CLIENTE *from_clientes, long codigo_cliente, long codigo_telefono) {
    CLIENTE *cliente = &*(from_clientes + codigo_cliente);

    TELEFONO *telefono = &*(cliente->telefonos + codigo_telefono);

    _mostrar_datos_telefono(*telefono);

    printf("\n\n");
}


// Funciones para el manejo de clientes
size_t obtener_clientes_con_telefonos(CLIENTE **out_clientes) {
    CLIENTE *clientes = (CLIENTE*)malloc(MAX_CLIENTES * sizeof(CLIENTE));
    memset(clientes, '\0', MAX_CLIENTES * sizeof(CLIENTE));
    *out_clientes = clientes;

    for (size_t i = 0; i < MAX_CLIENTES; i++)
    {
        clientes[i].telefonos = (TELEFONO*)malloc(MAX_TELEFONOS * sizeof(TELEFONO));
        memset(clientes[i].telefonos, '\0', MAX_TELEFONOS * sizeof(TELEFONO));
    }

    FILE *fp;
    char buffer[MEGA_BYTE + 1]; // buffer can read up to 1MB with a final null.

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

    fp = fopen(JSON_FILE_NAME, "r");
    fread(buffer, MEGA_BYTE, 1, fp);
    fclose(fp);

    __parsed_json_obj = json_tokener_parse(buffer);

    json_object_object_get_ex(__parsed_json_obj, "clientes", &clientes_obj);

    size_t cantidad_clientes = json_object_array_length(clientes_obj);

    for (size_t j = 0; j < cantidad_clientes; j++) {
        cliente_obj = json_object_array_get_idx(clientes_obj, j);
        CLIENTE *cliente = &*(clientes + j);

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

        cliente->cantidad_telefonos = json_object_array_length(telefonos_obj);

        for (size_t k = 0; k < cliente->cantidad_telefonos; k++) {
            telefono_obj = json_object_array_get_idx(telefonos_obj, k);
            TELEFONO *telefono = &*(cliente->telefonos + k);

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

u_short registrar_cliente(CLIENTE *for_clientes, size_t cantidad_clientes) {
    printf("\n\nPantalla de registro de cliente:\n");
    for_clientes[cantidad_clientes].codigo_cliente = cantidad_clientes;

    printf("Digite el nombre: ");
    limpiar_buffer_entrada();
    scanf("%30s", for_clientes[cantidad_clientes].nombre_cliente);

    printf("Digite el primer apellido: ");
    limpiar_buffer_entrada();
    scanf("%20s", for_clientes[cantidad_clientes].apellido1_cliente);

    printf("Digite el segundo apellido: ");
    limpiar_buffer_entrada();
    scanf("%20s", for_clientes[cantidad_clientes].apellido2_cliente);

    printf("Digite el usuario: ");
    limpiar_buffer_entrada();
    scanf("%8s", for_clientes[cantidad_clientes].usuario);

    printf("Digite el programa: ");
    limpiar_buffer_entrada();
    scanf("%15s", for_clientes[cantidad_clientes].programa);

    char date_str[10];
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    char day_str[3];
    snprintf(day_str, 3, "%d", tm.tm_mday);
    strcpy(date_str, day_str);
    strcat(date_str, "/");
    char month_str[3];
    snprintf(month_str, 3, "%d", tm.tm_mon + 1);
    strcat(date_str, month_str);
    strcat(date_str, "/");
    char year_str[5];
    snprintf(year_str, 5, "%d", tm.tm_year + 1900);
    strcat(date_str, year_str);
    strcpy(for_clientes[cantidad_clientes].fecha_actual, date_str);

    return 1;
}

u_short eliminar_cliente(CLIENTE *from_clientes, long codigo_cliente);

u_short actualizar_cliente(CLIENTE *from_clientes, long codigo_cliente);


// Funciones para el manejo de telefonos
size_t obtener_telefonos_cliente(TELEFONO **out_telefono, long codigo_cliente);

u_short agregar_telefono_cliente(CLIENTE *for_cliente) {
    TELEFONO *for_telefonos = for_cliente->telefonos;
    ssize_t cantidad_telefonos = for_cliente->cantidad_telefonos;

    limpiar_pantalla();

    printf("\n\nPantalla de registro de telefonos:\n");

    char input = EOF;
    for (size_t i = cantidad_telefonos; i < MAX_TELEFONOS; i++)
    {
        printf("Registro de telefono <%lu/%d>:\n", i+1, MAX_TELEFONOS);
        for_telefonos[i].codigo_felefono = i;

        printf("Digite el numero: ");
        limpiar_buffer_entrada();
        scanf("%20s", for_telefonos[i].numero);

        strcpy(for_telefonos[i].usuario, for_cliente->usuario);

        strcpy(for_telefonos[i].programa, for_cliente->programa);

        strcpy(for_telefonos[i].fecha_actual, for_cliente->fecha_actual);

        printf("Deseas seguir agregando mas telefonos? Si<S,s>:\n\n");
        getchar();
        limpiar_buffer_entrada();
        input = getchar();

        if (input != 's' && input != 'S' && input != EOF) {
            cantidad_telefonos = i+1;
            break;
        }
    }

    return cantidad_telefonos;
}

u_short eliminar_telefono_cliente(TELEFONO *from_telefonos, long codigo_telefono);
u_short actualizar_telefono_cliente(TELEFONO *from_telefonos, long codigo_telefono);


// Funciones para la persistencia de datos
void guardar_registro_clientes(CLIENTE *from_clients, long codigo_cliente) {
    CLIENTE *cliente = &*(from_clients + codigo_cliente);
    struct json_object *clientes_obj;
    json_object_object_get_ex(__parsed_json_obj, "clientes", &clientes_obj);

    char *json_str = (char*)malloc(MEGA_BYTE * sizeof(char));
    memset(json_str, '\0', MEGA_BYTE * sizeof(char));

    strcpy(json_str, "{ ");
    strcat(json_str, "\"codigo_cliente\": ");
    char codigo_cliente_str[4];
    snprintf(codigo_cliente_str, 4, "%lu", cliente->codigo_cliente);
    strcat(json_str, codigo_cliente_str);
    strcat(json_str, ", \"nombre_cliente\": \"");
    strcat(json_str, cliente->nombre_cliente);
    strcat(json_str, "\", \"apellido1_cliente\": \"");
    strcat(json_str, cliente->apellido1_cliente);
    strcat(json_str, "\", \"apellido2_cliente\": \"");
    strcat(json_str, cliente->apellido2_cliente);
    strcat(json_str, "\", \"usuario\": \"");
    strcat(json_str, cliente->usuario);
    strcat(json_str, "\", \"programa\": \"");
    strcat(json_str, cliente->programa);
    strcat(json_str, "\", \"fecha_actual\": \"");
    strcat(json_str, cliente->fecha_actual);
    strcat(json_str, "\", \"cantidad_telefonos\": ");
    char cantidad_telefonos_str[3];
    snprintf(cantidad_telefonos_str, 3, "%lu", cliente->cantidad_telefonos);
    strcat(json_str, cantidad_telefonos_str);
    strcat(json_str, ", \"telefonos\": [ ");
    for (size_t i = 0; i < cliente->cantidad_telefonos; i++)
    {
        TELEFONO *telefono = &*(cliente->telefonos + i);

        if (i == 0)
            strcat(json_str, "{ ");
        else
            strcat(json_str, ", { ");
        strcat(json_str, "\"codigo_telefono\": ");
        char codigo_telefono_str[3];
        snprintf(codigo_telefono_str, 3, "%lu", telefono->codigo_felefono);
        strcat(json_str, codigo_telefono_str);
        strcat(json_str, ", \"numero\": \"");
        strcat(json_str, telefono->numero);
        strcat(json_str, "\", \"usuario\": \"");
        strcat(json_str, telefono->usuario);
        strcat(json_str, "\", \"programa\": \"");
        strcat(json_str, telefono->programa);
        strcat(json_str, "\", \"fecha_actual\": \"");
        strcat(json_str, telefono->fecha_actual);
        strcat(json_str, "\" }");
    }
    strcat(json_str, " ] }");

    struct json_object *new_cliente_obj = json_tokener_parse(json_str);
    json_object_array_add(clientes_obj, new_cliente_obj);

    json_object_to_file_ext(JSON_FILE_NAME, __parsed_json_obj, JSON_C_TO_STRING_PRETTY_TAB);
}