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
 # Last modified: 2015-07-12 20:45
 #
 # Filename: shellsort.hpp
 #
 # Description: All Rights Are Reserved
 ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
#include <iostream>
//#include "insertsort.hpp"

using std::cout;
using std::cin;
using std::endl;

void InsertSort(int list[], int len) {
    for (int i=1; i < len; ++i) {
        int tmp = list[i];
        int j;
        for (j=i; j > 0; --j) {
            if (tmp < list[j-1]) {
                list[j] = list[j-1];
            }
            else {
                break;
            }
        }
        list[j] = tmp;
    }
}

void ShellSort(int list[], int len) {
    int delta[2] = {3, 1};
    for (int i=0; i < 2; ++i) {
        if(delta[i] == 1) {
            InsertSort(list, len);
        }
        else {
            int times = len/delta[i];
            for (int j=0; j < times; j++) {
                InsertSort(list+j*delta[i], delta[i]);
            }
            if (len - delta[i]*times > 0) {
                InsertSort(list+(times-1)*delta[i], len-delta[i]*times);
            }

        }
    }
}

int main() {
    int a[5] = {12, 34, 0, -1, 3};
    ShellSort(a, 5);
    for (int i=0; i < 5; ++i) {
        cout << a[i] << " ";
    }
    cout << endl;
}
