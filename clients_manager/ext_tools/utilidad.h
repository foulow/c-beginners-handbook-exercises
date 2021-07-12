#ifndef EXT_UTILIDAD_H
#define EXT_UTILIDAD_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <libgen.h>
#include <errno.h>
#include <string.h>
#include <getopt.h>
#include <sys/types.h>

#ifdef __unix__
#define CLS_COMMAND "clear"
#define UNIX_LIKE_SYSTEM 1
#elif defined(WIN32) || defined(_WIN32) || defined(__WIN32) || defined(__WIN32__) || defined(WIN64) || defined(_WIN64) || defined(__WIN64) || defined(__WIN64__)
#define CLS_COMMAND "cls"
#define UNIX_LIKE_SYSTEM 0
#endif

void limpiar_pantalla();
void limpiar_buffer_entrada();

short pausar_cualquier_input_para_seguir();
short pausar_confirmar_para_seguir();

#endif // fin de EXT_UTILIDAD_H