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
 # Last modified: 2015-09-27 18:49
 #
 # Filename: class_string.cc
 #
 # Description: All Rights Are Reserved
 ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
// customized class string that focus on copy constructor, assignment constructor, default constructor and destructor.
// deep copy and shallow copy
#include <iostream>
#include <cstring>

using std::cout;
using std::cin;
using std::endl;

class string {
public:
    string();
    string(const string &other);
    string(const char * str);
    ~string();
    string operator=(string &other);
    void out() {cout << data << " ";}
private:
    char *data;
};

string::string() {
    this->data = NULL;
    cout << "NULL\n";
}

string::string(const string &other) {
    //if (this->data) {
    //    delete data;
    //    data = NULL;
    //}
    this->data = new char[strlen(other.data)+1];
    strcpy(this->data, other.data);
}
string::string(const char *str) {
    //if (this->data) {
    //    delete data;
    //    data = NULL;
    //}
    this->data = new char[strlen(str)+1];
    strcpy(this->data, str);
}
string::~string() {
    if (this->data) {
        delete data;
        data = NULL;
    }
    else {
        data = NULL;
    }
}
string string::operator= (string &other) {
    if (this == &other) {
        cout << "same\n";
        return *this;
    }
    //if (this->data) {
    //    delete data;
    //    data = NULL;
    //}
    this->data = new char[strlen(other.data)+1];
    strcpy(this->data, other.data);
    cout << this->data << endl;
    return *this;
}

int main() {
    string test;
    char a[9] = "cvbddadu";
    string test1(a);
    string test2(test1);
    string test3 = test2;
    test3 = test3;
    test1.out();
    test2.out();
    test3.out();
}
