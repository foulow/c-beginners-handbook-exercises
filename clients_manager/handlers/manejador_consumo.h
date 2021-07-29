#ifndef MANEJADOR_CONSUMO_H
#define MANEJADOR_CONSUMO_H

#include "../data/consumo.h"
#include "../ext_tools/definiciones.h"

void mostrar_consumos_cliente(CONSUMO *from_consumos, size_t numbero_consumos, long codigo_cliente);

size_t *obtener_consumos_clientes(CONSUMO **out_consumos);

void guardar_registro_consumos(CONSUMO *from_consumos, long codigo_cliente);

#endif