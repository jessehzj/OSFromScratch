CC = gcc
LD = ld
CFLAGS = -std=c99 -pedantic -Wall -nostdlib -ffreestanding -m32
LDFLAGS = -T kernel.ld -nostdlib -n -melf_i386
OBJS = kernel.o
.PHONY: all
all: kernel
%.o: %.c
	${CC} -c ${CFLAGS} $<
kernel: $(OBJS) kernel.ld
	${LD} ${LDFLAGS} -o kernel ${OBJS}
clean:
	rm -f ${OBJS} kernel
