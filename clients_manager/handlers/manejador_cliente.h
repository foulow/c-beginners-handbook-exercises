#ifndef MANEJADOR_CLIENTE_H
#define MANEJADOR_CLIENTE_H

#include "../data/cliente.h"

CLIENTE **obtener_clientes_con_telefonos();

CLIENTE *obtener_cliente(long codigo_cliente);
void registrar_cliente(CLIENTE *cliente);
void actualizar_cliente(long codigo_cliente, CLIENTE *cliente);
void eliminar_cliente(long codigo_cliente);

TELEFONO *obtener_telefono_cliente(long codigo_cliente, long codigo_telefono);
void agregar_telefono_cliente(TELEFONO *telefono, CLIENTE *cliente);
void actualizar_telefono_cliente(long codigo_telefono, TELEFONO *telefono);
void eliminar_telefono_cliente(long codigo_cliente);

#endif