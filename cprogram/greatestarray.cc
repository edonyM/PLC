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
 # Last modified: 2015-06-19 15:55
 #
 # Filename: greatestarray.cc
 #
 # Description: All Rights Are Reserved
 ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <ctime>

using std::cout;
using std::cin;
using std::endl;
using std::vector;

int Max(vector<int> ls) {
    vector<int>::iterator pos;
    pos = max_element(ls.begin(), ls.end());
    return *pos;
}

vector<int> PosPosition(vector<int> ls) {
    vector<int> pos;
    for (size_t i=0; i < ls.size(); ++i) {
        if (ls[i] > 0) pos.push_back(i);
    }
    return pos;
}

vector<int> MaxSubArray(vector<int> ls, int ele_num) {
    vector<int> sub;
    int max = 0;
    int max_sub_pos = 0;
    for (size_t i=0; i <= ls.size()-ele_num; i+=ele_num) {
        int tmp = 0;
        for (int j=0; j < ele_num; ++j) {
            tmp = tmp + ls[j+i];
        }
        if (tmp > max) {
            max = tmp;
            max_sub_pos = i;
        }
    }
//    cout << "max sub position: " << max_sub_pos << endl;
    for (int k=0; k < ele_num; k++) {
        sub.push_back(ls[k+max_sub_pos]);
    }
    sub.push_back(max);
//    cout << "subarray *** max: " << max << endl;
    return sub;
}

int main() {
    vector<int> int_array;
    srand(time(NULL));
    for (int i=0; i < 10; ++i) {
        int flag = rand()%2;
        int mem = rand()%100;
        if (flag == 0) mem = -mem;
        int_array.push_back(mem);
    }
    for (int j=0; j < 10; ++j) {
        cout << int_array[j] << endl;
    }
    cout << "max: " << Max(int_array) << endl;
    vector<int> pos;
    pos = PosPosition(int_array);
    for (size_t j=0; j < pos.size(); ++j) {
        cout << pos[j] << endl;
    }

    int max = 0;
    vector<int> re;
    for (size_t k=1; k < int_array.size()+1; ++k) {
        vector<int> max_sub;
        max_sub = MaxSubArray(int_array, k);
//        cout << k << " subarray: \n";
//        for (int i=0; i < max_sub.size()-1; ++i) {
//            cout << max_sub[i] << endl;
//        }
        if (max < max_sub[max_sub.size()-1]) {
            max = max_sub[max_sub.size()-1];
            re = max_sub;
        }
    }
    cout << "max subarray: \n";
    for (int i=0; i < re.size()-1; ++i) {
        cout << re[i] << endl;
    }

}
