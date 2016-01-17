#include <stdio.h>
#include <string.h>
int matched(char str[], char find[]) {
    /* str[] is the string to do matching
     * find[] is the sub-string to be matched
     */
    int len_find = strlen(find);
    int len_str = strlen(str);
    for (int i=0; i <= len_str; ++i) {
        int str_i = i;
        int j = 0;
        int counter = 0;
        while (find[j++] == str[str_i++]) {
            counter++;
        }
        if (counter == len_find) return 1;
    }
    return 0;
}

int main() {
    char str[4][100] = {"Ah Love! could you and I with Fate conspire",
        "To grasp this sorry Scheme of Things entire,",
        "Would not we shatter it to bits -- and then",
        "Re-mould it nearer to the Heart's Desire!"};
    char find[] = "ould";
    for (int i=0; i < 4; ++i) {
        if (matched(str[i], find)) {
            printf("%s\n", str[i]);
        }
    }
}
