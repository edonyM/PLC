#include <stdio.h>

int main(int argc, char *argv[]) {
    for (int i=1; i < argc; ++i) {
        printf("arg %d: %s\n", i, argv[i]);
    }
    // let's make our own array of strings
    char *states[] = {
        "California", "Oregon",
        "Washington", "Texas"
    };
    for (int i=0; i < 4; ++i) {
        printf("states %d: %s\n", i, states[i]);
    }
}
