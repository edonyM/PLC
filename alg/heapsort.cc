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
 # Last modified: 2015-07-13 09:41
 #
 # Filename: heapsort.cc
 #
 # Description: All Rights Are Reserved
 ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
#include <iostream>
#include <cstdlib>

using std::cout;
using std::cin;
using std::endl;

typedef struct Heap_ {
    int size;
    int *data;
}Heap;

void HeapInit(Heap *maxheap) {
    maxheap->size = 0;
    maxheap->data = NULL;
}

void Swap(int *a, int *b) {
    *a ^= *b ^= *a ^= *b;
}
void HeapInsert(Heap *maxheap, int *data) {
    int num = maxheap->size + 1;
    int parent = num/2;
    int *new_data = new int[num];
    for (int i=0; i < maxheap->size; ++i) {
        new_data[i] = maxheap->data[i];
    }
    maxheap->data = new_data;
    maxheap->data[maxheap->size] = *data;
    while ((num > 0) && (parent > 0) && (maxheap->data[num-1] > maxheap->data[parent-1])) {
        //cout << maxheap->data[num-1] << "*" << maxheap->data[parent-1] << endl;
        Swap(maxheap->data+num-1, maxheap->data+parent-1);
        //cout << maxheap->data[num-1] << "^" << maxheap->data[parent-1] << endl;
        num = parent;
        parent = num/2;
    }
    maxheap->size++;
}
void HeapSort(int a[], int len) {
    int ins_start = len;
    for (; ins_start > 0; --ins_start) {
        int tmp = a[ins_start-1];
        Heap *tmp_heap = new Heap;
        HeapInit(tmp_heap);
        for (int i=0; i < ins_start; ++i) {
            HeapInsert(tmp_heap, a+i);
        }
        a[ins_start-1] = tmp_heap->data[0];
        for (int i=0; i < ins_start; ++i) {
            if (a[i] == tmp_heap->data[0]) {a[i] = tmp;break;}
        }
    }
}

int main() {
    int a[5] = {1, 23, -1, 3, 22};
    int a1[5] = {1, 23, -1, 3, 22};
    HeapSort(a, 5);
    for (int j=0; j < 5; ++j) cout << a[j] << " ";
    cout << "*" << endl;
    Heap *tmp = new Heap;
    HeapInit(tmp);
    for (int i=0; i < 5; ++i) {
        HeapInsert(tmp, a1+i);
    }
    for (int i=0; i < tmp->size; ++i) {
        cout << tmp->data[i] << " ";
    }
    cout << endl;
}
