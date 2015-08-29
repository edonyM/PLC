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
 # Last modified: 2015-08-29 17:17
 #
 # Filename: poly_queue.cc
 #
 # Description: All Rights Are Reserved
 ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
#define PI 3.1415927
#include <iostream>
#include "poly_list.h"

using std::cout;
using std::cin;
using std::endl;

typedef list<int> queue;


int main() {
    list<int> *ls = new list<int>;
    ls->head = NULL;
    ls->tail = NULL;
    ls->size = 0;
    for (int i=0; i < 3; ++i) {
        list_ins_next(ls, i-1, i+4);
    }
    node<int> *tmp = ls->head;
    while(tmp) {
        cout << tmp->data << endl;
        tmp = tmp->next;
    }
    for (int i=0; i < 3; ++i) {
        //cout << i-1 << "**\n";
        //cout << ls << endl;
        list_remove_next(ls, -1);
        if (ls->tail) cout << "tail: " << ls->tail->data << endl;
        else cout << "empty list\n";
    }
    cout << ls->size << endl;
    list<double> *ls1 = new list<double>;
    ls1->head = NULL;
    ls1->tail = NULL;
    ls1->size = 0;
    for (int i=0; i < 3; ++i) {
        list_ins_next(ls1, i-1, (i+1)*PI);
    }
    node<double> *tmp1 = ls1->head;
    while(tmp1) {
        cout << tmp1->data << endl;
        tmp1 = tmp1->next;
    }
    for (int i=0; i < 3; ++i) {
        //cout << i-1 << "**\n";
        //cout << ls << endl;
        list_remove_next(ls1, -1);
        if (ls1->tail) cout << "tail: " << ls1->tail->data << endl;
        else cout << "empty list\n";
    }
    cout << ls1->size << endl;
}
