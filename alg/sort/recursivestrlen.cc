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
 # Last modified: 2015-07-17 21:41
 #
 # Filename: recursivestrlen.cc
 #
 # Description: All Rights Are Reserved
 ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
#include <iostream>

using std::cout;
using std::cin;
using std::endl;

int mystrlen(char *buf, int n) {
    if (buf[n] == '\0' || n == 0) {
        return 0;
    }
    else if (n == 1) {
        return 1;
    }
    return mystrlen(buf, n/2) + mystrlen(buf+n/2, n/2);
}

int strlen(char *buf, int n) {
    int len = 0;
    len = mystrlen(buf, n);
    if (buf[len] == '\0') return len;
    else return len+1;
}

int main() {
    char f[] = {'a', 'b', 'c', 'd', 'e', 'f', '\0', 'x', 'y', 'z'};
    int i = mystrlen(f, 10);
    cout << i << endl;
    int j = mystrlen(f, 5);
    cout << j << endl;
    int k = mystrlen(f, 8);
    cout << k << endl;
    int ii = strlen(f, 10);
    cout << ii << endl;
    int jj = strlen(f, 5);
    cout << jj << endl;
    int kk = strlen(f, 8);
    cout << kk << endl;
}
