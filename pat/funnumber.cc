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
 # Last modified: 2015-06-23 19:10
 #
 # Filename: funnumber.cc
 #
 # Description: All Rights Are Reserved
 ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
#include <iostream>

using std::cin;
using std::cout;
using std::endl;

//long DigInNumber(long num, int dig) {
//    long tmp = num;
//    while (tmp) {
//        if (dig == (tmp%10)) return 1;
//        tmp /= 10;
//    }
//    return 0;
//}

void RecordDigit(long num, int record[10]) {
    long tmp = num;
    while (tmp) {
        record[tmp%10]++;
        tmp /= 10;
    }
}

int main() {
    long num;
    cin >> num;
    int dig_list[10] = {0,0,0,0,0,0,0,0,0,0};
    RecordDigit(num, dig_list);
    for (int i=0; i < 10; ++i) cout << dig_list[i] << " ";
    long doub_num = 2*num;
    int doub_dig_list[10] = {0,0,0,0,0,0,0,0,0,0};
    RecordDigit(doub_num, doub_dig_list);
    for (int i=0; i < 10; ++i) cout << doub_dig_list[i] << " ";
    for (int i=0; i < 10; ++i) {
        if (doub_dig_list[i] != dig_list[i]) {
            cout << "No\n" << 2*num << endl;
            return 0;
        }
    }
//    while (doub_num) {
//        int digit = doub_num % 10;
//        if (!DigInNumber(num, digit)) {
//            cout << "No\n" << 2*num << endl;
//            return 1;
//        }
//        doub_num /= 10;
//    }
    cout << "Yes\n" << 2*num << endl;
    return 0;
}
