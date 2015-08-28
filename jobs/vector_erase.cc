#include <vector>
#include <iostream>

using std::vector;
using std::cout;
using std::endl;

int main() {
    vector<int> array;
    array.push_back(1);
    array.push_back(6);
    array.push_back(6);
    array.push_back(3);
    vector<int>::iterator itor;
    vector<int>::iterator itor1;
    for (itor=array.begin(); itor!=array.end();) {
        if (6==*itor) {
            itor1 = itor;
            itor = array.erase(itor1);
        }
        else {
            itor++;
        }
    }
    for (size_t i=0; i < array.size(); ++i) {
        cout << array[i] << endl;
    }
}
