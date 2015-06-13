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
 # Last modified: 2015-06-12 19:24
 #
 # Filename: int2eng.cc
 #
 # Description: All Rights Are Reserved
 ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
#include <iostream>
#include <string>
#include <vector>
#include <climits>

using std::string;
using std::cin;
using std::cout;
using std::endl;
using std::vector;

string num2char[10] = {
                    "zero",
                    "one", "two", "three", 
                    "four", "five", "six",
                    "seven", "eight", "nine",
};

string num2ten[20] = {
                    "zero",
                    "ten", "twenty", "thirty",
                    "fourty", "fifty", "sixty",
                    "seventy", "eighty", "ninety",
                    "ten",
                    "eleven", "twelve", "thirteen",
                    "fourteen", "fifteen", "sixteen",
                    "seventeen", "eighteen", "nineteen"
};

string engcount[4] = {
                    "",
                    "thousand",
                    "million",
                    "billion"
};

string int2str(int num) {
    char c_tmp;
    string str;
    int tmp = num;
    if (tmp < 0) tmp = -tmp;
    while (tmp) {
        c_tmp = tmp % 10 + '0';
        str.insert(str.begin(),c_tmp);
        tmp /= 10;
    }
    if (num < 0) {
        str.insert(str.begin(),'-');
        num = -num;
    }
    return str;
}

vector<string> SliceNum(string str) {
    vector<string> str_list;
    int last_pos = str.length() % 3;
    if (last_pos)str_list.push_back(str.substr(0, last_pos));
    for (int i=last_pos; i < str.length(); i=i+3) {
        str_list.push_back(str.substr(i,3));
    }
    return str_list;
}

string Num2Eng(string num) {
    if (num.length() > 3) return "";
    string tmp;
    if (num.length() == 3) {
        string t_tmp = num2char[int(num[0]-'0')];
        if (t_tmp != "zero") {
            tmp = tmp + t_tmp  + " hundreds ";
        }
        t_tmp = num2ten[int(num[1]-'0')];
        if (t_tmp == "ten") {
            int count = 10 + int(num[2]-'0');
            tmp = tmp + num2ten[count] + " ";
            return tmp;
        }
        if (t_tmp != "zero")tmp = tmp + t_tmp + " ";
        t_tmp = num2char[int(num[2]-'0')];
        if (t_tmp != "zero")tmp = tmp + t_tmp + " ";
    }
    if (num.length() == 2) {
        string t_tmp = num2ten[int(num[0]-'0')];
        if (t_tmp == "ten") {
            int count = 10 + int(num[1]-'0');
            tmp = tmp + num2ten[count] + " ";
            return tmp;
        }
        if (t_tmp != "zero") {
            tmp = tmp + t_tmp + " ";
        }
        t_tmp = num2char[int(num[1]-'0')];
        if (t_tmp != "zero")tmp = tmp + t_tmp + " ";

    }
    if (num.length() == 1) {
        string t_tmp = num2char[int(num[0]-'0')];
        if (t_tmp != "zero")tmp = tmp + t_tmp + " ";
    }
    return tmp;
}

int main() {
    cout << "INT MAX" << INT_MAX <<endl;
    int num, flag = 0;    // flag for record the negative
    cin >> num;
    if (num < 0) {
        flag = 1;
        num = -num;
    }
    string num_str = int2str(num);
    cout << "length: " << num_str<<endl;
    vector<string> vec_str;
    vec_str = SliceNum(num_str);
    cout << vec_str.size()<<endl;
    string results;
    if (flag == 1) results += "minus ";
    for (size_t i=0; i< vec_str.size(); ++i) {
        cout<<vec_str[i]<<endl;
        results = results + Num2Eng(vec_str[i]) + engcount[vec_str.size()-1-i] + " ";
    }
    cout <<results <<endl;
}
