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
 # Last modified: 2015-08-28 22:27
 #
 # Filename: static_template.cc
 #
 # Description: All Rights Are Reserved
 ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
#include <iostream>

using std::cout;
using std::cin;
using std::endl;

template<class T>
class Operate {
public:
    static T Add(T a, T b) {
        return a+b;
    }
    static T Mul(T a, T b) {
        return a*b;
    }
    static T Judge(T a, T b) {
        if (a >= 0) {
            return a;
        }
        else {
            return a/b;
        }
    }
};
template<class T>
class Operate_ {
public:
    T Add(T a, T b) {
        return a+b;
    }
    T Mul(T a, T b) {
        return a*b;
    }
    T Judge(T a, T b) {
        if (a >= 0) {
            return a;
        }
        else {
            return a/b;
        }
    }
};

int main() {
    int a, b, c, d, e, x, y, z, x_, y_, z_;
    a = 1, b = 2, c = 3, d = 4, e = 5;
    x = Operate<int>::Add(a, b);
    y = Operate<int>::Mul(c, d);
    z = Operate<int>::Judge(e, b);
    Operate_<int> tmp_st;
    x_ = tmp_st.Add(a, b);
    y_ = tmp_st.Mul(c, d);
    z_ = tmp_st.Judge(e, b);
    cout << x << y << z;
    cout << x_ << y_ << z_;
}
