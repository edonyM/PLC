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
 # Last modified: 2015-06-24 20:05
 #
 # Filename: maxsub.cc
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

vector<int> MaxSubArray(int *array, int size) {
    int max = array[0];
    int beg = size;
    int end = 0;
    vector<int> record;
    //int tmp = array[0];
    for (int i=1; i <= size; ++i) { // sub array has i elements
        for (int j=0; j <= size-i; ++j) { // summary the sub array and find the max
            int tmp = 0;
            for (int k=1; k <= i; ++k) {
                tmp += array[j+k-1];
            }
            if (tmp >= max) {
                max = tmp;
                record.push_back(max);
                beg = j;
                record.push_back(j);
                end = j + i - 1;
                record.push_back(j+i-1);
            }
        }
    }
    for (vector<int>::iterator iter=record.begin(); iter < record.end(); iter=iter+3) {
        if ((*iter) == max) {
            if (*(iter+1) < beg) {
                cout << *(iter+1) << endl;
                beg = *(iter+1);
                end = *(iter+2);
            }
        }
    }
    vector<int> results;
    results.push_back(max);
    results.push_back(beg);
    results.push_back(end);
    return results;
}

int main() {
    int size;
    cin >> size;
    int *array = new int[size];
    for (int i=0; i < size; ++i) {
        cin >> array[i];
    }
    vector<int> max_sub_array;
    max_sub_array = MaxSubArray(array, size);
    if (max_sub_array[0] < 0) {
        cout << 0 << " " << array[0] << " " << array[size-1] << endl;
    }
    else{
        cout << max_sub_array[0] << " " << array[max_sub_array[1]] << " " << array[max_sub_array[2]] << endl;
    }
    return 0;
}
