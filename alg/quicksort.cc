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
    Swap(a+mid, a+right-1); // pivot in the right
                            // only sort between a[left+1]~a[right-2]
    return a[right-1];
}
void quicksort(int a[], int left, int right) {
    if (left >= right) return;
    int pivot = Median3(a, left, right);
    //cout << a[0] << a[1] << a[2] << a[3] << a[4] << endl;
    //cout << left << "-" << right << "p:" << pivot << endl;
    int i = left;
    int j = right-1;
    while(1) {
        while (a[++i] < pivot) {}
        while (a[--j] > pivot) {}
        if (i < j)
            Swap(a+i, a+j);
        else
            break;
    }
    Swap(a+i, a+right-1);
    quicksort(a, left, i-1);
    quicksort(a, i+1, right);
}
void quicksort_(int a[], int left, int right) {
    if (left >= right) return;
    int pivot = a[left];
    //cout << a[0] << a[1] << a[2] << a[3] << a[4] << endl;
    //cout << "p" << pivot << endl;
    int i = left;
    int j = right;
    while(i < j) {
        while (i<j && a[j] > pivot) {j--;}
        if (i < j) a[i++] = a[j];
        while (i<j && a[i] < pivot) {i++;}
        if (i < j) a[j--] = a[i];
    }
    a[i] = pivot;
    quicksort_(a, left, i-1);
    quicksort_(a, i+1, right);
}
void quicksort__(int a[], int left, int right) {
    if (left >= right) return;
    int pivot = a[right];
    //cout << a[0] << a[1] << a[2] << a[3] << a[4] << endl;
    //cout << "p" << pivot << endl;
    int i = left;
    int j = right;
    while(i < j) {
        while (i<j && (a[i] < pivot)) {++i;}
        if (i < j) a[j--] = a[i];
        while (i<j && (a[j] > pivot)) {--j;}
        if (i < j) a[i++] = a[j];
    }
    a[j] = pivot;
    quicksort__(a, left, j-1);
    quicksort__(a, j+1, right);
}
void quicksort___(int a[], int left, int right) {
    if (left >= right) return;
    int pivot = a[(left+right)/2];
    //cout << a[0] << a[1] << a[2] << a[3] << a[4] << endl;
    //cout << "p" << pivot << endl;
    int i = left;
    int j = right;
    while(1) {
        while (a[i] < pivot) {++i;}
        while (a[j] > pivot) {--j;}
        if (i < j) Swap(a+i, a+j);
        else break;
    }
    quicksort___(a, left, i-1);
    quicksort___(a, j+1, right);
}

int main() {
    int *cc = new int;
    *cc = 51;
    Swap(cc, cc);
    cout << *cc <<" CC\n";
    int a[5] = {12, -1, 34, 4 ,17};
    cout << "quick with left pivot\n";
    quicksort(a, 0, 4);
    for (int i=0; i < 5; ++i) cout << a[i] << " ";
    cout << endl;
    int a1[5] = {12, -1, 34, 4 ,17};
    cout << "quick with left pivot_\n";
    quicksort_(a1, 0, 4);
    for (int i=0; i < 5; ++i) cout << a1[i] << " ";
    cout << endl;
    int a2[5] = {12, -1, 34, 4 ,17};
    cout << "quick with left pivot__\n";
    quicksort__(a2, 0, 4);
    for (int i=0; i < 5; ++i) cout << a2[i] << " ";
    cout << endl;
    int a3[5] = {12, -1, 34, 4 ,17};
    cout << "quick with left pivot___\n";
    quicksort___(a3, 0, 4);
    for (int i=0; i < 5; ++i) cout << a3[i] << " ";
    cout << endl;
}
