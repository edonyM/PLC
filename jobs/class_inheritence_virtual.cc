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
 # Last modified: 2015-09-04 19:01
 #
 # Filename: class_inheritence_virtual.cc
 #
 # Description: All Rights Are Reserved
 ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
#include <iostream>

using std::cout;
using std::cin;
using std::endl;

class A {
public:
    void func() {cout << "A::func\n";}
};

class B: public A {
public:
    void func() {cout << "B::func\n";}
};

class A_V {
public:
    virtual void func() {cout << "virtual A::func\n";}
    ~A_V() {cout << "virtual A destructor\n";}
};

class B_V: public A_V {
public:
    virtual void func() {cout << "virtual B::func\n";}
    ~B_V() {cout << "virtual B destructor\n";}
};

int main() {
    B *pb = new B;
    pb->func();
    pb->A::func();
    A *pa;
    pa = dynamic_cast<A*>(pb);
    pa->func();
    B_V *pvb = new B_V;
    pvb->func();
    pvb->A_V::func();
    A_V *pva;
    pva = dynamic_cast<A_V*>(pvb);
    pva->func();
    delete pb;
    delete pva;    //delete pvb;
}
