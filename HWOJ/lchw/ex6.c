#include <stdio.h>

int main(int argc, char *argv[]) {
    int distance = 100;
    float power = 2.345f;
    double super_power = 9876.2345;
    int decima = 0733;
    int hex = 0x35df;
    char ch = 'e';
    char str[] = "edony";
    /* char str[] = "edony"; */
    printf("you are %d mile away.\n", distance);
    printf("you have %f level of power.\n", power);
    printf("you have %f awesome super power.\n", super_power);
    printf("you got a decima integer %o.\n", decima);
    printf("you got a hexadecimal integer %x.\n", hex);
    printf("you got a charactor %c.\n", ch);
    printf("you got a string %s.\n", str);
}
