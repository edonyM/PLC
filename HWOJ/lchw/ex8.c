#include <stdio.h>

int main(int argc, char *argv[]) {
    int numbers[4] = {0};
    char name[4] = {'a'};

    // print raw
    printf("numbers: %d %d %d %d\n",
            numbers[0], numbers[1],
            numbers[2], numbers[3]);
    printf("name: %c %c %c %c\n",
            name[0], name[1],
            name[2], name[3]);
    printf("name: %s\n", name);
    printf("integer of '\\0': %d\n", '\0');

    numbers[0] = 1;
    numbers[1] = 2;
    numbers[2] = 3;
    numbers[3] = 4;

    name[0] = 'Z';
    name[1] = 'e';
    name[2] = 'd';
    name[3] = '\0';
    // break the c-style string
    //name[0] = 'Z';
    //name[1] = 'e';
    //name[2] = 'd';
    //name[3] = 'd';  // no '\0' as the terminator of the c-style string

    printf("numbers: %d %d %d %d\n",
            numbers[0], numbers[1],
            numbers[2], numbers[3]);
    printf("name: %c %c %c %c\n",
            name[0], name[1],
            name[2], name[3]);
    printf("name: %s\n", name);

    // another way to print name
    char *another = "name";
    char *another_1 = name;
    printf("another name %s\n", another);
    printf("another_1 name %s\n", another_1);
}
