#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <libgen.h>
#include <errno.h>
#include <string.h>
#include <getopt.h>
#include <sys/types.h>

#include "../data/cliente.h"
#include "./manejador_cliente.h"

CLIENTE **__clientes;

CLIENTE **obtener_clientes_con_telefonos();

CLIENTE *obtener_cliente(long codigo_cliente);
void registrar_cliente(CLIENTE *cliente);
void actualizar_cliente(long codigo_cliente, CLIENTE *cliente);
void eliminar_cliente(long codigo_cliente);

TELEFONO *obtener_telefono_cliente(long codigo_cliente, long codigo_telefono);
void agregar_telefono_cliente(TELEFONO *telefono, CLIENTE *cliente);
void actualizar_telefono_cliente(long codigo_telefono, TELEFONO *telefono);
void eliminar_telefono_cliente(long codigo_cliente);