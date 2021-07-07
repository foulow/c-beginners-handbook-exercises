#ifndef MANEJADOR_CLIENTE_H
#define MANEJADOR_CLIENTE_H

#include "../data/cliente.h"

#define MAX_CLIENTES 500
#define MAX_TELEFONOS 20

size_t obtener_clientes_con_telefonos(CLIENTE **out_clientes);

void obtener_cliente(long codigo_cliente, CLIENTE **out_cliente);
void registrar_cliente(CLIENTE *cliente);
void actualizar_cliente(long codigo_cliente, CLIENTE *cliente);
void eliminar_cliente(long codigo_cliente);

size_t obtener_telefonos_cliente(long codigo_cliente, TELEFONO **out_telefono);

void obtener_telefono_cliente(long codigo_cliente, long codigo_telefono, TELEFONO **out_telefono);
void agregar_telefono_cliente(TELEFONO *telefono, CLIENTE *cliente);
void actualizar_telefono_cliente(long codigo_telefono, TELEFONO *telefono);
void eliminar_telefono_cliente(long codigo_cliente);

void mostrar_clientes_con_telefonos();

#endif