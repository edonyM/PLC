#include <stdio.h>

int main(int argc, char *argv[]) {
    if (argc == 1) {
        printf("no input\n");
    } else if (argc > 1 && argc < 4) {
        for (int i=0; i < argc; i++) {
            printf("argc %d: %s\n", i, argv[i]);
        }
    } else {
        printf("too many inputs\n");
    }

    return 0;
}
