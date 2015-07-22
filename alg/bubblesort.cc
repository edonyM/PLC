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
    //*b ^= *a ^= *b ^= *a;
    int tmp = 0;
    tmp = *a;
    *a = *b;
    *b = tmp;
}

void BubbleSort(int list[], int len) {
    for (int i=0; i < len; ++i) cout << list[i] << " ";
    cout << endl;
    for (int j=len; j >= 0; --j){
        int flag = 0;
        for (int i=0; i < j; ++i) {
            if (list[i] > list[i + 1]) Swap(list+i, list+i+1);
            else flag++;
        }
        if (flag == len) {cout<<flag<<endl;break;}
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
    cout << endl;
    int a1[8] = {1, 2, 3, 4, 5, 6, 7, 8};
    BubbleSort(a1, 8);
    for (int i=0; i < 8; ++i) cout << a1[i] << " ";
    cout << endl;
}
