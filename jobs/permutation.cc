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
 # Last modified: 2015-08-29 20:17
 #
 # Filename: permutation.cc
 #
 # Description: All Rights Are Reserved
 ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
#include <iostream>
#include <vector>
#include <string>
#include <cstring>

using std::cout;
using std::cin;
using std::endl;
using std::vector;
using std::string;

void swap(char *a, char *b) {
    char tmp;
    tmp = *a;
    *a = *b;
    *b = tmp;
}

void perm(char *str, int start, int end, vector<string> &result) {
    if (start == end) {
        //cout << str << endl;
        string tmp_str(str);
        result.push_back(tmp_str);
    }
    else {
        for (int i=start; i <= end; ++i) {
            swap(str+start, str+i);
            //cout << str << ":before\n";
            perm(str, start+1, end, result);
            //cout << str << ":after\n";
            swap(str+start, str+i);    // reset the array as the original;
        }
    }
}

void perm_(char *str, int start, int end, vector<char*> &result) {
    if (start == end) {
        //cout << str << endl;
        char *str_tmp = new char[end+1];
        strcpy(str_tmp, str);
        //cout << str_tmp << "**" << endl;
        result.push_back(str_tmp);
    }
    else {
        for (int i=start; i <= end; ++i) {
            swap(str+start, str+i);
            //cout << str << ":before\n";
            perm_(str, start+1, end, result);
            //cout << str << ":after\n";
            swap(str+start, str+i);    // reset the array as the original;
        }
    }
}
int main() {
    char str[] = {'a','b','c','d'};
    vector<string> res;
    perm(str, 0, 3, res);
    //cout << str << ":" << res.size() << endl;
    for (vector<string>::iterator i=res.begin(); i != res.end(); ++i) {
        cout << *i << endl;
    }
    char str_[] = {'a','b','c','d'};
    vector<char*> res_;
    perm_(str_, 0, 3, res_);
    for (vector<char*>::iterator i=res_.begin(); i != res_.end(); ++i) {
        cout << (*i) << endl;
    }
}
