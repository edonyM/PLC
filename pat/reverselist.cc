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
 # Last modified: 2015-06-25 14:37
 #
 # Filename: reverselist.cc
 #
 # Description: All Rights Are Reserved
 ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::vector;

typedef struct node_ {
    string address;
    int data;
    string next;
}node;

int main() {
    string begin_address;
    int n_num;
    int k_num;
    cin >> begin_address >> n_num >> k_num;
    vector<node> input_node_list;
    for (int i=0; i < n_num; ++i) {
        string add_tmp;
        int data_tmp;
        string next_tmp;
        cin >> add_tmp >> data_tmp >> next_tmp;
        node *element = new node;
        element->address = add_tmp;
        element->data = data_tmp;
        element->next = next_tmp;
        input_node_list.push_back(*element);
    }
    vector<node>::iterator iter = input_node_list.begin();
    while (iter != input_node_list.end()) {
        if ((*iter).address != begin_address) {
            iter++;
            continue;
        }
        else {break;}
    }
    vector<node> origin_seq_list;
    origin_seq_list.push_back(*iter);
    for (int j=0; j < n_num-1; ++j){
        for (vector<node>::iterator i=input_node_list.begin(); i < input_node_list.end(); ++i) {
            if ((*i).address == (*iter).next) {
                origin_seq_list.push_back(*i);
                iter = i;
            }
        }
    }
    vector<node> reverse_list;
    vector<node>::iterator tmp_iter_beg = origin_seq_list.begin();
    vector<node>::iterator tmp_iter_end = tmp_iter_beg + k_num;
    do {
        vector<node> tmp(tmp_iter_beg, tmp_iter_end);
        vector<node> reverse_tmp(tmp.rbegin(), tmp.rend());
        for (vector<node>::iterator i=reverse_tmp.begin(); i < reverse_tmp.end(); ++i) {
            reverse_list.push_back(*i);
        }
        tmp_iter_beg = tmp_iter_end;
        tmp_iter_end = tmp_iter_beg + k_num;
        if (tmp_iter_end > origin_seq_list.end()){
            tmp_iter_end = origin_seq_list.end();
        }
    }while (tmp_iter_end < origin_seq_list.end());
    for (vector<node>::iterator i=tmp_iter_beg; i < origin_seq_list.end(); ++i) {
        reverse_list.push_back(*i);
    }
    for (vector<node>::iterator i=reverse_list.begin(); i < reverse_list.end()-1; ++i) {
        (*i).next = (*(i+1)).address;
    }
    (reverse_list.end()-1)->next = "-1";
    for (vector<node>::iterator i=reverse_list.begin(); i < reverse_list.end(); ++i) {
        cout << i->address << " " << i->data << " " << i->next << endl;
    }
}
