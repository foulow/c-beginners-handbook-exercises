# executables
MD = mkdir
RM = rm
CC = gcc

# config
CFLAGS = -O2 -Wall -Werror
SRCS = $(wildcard *.c)
OUT_DIR = bin

# rules
.PHONY: all clean

all: $(SRCS:.c=)

.c:
	$(MD) -p $(@D)/$(OUT_DIR)
	$(CC) $(CFLAGS) $< -o $(OUT_DIR)/$@.out

clean:
	$(RM) -rf $(OUT_DIR)