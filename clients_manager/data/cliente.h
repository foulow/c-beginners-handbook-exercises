#ifndef CLIENTE_H
#define CLIENTE_H

#include "./telefono.h"

typedef struct {
    long codigo_cliente;
    char nombre_cliente[31];
    char apellido1_cliente[21];
    char apellido2_cliente[21];
    char usuario[9];
    char programa[16];
    char fecha_actual[9];
    TELEFONO *telefono;
} CLIENTE;

#endif