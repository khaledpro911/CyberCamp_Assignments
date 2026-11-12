#include <stdio.h>
#include <ctype.h>

int main(int argc, char *argv[]) {
    if (argc != 2) return 1;

    FILE *f = fopen(argv[1], "rb");
    if (!f) return 1;

    unsigned char buf[16];
    size_t n;
    long offset = 0;

    while ((n = fread(buf, 1, 16, f)) > 0) {
        printf("%08lx: ", offset);
        for (size_t i = 0; i < 16; i++) {
            if (i < n) printf("%02x ", buf[i]);
            else printf("   ");
        }
        for (size_t i = 0; i < n; i++) {
            printf("%c", isprint(buf[i]) ? buf[i] : '.');
        }
        printf("\n");
        offset += 16;
    }

    fclose(f);
    return 0;
}
