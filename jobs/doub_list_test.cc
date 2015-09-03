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
 # Last modified: 2015-09-03 22:22
 #
 # Filename: doub_list_test.cc
 #
 # Description: All Rights Are Reserved
 ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
#include <iostream>
#include "doub_list.hpp"

using std::cout;
using std::cin;
using std::endl;

int main() {
    doub_list *dls = (doub_list *)malloc(sizeof(doub_list));
    int a[9] = {-1, 12, 34, 4, 3, 19, 98, 16, 10};
    if (doub_list_init(dls)) {
        for (int i=0; i < 9; ++i) {
            doub_list_ins(dls, NULL, a[i]);
        }
        doub_list_print(dls);
        int data;
        doub_list_rm(dls, NULL, data);
        cout << data << " rm\n";
        cout << "****\n";
        doub_list_sort(dls);
        doub_list_print(dls);
    }
}
