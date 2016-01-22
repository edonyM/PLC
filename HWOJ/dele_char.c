#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int GetResult(const char *input, char *output) {
    int len = strlen(input);
    char *out = (char *)malloc(len * sizeof(char));
    if (!out) return -1;
    out[0] = input[0];
    for (int j=1; j < len; ++j) {
        out[j] = '\0';
    }

    int counter = 1;
    int out_counter = 0;
    while (input[counter] != '\0') {
        while (out[out_counter] != '\0') {
            if (input[counter] == out[out_counter]) {
                counter++;
                out_counter = 0;
                break;
            }
            else {
                out_counter++;
            }
        }
        if (out_counter != 0) {
            out[out_counter] = input[counter++];
            out_counter = 0;
        }
    }

    strcpy(output, out);
    printf("%s, %s", output, out);
    return 0;
}

int main() {
    char str[] = "abadcbad";
    char *out = (char*)malloc(strlen(str)*sizeof(char));
    int tmp = GetResult(str, out);
    printf("result: %s", out);
}
