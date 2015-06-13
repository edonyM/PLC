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
 # Last modified: 2015-06-13 16:47
 #
 # Filename: factorial.cc
 #
 # Description: All Rights Are Reserved
 ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::string;

int EnterNum() {
    string input;
    cout << "Enter number: "<<endl;
    cin >> input;
    int num = 0;
    int flag = 1;
    if (input[0] == '-') {
        flag = -1;
        input.erase(input.begin(), input.begin()+1);
    }
    if (input[0] == '+') {
        input.erase(input.begin(), input.begin()+1);
    }
    for (int i=0; i< input.size(); ++i) {
        if (std::isdigit(input[i])) {
            num = 10 * num + int(input[i] - '0');
        }
        else {
            cout << "This is not a number!\n";
            return -1;
        }
    }
    return flag*num;
}

long Factorial(long num) {
    long res = 1;
    if (num < 0) {
        cout << "Minus Number Can Not Factorial!\n";
        return -1;
    }
    else if (num == 0) {
        return 1;
    }
    else {
        for (int i=1; i <= num; ++i) {
            res *= i;
        }
        return res;
    }
}

int main() {
    int num;
    num = EnterNum();
    long results = 0;
    results = Factorial(num);
    cout << results << endl;
    int counter_0 = 0;
    if (results < 0) {
        cout << "Oops, Minus Number\n";
        return 1;
    }
    while ((results != 0) && (results % 10 == 0)) {
        counter_0++;
        results /= 10;
    }
    cout << "trailing numbers of zeros: " << counter_0 << endl;
    return 0;
}

