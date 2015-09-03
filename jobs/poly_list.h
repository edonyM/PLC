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
 # Last modified: 2015-08-29 16:52
 #
 # Filename: poly_list.h
 #
 # Description: All Rights Are Reserved
 ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
#ifndef poly_lish_h
#define poly_list_h
#include <cstddef>
#include <iostream>
using std::cout;
template <class T>
struct node {
    T data;
    struct node *next;
};

template <class T>
int destroy(struct node<T> *rm) {
    if (rm) {
        //cout << "delete\n";
        rm->next = NULL;
        delete rm;
        return 1;
    }
    else {
        return 0;
    }
}

template <class t>
struct list {
    struct node<t> *head;
    struct node<t> *tail;
    unsigned int size;
};

template <class t>
unsigned int size(struct list<t> *ls) {
    if (ls)
    {
        return ls->size;
    }
    else {
        return -1;
    }
}

template <class t>
int list_ins_next(struct list<t> *ls, unsigned int pos, t data) {
    if (!ls || pos == -1) {
        struct node<t> *new_node = new struct node<t>;
        new_node->data = data;
        new_node->next = NULL;
        ls->head = new_node;
        ls->tail = new_node;
        ls->size++;
        return 1;
    }
    else {
        unsigned int counter = pos;
        struct node<t> *tmp = ls->head;
        for (unsigned int i=0; i < counter; ++i) {
            if (tmp->next) {
                tmp = tmp->next;
            }
            else {
                return 0;
            }
        }
        struct node<t> *new_node = new struct node<t>;
        new_node->data = data;
        new_node->next = NULL;
        struct node<t> *after = tmp->next;
        tmp->next = new_node;
        new_node->next = after;
        if (after == NULL) {
            ls->tail = new_node;
        }
        ls->size++;
        return 1;
    }
}

template <class t>
int list_remove_next(list<t> *ls, unsigned int pos) {
    if (!ls) {
        return 0;
    }
    if (pos == -1) {
        struct node<t> *tmp_h = ls->head;
        ls->head = tmp_h->next;
        if (tmp_h->next == NULL) {
            ls->tail = NULL;
        }
        if (destroy(tmp_h)) {
            ls->size--;
            return 1;
        }
        else {
            return 0;
        }
    }
    else {
        unsigned int counter = pos;
        struct node<t> *tmp = ls->head;
        for (unsigned int i=0; i < counter; ++i) {
            if (tmp->next) {
                tmp = tmp->next;
            }
            else {
                return 0;
            }
        }
        struct node<t> *after = tmp->next;
        tmp->next = after->next;
        if (destroy(after)) {
            ls->size--;
            return 1;
        }
        else {
            return 0;
        }
    }
}
#endif
