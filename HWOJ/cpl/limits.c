#include <stdio.h>
#include <limits.h>

int main() {
    printf("int max is %d\n", INT_MAX);
    printf("int min is %d\n", INT_MIN);
    printf("unsigned int max is %d\n", UINT_MAX);
    printf("short max is %d\n", SHRT_MAX);
    printf("short min is %d\n", SHRT_MIN);
    printf("char max is %d\n", CHAR_MAX);
    printf("char min is %d\n", CHAR_MIN);
    /* Not defined in `limits.h` file
     * printf("float max is %d\n", CHAR_MAX);
     * printf("float min is %d\n", CHAR_MIN);
     */
}
