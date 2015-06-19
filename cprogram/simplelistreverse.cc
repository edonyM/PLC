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
 # Last modified: 2015-06-19 15:05
 #
 # Filename: simplelistreverse.cc
 #
 # Description: All Rights Are Reserved
 ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
#include <iostream>
#include <cstring>
#include <cstdio>

using std::cout;
using std::cin;
using std::endl;

typedef struct node_ {
    int num;
    char a[10];
    node_ *next;
}node;

void print_reverse(node* list) {
    if ( list != 0 )
    {
        print_reverse( list->next );
        printf( "%d, %s\n", list->num, list->a);
    }
}


int main() {
    node *ls = new node;
    ls->num = -1;
    ls->next = NULL;
    node *ls_p = ls;
    char tmp[4][10] = {"edony", "cc", "murphy", "kangro"};
    for (int i=0; i < 3; ++i) {
        node *n = new node;
        n->num = i;
        strcpy(n->a,tmp[i]);
        n->next = NULL;
        ls_p->next = n;
        ls_p = ls_p->next;
    }
    cout << "Origin: " << endl;
    node *tt = ls;
    for (int i=0; i<3; ++i) {
        tt = tt->next;
        cout << tt->num << " " << tt->a << endl;
    }
    cout << "Reverse: " << endl;
    print_reverse(ls->next);
}
