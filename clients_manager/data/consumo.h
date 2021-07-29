#ifndef CONSUMO_H
#define CONSUMO_H

#define CARGO_FIJO_0_A_100_KWH 26.35
#define CARGO_FIJO_101_O_MAS_KWH 97.19

typedef struct {
    long codigo_consumo;
    char fecha_inicio[10];  // cada factura se genera el 1ro de cada mes.
    char fecha_cierre[10];
    long kWh_conumido;
    long codigo_cliente;
} CONSUMO;

#endif