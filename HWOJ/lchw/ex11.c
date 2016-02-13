#include <stdio.h>

int main(int argc, char *argv[]) {
    int i = argc;
    while (i <= argc && i >= 1) {
        printf("argc %d: %s\n", i-1, argv[i-1]);
        i--;
    }
    // let's make our own array of strings
    char *states[] = {
        "California", "Oregon",
        "Washington", "Texas"
    };
    int states_num = 4;
    i = 0;
    while (i < states_num) {
        printf("states %d: %s\n", i, states[i]);
        i++;
    }
}
