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
 # Last modified: 2015-06-24 15:42
 #
 # Filename: maxsubarray.cc
 #
 # Description: All Rights Are Reserved
 ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
#include <iostream>
#include <vector>
#include <algorithm>

using std::cout;
using std::cin;
using std::endl;
using std::vector;

int MaxSubArray(int *array, int size, vector<int> &max_member) {
    int max = 0;
    int tmp = 0;
    for (int i=0; i < size; ++i) {
        tmp += array[i];
        if (tmp < 0) {
            tmp = 0;
        }
        if (max <= tmp) {
            max = tmp;
            max_member.push_back(i);
        }
        //max = max < tmp ? tmp : max;
    }
    return max;
}

int FindBeg(int *array, int pos_max, int max) {
    int tmp = 0;
    //if (max == 0) return pos_max;
    while (pos_max>=0) {
        if (tmp == max) break;
        tmp += array[pos_max];
        pos_max--;
        //cout << "pos_max: " << pos_max << endl;
    }
    if (tmp == max) return pos_max+1;
    else return -1;
}

int main() {
    int size;
    cin >> size;
    int *array = new int[size];
    for (int i=0; i < size; ++i) {
        cin >> array[i];
    }
    int max = 0;
    vector<int> list_element;
    max = MaxSubArray(array, size, list_element);
    vector<int>::iterator end_element;
    if ((max == 0) && (list_element.size() == 0)) {
        cout << 0 << " " << array[0] << " " << array[size-1] << endl;
        return 0;
    }
    else {
        int begin = size;
        int tmp = 0;
        size_t j = 0;
        for (size_t i=list_element.size()-1; i > 0; --i) {
            tmp = FindBeg(array, list_element[i], max);
            if ((tmp != -1)&&(begin >= tmp)) {
                begin = tmp;
                j = i;
            }
        }
        cout << max << " " << array[begin] << " " << array[j] << endl;
        return 0;
    }
}
