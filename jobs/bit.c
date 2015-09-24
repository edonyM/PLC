#include <stdio.h>

struct bit {
    unsigned int a:1, b:1, c:1, d:1;
};

char *get_str(){
    char *str={"hello"};
    return str;
}
int main() {
    struct bit test;
    printf("ok\n");
    char *p = get_str();
    printf("%s\n",p);
    unsigned short a = 10;
    printf("~A=%u\n",~a);
    unsigned char c = 128;
    printf("c=%d\n", c);
}
