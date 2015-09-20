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
 # Last modified: 2015-09-18 19:46
 #
 # Filename: int2str.cc
 #
 # Description: All Rights Are Reserved
 ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
#include <iostream>
#include <vector>

using std::cout;
using std::cin;
using std::endl;
using std::vector;

char *int2str(int input) {
    vector<char> ch_tmp;
    int tmp = input;
    int counter = 0;
    while (tmp) {
        int bit = tmp%10;
        char bit_c = char(bit + '0');
        ch_tmp.push_back(bit_c);
        tmp /= 10;
        counter++;
    }
    char *str = new char[counter];
    str[counter] = '\0';
    for (vector<char>::iterator iter=ch_tmp.begin(); iter != ch_tmp.end(); iter++) {
        str[--counter] = *iter;
    }
    return str;
}

int main() {
    int a = 1334;
    char *out = int2str(a);
    cout << out << endl;
}
