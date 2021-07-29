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
#include "manejador_consumo.h"

#define JSON_FILE_NAME "lista_consumos_clientes.json"

struct json_object *__parsed_json_obj;

void mostrar_consumos_cliente(CONSUMO *from_consumos, size_t numbero_consumos, long codigo_cliente) {
    printf("Consumos para cliente codigo: %lu\n", codigo_cliente);

}

size_t *obtener_consumos_clientes(CONSUMO **out_consumos) {
    size_t *cantidad_consumos_clientes = (size_t*)malloc(MAX_CLIENTES * sizeof(size_t));
    memset(cantidad_consumos_clientes, '\0', MAX_CLIENTES * sizeof(size_t));

    FILE *fp;
    char buffer[MEGA_BYTE + 1]; // buffer can read up to 1MB with a final null.

    struct json_object *consumos_obj;

    struct json_object *consumo_obj;
    struct json_object *codigo_consumo_obj;
    struct json_object *fecha_inicio_consumo_obj;
    struct json_object *fecha_cierre_consumo_obj;
    struct json_object *kWh_conumido_obj;
    struct json_object *codigo_cliente_obj;

    fp = fopen(JSON_FILE_NAME, "r");
    fread(buffer, MEGA_BYTE, 1, fp);
    fclose(fp);

    __parsed_json_obj = json_tokener_parse(buffer);

    json_object_object_get_ex(__parsed_json_obj, "consumos", &consumos_obj);
}

void guardar_registro_consumos(CONSUMO *from_consumos, long codigo_cliente) {

}