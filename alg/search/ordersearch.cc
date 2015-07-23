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
 # Last modified: 2015-07-23 15:56
 #
 # Filename: ordersearch.cc
 #
 # Description: All Rights Are Reserved
 ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
#include <iostream>
#include <vector>

using std::cout;
using std::cin;
using std::endl;
using std::vector;

int OrderSearch(int a[], int len, int search) {
    for (int i=0; i < len; ++i) {
        if (a[i] == search) return i;
    }
    return -1;
}

int BinarySearch(int a[], int len, int search) {
    int low = 0;
    int high = len - 1;
    while (low < high) {
        int middle = (low + high)/2;
        if (a[middle] == search) 
        {
            return middle;
        }
        else {
            if (a[middle] > search) {
                high = middle;
            }
            else {
                low = middle;
            }
        }
    }
    return -1;
}

typedef struct Hash_ {
    int tablesize;
    vector<int> a;
    vector<int> info;
}Hash;

int hashfunc(int key, Hash *h) {
    return key%(h->tablesize);
}

void HashInit(Hash *h, int a[], int len) {
    vector<int> tmp(25, 0);
    h->tablesize = 25;
    h->a = tmp;
    h->info = tmp;
    for (int i=0; i < len; ++i) {
        int add = hashfunc(a[i], h);
        while (h->info[add] > 0) {
            add = hashfunc(add+1, h);
        }
        cout << add << endl;
        h->a[add] = a[i];
        h->info[add]++;
    }
}

int HashSearch(int a[], int len, int search) {
    Hash *hash = new Hash;
    HashInit(hash, a, len);
    for (int j=0; j < 25; ++j) cout << hash->a[j] << " ";
    cout << endl;
    int add = hashfunc(search, hash);
    while (hash->info[add] > 0) {
        if (hash->a[add] == search) return add;
        else add = hashfunc(add+1, hash);
    }
    return -1;
}
int main() {
    int a[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int i = BinarySearch(a, 10, 7);
    cout << a[i] << endl;
    int b[9] = {12, 3, 11, 6, 8, 10, 37, 15, 17};
    int j = HashSearch(b, 9, 37);
    cout << j << endl;
}
