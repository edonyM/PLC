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
    for (int i=1; i < end+1; i *=2) {
        if (i > end) i = end;
        int left_start = start;
        int left_end = left_start + i - 1;
        int right_start = left_start + i;
        int right_end = right_start + i - 1;
        for (; right_end <= end; right_end=right_end+2*i) {
            if (right_end > end) right_end = end;
            int end_r_s = right_end;
            int start_r = right_end + 1 - i;
            int start_l = start_r - i;
            int end_s = start_l + i -1;
            cout << list[start_l] << "L" << list[end_s] << endl;
            cout << list[start_r] << "R" << list[end_r_s] << endl;
            int new_start = start;
            while (start_l <= end_s && start_r <= end_r_s) {
                if (list[start_l] < list[start_r]) sorted[new_start++] = list[start_l++];
                else sorted[new_start++] = list[start_r++];
            }
            while (start_l <= end_s) {
                sorted[new_start++] = list[start_l++];
            }
            while (start_r <= end_r_s) {
                sorted[new_start++] = list[start_r++];
            }
            //while (new_start >= 0) {
            //    list[start_r--] = sorted[new_start--];
            //}
            for (int j=right_end+1-i-i; j <= right_end; ++j) {list[j] = sorted[j];}
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
