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
 # Last modified: 2015-06-11 21:10
 #
 # Filename: listpermutation.cc
 #
 # Description: All Rights Are Reserved
 ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
// List all permutation list of given string
#include <iostream>
#include <vector>
#include <string>
#include <cstring>

using std::vector;
using std::string;
using std::cout;
using std::cin;
using std::endl;

string pickcell(const string str, int x, int y) {
    string new_str = str;
    new_str[x] = new_str[y];
    new_str[y] = str[x];
    return new_str;
}

void all_list(string str, int pos) {
    int len = str.length();
    if (pos == len - 1) {
        cout << str << endl;
    }
    else {
        for (int i=pos; i < len; ++i) {
            all_list(pickcell(str, pos, i), pos+1);
        }
    }
}

int main() {
    string str;
    cin >> str;
    //vector<char> v_str;
    //permu(str.c_str(), v_str);
    all_list(str, 0);
}
