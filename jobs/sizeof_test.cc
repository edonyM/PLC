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
 # Last modified: 2015-09-07 20:54
 #
 # Filename: sizeof_test.cc
 #
 # Description: All Rights Are Reserved
 ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
#include <iostream>
#include <stdint.h>

using std::cout;
using std::cin;
using std::endl;

int main() {
    int *a = new int[5];
    int b[] = {1,2,3,4,5};
    cout << "sizeof(a): " << sizeof(a) << endl;
    cout << "sizeof(b): " << sizeof(b) << endl;

    char *c_a = new char[5];
    char c_b[] = "12345";
    cout << "sizeof(c_a): " << sizeof(c_a) << endl;
    cout << "sizeof(c_b): " << sizeof(c_b) << endl;

    cout << "sizeof(int): " << sizeof(int) << endl;
    cout << "sizeof(short): " << sizeof(short) << endl;
    cout << "sizeof(long): " << sizeof(long) << endl;
    cout << "sizeof(long32): " << sizeof(int32_t) << endl;
    cout << "sizeof(long long): " << sizeof(long long) << endl;
    cout << "sizeof(double): " << sizeof(double) << endl;
    cout << "sizeof(float): " << sizeof(float) << endl;

    union a_ {
        int in;
        struct str_ {
            int a:32;
            int b:16;
        }str;
    }aa;
    cout << "union: " << sizeof(aa.in) << endl;
    aa.in = 15;
    cout << "union.int: " << sizeof(aa.str) << endl;
}
