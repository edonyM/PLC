#include <iostream>
#include <list>
#include <string>

using std::cout;
using std::endl;
using std::string;
using std::list;
//using namespace std;

struct node {
    int num;
    string name;
};

list<node> rev(list<node> ls) {
    list<node> tmp(ls.rbegin(), ls.rend());
    return tmp;
}


int main() {
    int a[3] = {1, 2, 3};
    list<node> re;
    string str[3] = {"edony", "cc", "murphy"};
    for (int i=0; i < 3; ++i) {
        node tmp;
        tmp.num = a[i];
        tmp.name = str[i];
        re.push_back(tmp);
    }
    list<node> af_re;
    list<node> af_re1(re.rbegin(), re.rend());
    af_re = rev(re);
    list<node>::iterator pos_b;
    cout << "Before reverse: " << endl;
    for (pos_b=re.begin(); pos_b != re.end(); ++pos_b) {
        cout << (*pos_b).num << " " << (*pos_b).name << endl;
    }
    list<node>::iterator pos;
    cout << "After reverse: " << endl;
    for (pos=af_re.begin(); pos != af_re.end(); ++pos) {
        cout << (*pos).num << " " << (*pos).name << endl;
    }
    list<node>::iterator pos_1;
    cout << "After reverse: " << endl;
    for (pos_1=af_re.begin(); pos_1 != af_re.end(); ++pos_1) {
        cout << (*pos_1).num << " " << (*pos_1).name << endl;
    }
}
