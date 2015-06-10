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
 # Last modified: 2015-06-10 13:36
 #
 # Filename: linecount.cc
 #
 # Description: All Rights Are Reserved
 ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
#include <iostream>
#include <fstream>
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::ios;
using std::ifstream;
using std::string;

int LineCounter(const char *file_name) {
    ifstream file;
    int line_num = 0;
    string str_tmp;
    file.open(file_name, ios::in);
    if (file.fail()) {
        return -1;
    }
    else {
        while (getline(file, str_tmp)) {
            ++line_num;
        }
        file.close();
        return line_num;
    }
}

int ByteCounter(const char *file_name) {
    ifstream file;
    int byte_counter = 0;
    int byte_counter_1 = 0;
    char ch;
    file.open(file_name, ifstream::in);
    if (file.fail()) {
        return -1;
    }
    else {
        while (file.eof()) {
            file >> ch;
            cout<<ch;
            ++byte_counter_1;
        }
        file.clear();   //reset the file flags for redirect
        file.seekg(0, ifstream::beg);
        if (file.good()) cout<<"file is good\n";
        if (file.eof()) cout<<"file is end\n";
        while (file.get(ch)) {
            ++byte_counter;
        }
        file.clear();
        file.seekg(0, ifstream::beg);
        int beg;
        beg = file.tellg();
        file.seekg(0, ifstream::end);
        int end;
        end = file.tellg();
        cout<<byte_counter_1<< "**" << end- beg <<endl;
        file.close();
        return byte_counter;
    }
}

int main() {
    string file_name;
    cin >> file_name;
    cout << "Line Numbers: " << LineCounter(file_name.c_str())<<endl;
    cout << "Bytes Numbers: "<< ByteCounter(file_name.c_str())<<endl;
}
