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
 # Last modified: 2015-06-23 15:45
 #
 # Filename: print_sand_clock.cc
 #
 # Description: All Rights Are Reserved
 ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
#include <iostream>
#include <cmath>

using std::cin;
using std::cout;
using std::endl;

int MaxLineNum(int n) {
    int max = 1;
    while (1) {
        if ((max*max + 2*max - 3) <= 2*(n-1)) {
            max += 2;
            continue;
        }
        else {
            return (max-2);
        }

    }
//    double ans_tmp = 0;
//    ans_tmp = (-b_formula + sqrt(b_formula*b_formula - 4*a_formula*c_formula)) / (2*a_formula);
//    cout << "ans tmp: " << ans_tmp << endl;
//    double ans = (-b_formula - sqrt(b_formula*b_formula - 4*a_formula*c_formula)) / (2*a_formula);
//    cout << "ans : " << ans << endl;
//    if (ans < ans_tmp) ans = ans_tmp;
//
//    if (ans > 0) {
//        if (int(ans) % 2 == 0) ans--;
//        cout << "formula ans: " << ans << endl;
//        return int(ans);
//    }
//    else {
//        return -1;
//    }
//
}

void ShowTop(int max, char s) {
    for (int i=max; i > 1; i=i-2) {
        for (int b=(max-i)/2; b > 0; --b) {
            cout << ' ';
        }
        for (int c=i; c > 0; --c) {
            cout << s;
        }
        cout << endl;
    }
}

void ShowMid(int max, char s) {
    for (int i=(max-1)/2; i > 0; --i) {
        cout << ' ';
    }
    cout << s << endl;
}

void ShowDown(int max, char s) {
    for (int i=3; i <= max; i=i+2) {
        for (int b=(max-i)/2; b > 0; --b) {
            cout << ' ';
        }
        for (int c=i; c > 0; --c) {
            cout << s;
        }
        cout << endl;
    }
}
int main() {
    int n;
    char s;
    cin >> n;
    cin >> s;
    int num_line = 0;
    num_line = MaxLineNum(n);
    ShowTop(num_line, s);
    ShowMid(num_line, s);
    ShowDown(num_line, s);
    int remain;
    remain = (num_line*num_line + 2*num_line - 3) / 2 + 1;
    cout << n - remain << endl;
}
