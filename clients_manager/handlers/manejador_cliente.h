#ifndef MANEJADOR_CLIENTE_H
#define MANEJADOR_CLIENTE_H

#include "../data/cliente.h"

#define MAX_CLIENTES 500
#define MAX_TELEFONOS 20

// Funciones para el muestreo de datos
void mostrar_clientes_con_telefonos(CLIENTE *from_clientes, size_t numero_clientes);
void mostrar_cliente_con_telefonos(CLIENTE *from_clientes, long codigo_cliente);
void mostrar_cliente(CLIENTE *from_clientes, long codigo_cliente);
void mostrar_telefonos_cliente(CLIENTE *from_clientes, long codigo_cliente);
void mostrar_telefono_cliente(CLIENTE *from_clientes, long codigo_cliente, long codigo_telefono);


// Funciones para el manejo de clientes
size_t obtener_clientes_con_telefonos(CLIENTE **out_clientes);

u_short registrar_cliente(CLIENTE **for_clientes, size_t cantidad_clientes);
u_short eliminar_cliente(CLIENTE **from_clientes, long codigo_cliente);
u_short actualizar_cliente(CLIENTE **from_clientes, long codigo_cliente);


// Funciones para el manejo de telefonos
size_t obtener_telefonos_cliente(TELEFONO **out_telefono, long codigo_cliente);

u_short agregar_telefono_cliente(TELEFONO **for_telefonos, size_t cantidad_telefonos);
u_short eliminar_telefono_cliente(TELEFONO **from_telefonos, long codigo_telefono);
u_short actualizar_telefono_cliente(TELEFONO **from_telefonos, long codigo_telefono);


// Funciones para la persistencia de datos
void guardar_registro_clientes(CLIENTE *from_clients, long codigo_cliente);

#endif // fin de MANEJADOR_CLIENTE_H