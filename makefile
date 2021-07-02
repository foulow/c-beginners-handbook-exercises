# executables
MD = mkdir
RM = rm
CC = gcc

# config
CFLAGS = -O2 -Wall -Werror
SRCS = $(wildcard *.c)
OUT_DIR = bin
OUT_EXT = out
# rules
.PHONY: all clean

all: $(SRCS:.c=)

.c:
	$(MD) -p $(@D)/$(OUT_DIR)
	$(CC) $(CFLAGS) $< -o $(OUT_DIR)/$@.$(OUT_EXT)

clean:
	$(RM) -rf $(OUT_DIR)
