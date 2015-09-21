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
 # Last modified: 2015-09-21 17:10
 #
 # Filename: sequence_substr.c
 #
 # Description: All Rights Are Reserved
 ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
// 求一个字符串中连续出现次数最多的字串
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <cstring>
#include <cassert>

using std::cout;
using std::cin;
using std::endl;
using std::vector;
using std::set;
using std::map;
using std::string;

set<string> SubStr(char *str) {     //list all sub-strings
    set<string> substr;
    if (!str) return substr;
    int len = strlen(str);
    for (int i=1; i <= len; i++) {
        char *str_tmp = new char[i+1];
        for (int j=0; j < len; j++) {
            int counter = i;
            while (counter) {
                str_tmp[i-counter] = str[j+i-counter];
                counter--;
            }
            str_tmp[i] = '\0';
            if (strlen(str_tmp) == i) {
                string tmp(str_tmp);
                substr.insert(tmp);
            }
        }
        delete [] str_tmp;
    }
}

std::pair<string, int> MaxRepeatSubStr(char *str) {     // 非连续出现次数最多的字串
    string max_repeat;
    if (!str) return std::pair<string, int>(max_repeat,0);
    set<string> substr = SubStr(str);
    int counter = 0;
    map<string, int> find_max;
    for (set<string>::iterator iter=substr.begin(); iter != substr.end(); iter++) {
        find_max.insert(std::pair<string, int>(*iter, counter));
    }
    int len = strlen(str);
    for (int i=1; i <= len; i++) {
        char *str_tmp = new char[i+1];
        for (int j=0; j < len; j++) {
            int counter = i;
            while (counter) {
                str_tmp[i-counter] = str[j+i-counter];
                counter--;
            }
            str_tmp[i] = '\0';
            if (strlen(str_tmp) == i) {
                string tmp(str_tmp);
                find_max[tmp]++;
            }
        }
    }
    int value=0;
    string result;
    for (map<string, int>::iterator iter=find_max.begin(); iter != find_max.end(); iter++) {
        if (iter->second > value) {
            value = iter->second;
            result = iter->first;
        }
    }
    return std::pair<string, int>(result, value);
}
std::pair<string, int> MaxSeqSubStr(char *str) {
}
int main() {
    char str[11] = "abcbcbcabc";
    set<string> result = SubStr(str);
    set<string>::iterator iter=result.begin();
    for (; iter != result.end(); ++iter) {
        cout << *iter << " ";
    }
    cout << endl;
    std::pair<string, int> after = MaxRepeatSubStr(str);
    cout << "string: " << after.first << " and counter: " << after.second << endl;
}
