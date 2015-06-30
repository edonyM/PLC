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
 # Last modified: 2015-06-23 16:50
 #
 # Filename: pairprime.cc
 #
 # Description: All Rights Are Reserved
 ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
#include <iostream>
#include <vector>
#include <cmath>

using std::cout;
using std::cin;
using std::endl;
using std::vector;

bool IsPrime(int num) {
    for (int i=2; i <= int(sqrt(num)); ++i) {
        if (num % i == 0) return 0;
    }
    return 1;
}
vector<int> PrimeList(int n) {
    vector<int> pri_lis;
    for (int i=2; i <= n; ++i) {
        if (IsPrime(i)) pri_lis.push_back(i);
    }
    return pri_lis;
}
int PairPrime(int pri1, int pri2) {
    if ((pri2 - pri1) == 2) {
        return 1;
    }
    else {
        return 0;
    }
}

int main() {
    int n;
    cin >> n;
    vector<int> pri_list;
    pri_list = PrimeList(n);
    int counter = 0;
    for (size_t i=pri_list.size(); i > 1; --i) {
        counter += PairPrime(pri_list[i-1], pri_list[i]);
    }
    cout << counter << endl;
}
