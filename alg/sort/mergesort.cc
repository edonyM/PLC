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
        mergesortrecur(list, sorted, start, middle);
        mergesortrecur(list, sorted, middle+1, end);
        Merge(list, sorted, start, middle, end);
    }
}

void mergersortinter(int list[], int sorted[], int start, int end) {
    for (int i=1; i <= end; i *=2) {
        for (int right = start + i; right+i-1 <= end; right=right+2*i) {
            int right_tmp = right;
            int end_r = right + i - 1;
            int middle = right - 1;
            int left = right - i;
            int counter = left;
            //cout << left << "," << middle << "," << right << "," << end_r << endl;
            while (left <= middle && right_tmp <= end_r) {
                if (list[left] < list[right_tmp]) sorted[counter++] = list[left++];
                else sorted[counter++] = list[right_tmp++];
            }
            while (left <= middle) {
                sorted[counter++] = list[left++];
            }
            while (right_tmp <= end_r) {
                sorted[counter++] = list[right_tmp++];
            }
            for (int j=right-i; j <= end_r; ++j) {
                list[j] = sorted[j];
            }
        }
    }
}
int main() {
    int a[5] = {1, 2,13, -1,45};
    int b[5];
    mergesortrecur(a,b,0,4);
    for (int i=0; i < 5; ++i) {
        cout << b[i] << " ";
    }
    cout << endl;
    int a1[5] = {1, 2,13, -1,45};
    int b1[5];
    mergersortinter(a1, b1, 0, 4);
    for (int i=0; i < 5; ++i) {
        cout << a1[i] << " ";
    }
    cout << endl;
}
