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
 # Last modified: 2015-07-12 19:29
 #
 # Filename: bubblesort.cc
 #
 # Description: All Rights Are Reserved
 ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
#include <iostream>

using std::cout;
using std::cin;
using std::endl;

void Swap(int *a, int *b) {
    *b ^= *a ^= *b ^= *a;
}

void BubbleSort(int list[], int len) {
    int flag = 0;
    for (int j=len; j > 0; --j){
        for (int i=0; i < len; ++i) {
            if (list[i] > list[i + 1]) Swap(list+i, list+i+1);
            else flag++;
        }
        if (flag == len) break;
    }
}

int main() {
    /* test Swap
    int *a = new int;
    int *b = new int;
    *a = 12;
    *b = 222;
    Swap(a,b);
    cout << *a << " " << *b << endl;
    */
    int a[5] = {2, 13, 4, 55,-1};
    BubbleSort(a, 5);
    for (int i=0; i < 5; ++i) cout << a[i] << " ";
}
