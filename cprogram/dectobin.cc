#include <iostream>
#include <string>
#include <cmath>

using std::cout;
using std::cin;
using std::endl;
using std::string;

string Dec2Bin(int num) {
    int tmp = num;
    string re;
    while (tmp) {
        int i = tmp % 2;
        re.insert(re.begin(), char(i + '0'));
        tmp = tmp / 2;
    }
    return re;
}

int Bin2Dec(string bin) {
    int len = bin.length();
    int num = 0;
    for (int i=0; i < len; ++i) {
        num += int(bin[i] - '0') * pow(2, len-1-i);
    }
    return num;
}

int main() {
    int non_frac_num = 0;
    cin >> non_frac_num;
    string bin;
    bin = Dec2Bin(non_frac_num);
    cout << bin << endl;
    cout << "convert binary into decimal number...\n";
    cout << Bin2Dec(bin) << endl;
    if (Bin2Dec(bin) == non_frac_num) cout << "Convertion is Correct!\n";
    else cout << "Wrong convertion!\n";
}

