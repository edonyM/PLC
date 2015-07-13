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
 # Last modified: 2015-07-13 14:57
 #
 # Filename: quicksort.cc
 #
 # Description: All Rights Are Reserved
 ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
#include <iostream>

using std::cout;
using std::cin;
using std::endl;

void Swap(int *a, int *b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}
int Median3(int a[], int left, int right) {
    int mid = (left + right)/2;
    //cout << "MID: " << mid << endl;
    //cout << a[left] << " " << a[mid] << " " << a[right] << endl;
    if (a[left] > a[mid]) {
        Swap(a+left, a+mid);
    }
    if (a[left] > a[right]) {
        Swap(a+left, a+right);
    }
    if (a[mid] > a[right]) {
        Swap(a+mid, a+right);
    }
    //cout << a[left] << " " << a[mid] << " " << a[right] << endl;
    //Swap(a+mid, a+right-1); // pivot in the right
                            // only sort between a[left+1]~a[right-2]
    return a[mid];
}
void quicksort(int a[], int left, int right) {
    if (left >= right) return;
    int pivot = Median3(a, left, right);
    //cout << a[0] << a[1] << a[2] << a[3] << a[4] << endl;
    //cout << "p" << pivot << endl;
    int i = left;
    int j = right;
    for(;;) {
        while ((i<j) && (a[i] < pivot)) {++i;}
        while ((i<j) && (a[j] > pivot)) {--j;}
        if (i < j)
            Swap(a+i, a+j);
        else
            break;
    }
    Swap(a+i, a+(left+right)/2);
    for (int i=0; i < 5; ++i) cout << a[i] << " ";
    cout << endl;
    quicksort(a, left, i-1);
    quicksort(a, i+1, right);
}

int main() {
    int *cc = new int;
    *cc = 51;
    Swap(cc, cc);
    cout << *cc <<" CC\n";
    int a[5] = {12, -1, 34, 4 ,17};
    quicksort(a, 0, 4);
    for (int i=0; i < 5; ++i) cout << a[i] << " ";
    cout << endl;
}
