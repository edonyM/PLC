#include <stdio.h>

int main() {
    int tmp = EOF;
    printf("EOF = %d\n", tmp);
    int c = getchar()!=EOF;
    printf("(getchar!=EOF) = %d\n", c);
}
