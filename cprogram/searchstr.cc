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
 # Last modified: 2015-06-13 19:21
 #
 # Filename: searchstr.cc
 #
 # Description: All Rights Are Reserved
 ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
// String search without library string
#include <iostream>
//#include <string>
#include <cstring>

using std::cin;
using std::cout;
using std::endl;
//using std::string;

int Match(const char ch, char *str) {
    int i = 0;
    while (str[i] != '\0') {
        if (str[i] == ch) return i;
        else ++i;
    }
    return -1;
}

int IsSubString(char *str, char *sub) {
    int pos_substr_star = Match('*', sub);
    int re_mode = 1;    // re_mode=1 is flag for treate an * as regular symbol
    // reset re_mode flag and translate the '\*' into normal string
    if (pos_substr_star > 0 && sub[pos_substr_star-1] == '\\') {
        re_mode = 0;
        for (int i=pos_substr_star-1; i < strlen(sub); ++i) {
            sub[i] = sub[i+1];
        }
    }

    // find the first match between them from the begining of sub string
    int pos_str_match_sub_beg = Match(sub[0], str);
    // if the first charactor is '*', match the next charactor
    if (pos_substr_star == 0) pos_str_match_sub_beg = Match(sub[1], str);

    if (pos_str_match_sub_beg < 0) {cout<<0<<endl;return 0;};    // Nothing match
    if (re_mode && pos_substr_star >= 0) {      // regular expression mode
        if (pos_substr_star == strlen(sub)-1) {
            for (int i=0; i < strlen(sub)-1; ++i) {
                if (str[pos_str_match_sub_beg] == sub[i]) {
                    continue;
                }
                else if (sub[i] == '*') {
                    char *str_0;
                    str_0 = str + pos_str_match_sub_beg + i;
                    char *sub_str_0;
                    sub_str_0 = sub + i;
                    IsSubString(str_0, sub_str_0);
    
                }
                else {
                    cout<<1<<endl;
                    return 0;
                }
            }
        } 
        for (int i=0; i < pos_substr_star; ++i) {
            if (str[pos_str_match_sub_beg+i] == sub[i]) {
                continue;
            }
            else if (sub[i] == '*') {
                char *str_1;
                str_1 = str + pos_str_match_sub_beg + i;
                char *sub_str_1;
                sub_str_1 = sub + i;
                IsSubString(str_1, sub_str_1);
            }
            else {
                cout<<2<<endl;
                return 0;
            }
        }
        int pos_star = pos_str_match_sub_beg + pos_substr_star - 1;
        while ((str[pos_star] != sub[pos_substr_star+1]) &&
                (pos_star < strlen(str) - 1)) {
            pos_star++;
        }
        if (pos_star == strlen(str) -1 && pos_substr_star == strlen(sub)-1)
        {
            cout<<3<<endl;
            return 1;
        }
        if (pos_star == strlen(str) -1 && pos_substr_star != strlen(sub)-1)
        {
            return 0;
        }
        for (int j=pos_substr_star+1; j < strlen(sub); ++j) {
            if (str[pos_star] == sub[j]) {
                pos_star++;
            }
            else if (sub[j] == '*') {
                char *str_2;
                str_2 = str + pos_star;
                char *sub_str_2;
                sub_str_2 = sub + j;
                IsSubString(str_2, sub_str_2);

            }
            else {
                cout<<4<<endl;
                return 0;
            }
        }
        cout<<5<<endl;
        return 1;
    }
    else {    // normal mode
        for (int i=0; i < strlen(sub); ++i) {
            if (str[pos_str_match_sub_beg+i] == sub[i]) {
                continue;
            }
            else if (sub[i] == '*') {
                char *str_3;
                str_3 = str + pos_str_match_sub_beg + i;
                char *sub_str_3;
                sub_str_3 = sub + i;
                IsSubString(str_3, sub_str_3);

            }
            else {
                cout<<6<<endl;
                return 0;
            }
        }
        cout<<7<<endl;
        return 1;
    }

}

int main(int argc, char *argv[]) {
    if (argc == 3) {
        char *str = argv[1];
        char *sub_str = argv[2];
        // sizeof to count length of string with type char[]
        //int str_len = sizeof(argv[1])/sizeof(char);
        //int substr_len = sizeof(argv[2])/sizeof(char);
        int str_len = strlen(str);
        int substr_len = strlen(sub_str);
        cout << str <<endl;
        cout << sub_str <<endl;
//        cout << str_len <<endl;
//        cout << substr_len <<endl;
        int a;
        a = IsSubString(str, sub_str);
        if (IsSubString(str, sub_str)) {
            cout << "Yes" << endl;
            cout << sub_str << " is sub-string of " << str << endl;
        }
        else {
            cout << "No" << endl;
            cout << sub_str << " is not sub-string of " << str << endl;
        }
    }
}

