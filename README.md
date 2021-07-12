# c-beginners-handbook-exercises

A quick repo with my exercises' solutions for the c beginners handbook.

## Book examples

To compile all files use `Make` to generate the executable bin files for each example.

```bash
$> cd examples
$> make all
```

> Note: this makefile was make to be use on linux systems, make any changes necessary to use it for your OS.

## clients_manager

To compile this project enter the following command in a terminal with gcc installed.

```bash
$> cd clients_manager
$> gcc main.c ./ext_tools/utilidad.c ./handlers/manejador_cliente.c -ljson-c -o client_manager.out
```
