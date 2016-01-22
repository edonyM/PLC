 /*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 #        .---.         .-----------
 #       /     \  __  /    ------
 #      / /     \(  )/    -----   (`-')  _ _(`-')              <-. (`-')_
 #     //////    '\/ `   ---      ( OO).-/( (OO ).->     .->      \( OO) )     .->
 #    //// / //  :   : ---      (,------. \    .'_ (`-')----. ,--./ ,--/  ,--.'  ,-.
 #   // /   /  / `\/ '--         |  .---' '`'-..__)( OO).-. ' |   \ |  | (`-')'.'  /
 #  //          //..\\          (|  '--.  |  |  ' |( _) | | | |  . '|  |)(OO \    /
 # ============UU====UU====      |  .--'  |  |  / : \|  |)| | |  |\    |  |  /   /)
 #             '//||\\`          |  `---. |  '-'  /  '  '-' ' |  | \   |  `-/   /`
 #               ''``            `------' `------'    `-----' `--'  `--'    `--'
 # ######################################################################################
 #
 # Author: edony - edonyzpc@gmail.com
 #
 # twitter : @edonyzpc
 #
 # Last modified: 2015-09-23 21:39
 #
 # Filename: strstr.c
 #
 # Description: All Rights Are Reserved
 ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
// pure c impelement strstr()
#include <iostream>

using std::cin;
using std::cout;
using std::endl;

const char *strstr(const char *string, const char *strCharSet) {
    for (int i=0; string[i]!='\0'; i++) {
        int str_counter = i;
        int charset_counter = 0;
        int flag = 0;
        while (string[str_counter] == strCharSet[charset_counter]) {
            str_counter++;
            charset_counter++;
            if (strCharSet[charset_counter] == '\0') {
                flag = 1;
                break;
            }
        }
        if (flag) {
            return string+i;
        }
    }
}

int main() {
    char string[9] = "12345678";
    char strCharSet[4] = "234";
    const char *result = strstr(string, strCharSet);
    cout << result << endl;

}
