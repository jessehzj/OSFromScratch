/* 2018/7/7/00:04 huangzhijie at zongyuejiayuan */
/** simple kernel from scratch */


#define GRUB_MAGIC 0x1BADB002
#define GRUB_FLAGS 0x0
#define GRUB_CHECKSUM (-1 * (GRUB_MAGIC + GRUB_FLAGS))

struct grub_signature {
    unsigned int magic;
    unsigned int flags;
    unsigned int checksum;
};

struct grub_signature gs __attribute__ ((section (".grub_sig"))) = {
    GRUB_MAGIC,
    GRUB_FLAGS,
    GRUB_CHECKSUM
};

void puts( const char *s, int color){
    volatile char *buffer = (volatile char*)0xB8000;

    while( *s != 0 ) {
        *buffer++ = *s++;
        *buffer++ = color;
    }
}


void main (void) {
    puts("Hello World!", 0x7);
    while (1);
}
