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
 # Last modified: 2015-08-30 15:32
 #
 # Filename: const_static.cc
 #
 # Description: All Rights Are Reserved
 ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
#include <iostream>

using std::cout;
using std::cin;
using std::endl;

class A {
public:
    const static int size;
};
const int A::size=10;

class B {
public:
    const static int size = 10;
};

class C {
private:
    const int size;
public:
    C():size(10) {
    }
    void getsize() {cout << size << endl;};
};
int main() {
    A a;
    cout << a.size << endl;
    B b;
    cout << b.size << endl;
    C c;
    c.getsize();
}
