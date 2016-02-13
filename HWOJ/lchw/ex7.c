#include <stdio.h>

int main(int argc, char *argv[]) {
    int areas[] = {10, 12, 13, 14, 20};
    char name[] = "Zed";
    /*char full_name[] = {'Z', 'e', 'd',' ', 'A', '.',
        ' ', 'S', 'h', 'a', 'w', '\0'};*/
    char full_name[] = {'Z', 'e', 'd',' ', 'A', '.',
        ' ', 'S', 'h', 'a', 'w'};
    printf("The size of int %lu\n", sizeof(int));
    printf("The size of int[] %lu\n", sizeof(areas));
    printf("The number of ints in areas %lu\n",
            sizeof(areas)/sizeof(int));
    printf("The size of char: %lu\n", sizeof(char));
    printf("The size of name (char[]): %lu\n", sizeof(name));
    printf("The number of chars: %lu\n", sizeof(name)/sizeof(char));
    printf("The size of full_name (char[]): %lu\n", sizeof(full_name));
    printf("The number of chars: %lu\n", sizeof(full_name)/sizeof(char));
    printf("name=\"%s\" and full_name=\"%s\"\n", name, full_name);

    return 0;
}
