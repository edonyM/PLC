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
 # Last modified: 2015-09-15 20:15
 #
 # Filename: quicksort.cc
 #
 # Description: All Rights Are Reserved
 ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
#include <iostream>

using std::cout;
using std::cin;
using std::endl;
template<class t>
void swap(t *a, t *b) {
    t tmp = *a;
    *a = *b;
    *b = tmp;
}

void quicksort(int ls[], int m, int n) {
    //cout << m << "-->" << n << endl;
    //for (int i=m; i < n; i++)cout << ls[i] << endl;
    if (m >= n) return;
    int pivot = ls[(m+n)/2];
    int i = m;
    int j = n;
    while (1) {
        while (ls[i] < pivot) {++i;}
        while (ls[j] > pivot) {--j;}
        if (i < j) {swap(ls+i, ls+j);}
        else break;
    }
    quicksort(ls, m, i-1);
    quicksort(ls, j+1, n);
}

void quicksort2(int ls[], int m, int n) {
    if (m >= n) return;
    int pivot = ls[m];
    int i = m;
    int j = n;
    while (i < j) {
        while (i<j && ls[j] > pivot) {--j;}
        if (i < j) ls[i++]= ls[j];
        while (i<j && ls[i] < pivot) {++i;}
        if (i < j) ls[j--]= ls[i];
    }
    ls[i] = pivot;
    quicksort2(ls, m, i-1);
    quicksort2(ls, i+1, n);
}
void bubblesort(int ls[], int size) {
    for (int i=size; i > -1; i--) {
        int flag = 0;
        for (int j=1; j < i; j++) {
            if (ls[j-1] > ls[j]){swap(ls+j-1, ls+j);}
            else flag++;
        }
        if (flag == i) break;
    }
}
void selectsort(int ls[], int size) {
    for (int i=0; i < size; i++) {
        for (int j=i; j < size; ++j) {
            if (ls[j] < ls[i]) {
                swap(ls+j, ls+i);
            }
        }
    }
}
void insertsort(int ls[], int size) {
    for (int i=1; i < size; i++) {
        int tmp = ls[i];
        int j;
        for (j=i; j > 0; j--) {
            if (ls[j-1] > tmp) 
            {
                ls[j] = ls[j-1];
            }
            else 
            {
                break;
            }
        }
        ls[j] = tmp;
    }
}

void shellsort(int ls[], int size) {
    int seq[3] = {5, 3, 1};
    for (int i=0; i < 3; i++) {
        for (int s=seq[i]; s < size; s += seq[i]) {
            int tmp = ls[s];
            int j;
            for (j=s; j > 0; j -= seq[i]) {
                if (ls[j-seq[i]] > tmp) {ls[j] = ls[j-seq[i]];}
                else {break;}
            }
            ls[j] = tmp;
        }
    }
}
void merge(int ls[], int sorted[], int start, int mid, int end) {
    int counter = 0;
    int i = start;
    int j = mid+1;
    while ((i <= mid) && (j <= end)) {
        if (ls[i] < ls[j]) {
            sorted[counter++] = ls[i++];
        }
        else {
            sorted[counter++] = ls[j++];
        }
    }
    while (i <= mid) {
        sorted[counter++] = ls[i++];
    }
    while (j <= end) {
        sorted[counter++] = ls[j++];
    }
    for (int n=0; n < counter; n++) {
        ls[start+n] = sorted[n];
    }
}

void mergesort(int ls[], int sorted[], int start, int end) {
    int mid = (start+end)/2;
    if (start < end) {
        mergesort(ls, sorted, start, mid);
        mergesort(ls, sorted, mid+1, end);
        merge(ls, sorted, start, mid, end);
    }
}

void mergsort_NR(int ls[], int sorted[], int start, int end) {
    for (int delta=1; delta <= (end-start+1)/2; delta *= 2) {
        for (int i=0; i < (end-start+1)/2; i+=2*delta) {
            int start_l = i;
            int last = i + 2*delta - 1;
            int mid = (start_l+last)/2;
            int start_r = mid + 1;
            int counter = 0;
            while (start_l <= mid && start_r <= last) {
                if (ls[start_l] < ls[start_r]) {
                    sorted[counter++] = ls[start_l++];
                }
                else {
                    sorted[counter++] = ls[start_r++];
                }
            }
            while (start_l <= mid) {
                sorted[counter++] = ls[start_l++];
            }
            while (start_r <= last) {
                sorted[counter++] = ls[start_r++];
            }
            for (int i=0; i < counter; i++) {
                ls[i+start_l] = sorted[i];
            }
        }
    }
}

int main() {
    int ls[8] = {12, 2, 13, -1, 15, 1, 0, 5};
    int *tmp = new int[8];
    int *tmp2 = new int[8];
    for (int i=0; i < 8; ++i) {
        tmp[i] = ls[i];
        tmp2[i] = ls[i];
    }
    cout << "**\n";
    quicksort(tmp, 0, 7);
    for(int i=0; i < 8; ++i) {
        cout << tmp[i] << endl;
    }
    cout << "**\n";
    bubblesort(tmp2, 8);
    for(int i=0; i < 8; ++i) {
        cout << tmp2[i] << endl;
    }
    cout << "**\n";

    int tmp3[10] = {12, 2, 13, -1, 34, 15, 1, 7, 0, 5};
    insertsort(tmp3,10);
    for(int i=0; i < 10; ++i) {
        cout << tmp3[i] << endl;
    }
    cout << "**\n";
    int tmp4[10] = {12, 2, 13, -1, 34, 15, 1, 7, 0, 5};
    shellsort(tmp4, 10);
    for(int i=0; i < 10; ++i) {
        cout << tmp4[i] << endl;
    }
    cout << "**merge\n";
    int tmp5[10] = {12, 2, 13, -1, 34, 15, 1, 7, 0, 5};
    int sorted[10];
    mergesort(tmp5, sorted, 0, 9);
    for(int i=0; i < 10; ++i) {
        cout << sorted[i] << endl;
    }
    cout << "**merge_NR even\n";
    int tmp6[10] = {12, 2, 13, -1, 34, 15, 1, 7, 0, 5};
    int sorted1[10];
    mergesort(tmp6, sorted1, 0, 9);
    for(int i=0; i < 10; ++i) {
        cout << tmp6[i] << endl;
    }
    cout << "**merge_NR odd\n";
    int tmp7[7] = {2, -1, 34, 15, 1, 7, 5};
    int sorted2[7];
    mergesort(tmp7, sorted2, 0, 6);
    for(int i=0; i < 7; ++i) {
        cout << tmp7[i] << endl;
    }
    cout << "**selection sort\n";
    int tmp8[7] = {2, -1, 34, 15, 1, 7, 5};
    selectsort(tmp8, 7);
    for(int i=0; i < 7; ++i) {
        cout << tmp8[i] << endl;
    }
    //quicksort2(tmp2, 0, 7);
    //for(int i=0; i < 8; ++i) {
    //    cout << tmp2[i] << endl;
    //}
}
