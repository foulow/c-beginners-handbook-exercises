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

#ifdef WIN32 || _WIN32 || __WIN32 || __WIN32__ || WIN64 || _WIN64 || __WIN64 || __WIN64__
#define CLS_COMMAND "cls"
#define UNIX_LIKE_SYSTEM 0
#elif unix || _unix || __unix || __unix__ || linux || _linux || __linux || __linux__ || __APPLE__ || __MACH__ || __CYGWIN__
#define CLS_COMMAND "clear"
#define UNIX_LIKE_SYSTEM 1
#endif

void limpiar_pantalla();
void limpiar_buffer_entrada();

short pausar_cualquier_input_para_seguir();
short pausar_confirmar_para_seguir();

#endif // fin de EXT_UTILIDAD_H