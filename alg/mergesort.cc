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
 # Last modified: 2015-07-12 21:22
 #
 # Filename: mergesort.cc
 #
 # Description: All Rights Are Reserved
 ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
#include <iostream>

using std::cout;
using std::cin;
using std::endl;

void Swap(int *a, int *b) {
    *a ^= *b ^= *a ^= *b;
}
void Merge(int *l, int *n,int start, int middle, int end) {
    int right = middle + 1;
    int left = start;
    int n_start = start;
    while (left <= middle && right <= end) {
        if (l[left] < l[right]) {
            n[n_start++] = l[left++];
        }
        else {
            n[n_start++] = l[right++];
        }
    }
    while (left <= middle) {
        n[n_start++] = l[left++];
    }
    while (right <= end) {
        n[n_start] = l[right++];
    }
}
void mergesortrecur(int list[], int sorted[], int start, int end) {
    int middle = (start + end)/2;
    if (start < end) {
        MergeSort(list, sorted, start, middle);
        MergeSort(list, sorted, middle+1, end);
        Merge(list, sorted, start, middle, end);
    }
}

void mergersort()
int main() {
    int a[5] = {1, 2,13, -1,45};
    int b[5];
    MergeSort(a,b,0,4);
    for (int i=0; i < 5; ++i) {
        cout << b[i] << " ";
    }
    cout << endl;
}
