#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {
    if (argc != 2) return 1;

    FILE *f = fopen(argv[1], "r");
    if (!f) return 1;

    char line[1024];
    int line_num = 0;
    int matches = 0;

    while (fgets(line, sizeof(line), f)) {
        line_num++;
        if (strstr(line, "FAILED") || strstr(line, "404")) {
            printf("Alert at line %d: %s", line_num, line);
            matches++;
        }
    }

    printf("\nScan complete. Total matches found: %d\n", matches);
    fclose(f);
    return 0;
}
