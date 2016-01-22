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
 # Last modified: 2015-09-23 21:59
 #
 # Filename: word_reverse.cc
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

vector<string> Split2Word(const char *str) {
    vector<string> words;
    vector<char> word;
    for (int i=0; i <= strlen(str); ++i) {
        if (str[i] == ' ' || str[i] == '\0'){
            string tmp;
            for (vector<char>::iterator iter=word.begin(); iter!=word.end(); iter++) {
                tmp = tmp + *iter;
            }
            words.push_back(tmp);
            word.clear();
        }
        else {
            word.push_back(str[i]);
        }
    }
    return words;
}

string ReverseStr(const char *str) {
    vector<string> words = Split2Word(str);
    vector<string> reverse_words(words.rbegin(), words.rend());
    //for (vector<string>::iterator iter=reverse_words.begin(); iter!=reverse_words.end(); iter++) {
    //    cout << *iter << "\\";
    //}
    string result;
    for (vector<string>::iterator iter=reverse_words.begin(); iter!=reverse_words.end(); iter++) {
        result = result + *iter;
        result = result + ' ';
    }
    return result;
}
int main() {
    char str[20] = "I'm a good student.";
    vector<string> words = Split2Word(str);
    for (vector<string>::iterator iter=words.begin(); iter!=words.end(); iter++) {
        cout << *iter << "|";
    }
    cout << endl;
    string results = ReverseStr(str);
    cout << results << endl;
}
