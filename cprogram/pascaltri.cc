#include <iostream>
#include <vector>
#include <cassert>

using std::cout;
using std::cin;
using std::endl;
using std::vector;
using std::cerr;

vector<int> row_pascaltri(int row) {
    vector<int> ls_row;
    ls_row.push_back(1);
    if (row == 1) return ls_row;
    if (row == 2) {
        ls_row.push_back(1);
        return ls_row;
    }
    int row_counter = 2;
    if (row > 2) {
        ls_row.push_back(1);
        while (row_counter < row) {
            vector<int> tmp;
            tmp.push_back(1);
            for (int i=0; i < ls_row.size() - 1; ++i) {
                tmp.push_back(ls_row[i] + ls_row[i+1]);
            }
            tmp.push_back(1);
            ls_row = tmp;
            row_counter++;
        }
        return ls_row;
    }
}

int main() {
    int row, col;
    cout << "enter row of pascal triangle\n";
    cin >> row;
    cout << "enter colum of pascal triangle\n";
    cin >> col;
    if (row < col) {
        cerr << "Wrong Input Number\n";
        //return 1;
    }
    assert(row >= col);
    vector<int> re;
    re = row_pascaltri(row);
    for (int i=0; i<re.size();i++) cout << re[i] <<" ";
    cout <<endl;
    cout << "the element is " << re[col-1] << endl;
}
