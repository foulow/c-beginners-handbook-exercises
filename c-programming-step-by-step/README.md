# NOTES

## Compilation commands

To compile all .c files in a directory you currently are use:

```bash
$> gcc -c *.c
```

> Command args: -c => compile

## Library creation commands

For archiving .o files to create a library use:

```bash
$> ar -cvq lib<YOUR_LIB_NAME>.a *.o
```

> Command args: -c => silence mode, v => verbose, q => quick
