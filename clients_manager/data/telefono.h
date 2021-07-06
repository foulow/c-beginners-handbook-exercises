#ifndef TELEFONO_H
#define TELEFONO_H

typedef struct {
    long codigo_felefono;
    char numero[20];
    char usuario[9];
    char programa[16];
    char fecha_actual[9];
} TELEFONO;

#endif