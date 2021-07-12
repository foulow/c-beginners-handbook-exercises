#include "./utilidad.h"

void limpiar_pantalla() {
    system(CLS_COMMAND);
}

void limpiar_buffer_entrada() {
#if UNIX_LIKE_SYSTEM
    fflush(stdin);
#else
    __fpurge(stdin);
#endif
}
short pausar_cualquier_input_para_seguir() {
    printf("Presiona la tecla Enter para continuar...\n\n");
    limpiar_buffer_entrada();
    getchar();

    return 0;
}

short pausar_confirmar_para_seguir() {
    char input = EOF;

    printf("Estas seguro que desea salir? Si<S,s>:\n\n");
    limpiar_buffer_entrada();
    input = getchar();

    if (input != 'y' && input != 'Y' && input != EOF)
        return -1;
    else
        return 0;
}