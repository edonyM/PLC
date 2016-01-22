#include <stdio.h>
#include <stdlib.h>

void func(char **p) {
    *p = (char*)malloc(3*sizeof(char));
    *(*p + 0) = '1';
    *(*p + 1) = 'A';
    *(*p + 2) = '\0';
}

int main() {
    char *tmp;
    func(&tmp);
    printf("%s\n", tmp);
}
