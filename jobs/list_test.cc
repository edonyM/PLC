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
 # Last modified: 2015-09-02 20:09
 #
 # Filename: list_test.cc
 #
 # Description: All Rights Are Reserved
 ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
#include <iostream>
#include "link_list.hpp"

using std::cout;
using std::cin;
using std::endl;

int main() {
    int da[9] = {12, 3, -1, 45, 8, 19, 22, 9, 32};
    list *ls = (list *)malloc(sizeof(list));
    list_init(ls);
    //cout << ls << endl;
    for (int i=0; i < 9; ++i) {
        list_ins_next(ls, NULL, da[i]);
    }
    cout << list_size(ls) << endl;
    list_print(ls);
    cout << "TAIL: " << ls->tail->data << endl;
    cout << "**** PartI ****\n";
    node *rm=NULL;
    node *tmp = ls->head;
    while(tmp) {
        if (tmp->data == 45) {
            rm = tmp;
            break;
        }
        else {
            tmp = tmp->next;
        }
    }
    int pop = 0;
    list_rm_next(ls, rm, pop);
    list_print(ls);
    cout << "**** PartII ****\n";
    list_sort(ls);
    list_print(ls);
    list *ls1 = (list *)malloc(sizeof(list));
    node *h = (node *)malloc(sizeof(node));
    h->data = -3;
    h->next = NULL;
    ls1->head = h;
    ls1->tail = h;
    for (int i=0; i < 9; ++i) {
        list_ins_next(ls1, ls1->tail, i-2);
    }
    list_sort(ls1);
    list_print(ls1);
}
