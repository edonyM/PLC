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
 # Last modified: 2015-09-03 17:14
 #
 # Filename: doub_list.hpp
 #
 # Description: All Rights Are Reserved
 ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
#include <iostream>
#include <cstdlib>

using std::cout;
using std::cin;
using std::endl;

typedef struct d_node_ {
    int data;
    d_node_ *pre;
    d_node_ *next;

}d_node;

typedef struct doub_list_ {
    int size;
    d_node *head;
    d_node *tail;
}doub_list;

int doub_list_init(doub_list *dls) {
    if (!dls) {
        return 0;
    }
    else {
        dls->size = 0;
        dls->head = NULL;
        dls->tail = NULL;
        return 1;
    }
}

int destroy(d_node *des) {
    if (des) {
        des->pre = NULL;
        des->next = NULL;
        free(des);
        return 1;
    }
    else {
        return 0;
    }
}

int doub_list_ins(doub_list *dls, d_node *pos, int data) {
    d_node *ins = (d_node *)malloc(sizeof(d_node));
    ins->data = data;
    ins->pre = NULL;
    ins->next = NULL;
    if (!pos) {
        if (!dls->head) {
            dls->head = ins;
            dls->tail = ins;
        }
        else {
            d_node *tmp = dls->head;
            ins->next = tmp;
            tmp->pre = ins;
            dls->head = ins;
        }
        dls->size++;
        return 1;
    }
    else {
        if (!dls->head) {
            return 0;
        }
        else {
            d_node *tmp = pos->next;
            if (!tmp) {
                dls->tail = ins;
            }
            ins->next = tmp;
            ins->pre = pos;
            tmp->pre = ins;
            pos->next = ins;
            dls->size++;
        }
    }
}

int doub_list_rm(doub_list *dls, d_node *rm, int &data) {
    // TODO(edony):update the pointer dls->tail
    if (!dls) {
        return 0;
    }
    else {
        if (!rm) {
            d_node *tmp = dls->head;
            data = tmp->data;
            dls->head = dls->head->next;
            tmp->next = NULL;
            dls->head->pre = NULL;
            if (destroy(tmp)) {
                dls->size--;
                return 1;
            }
            else {
                return 0;
            }
        }
        else {
            data = rm->data;
            d_node *tmp = rm->pre;
            tmp->next = rm->next;
            rm->next->pre = tmp;
            if (destroy(rm)) {
                dls->size--;
                return 1;
            }
            else {
                return 0;
            }
        }
    }
}

void doub_list_print(doub_list *dls) {
    d_node *tmp = dls->head;
    while (tmp) {
        cout << tmp->data << endl;
        tmp = tmp->next;
    }
}

void doub_list_sort(doub_list *dls) {
    // insert sort
    if (!dls) {
        cout << "empty list\n";
    }
    else {
        int data = 0;
        d_node *tmp = dls->head->next;
        d_node *rm = NULL;
        int counter = 3;
        while (counter) {
            if (rm) {doub_list_rm(dls, rm, data);}
            d_node *ins = tmp;
            while (ins) {
                if (ins->data > tmp->data) {ins = ins->pre;}
                else {break;}
            }
            doub_list_print(dls);
            cout << "###: " << ins->pre->data<< "\n";
            if (doub_list_ins(dls, ins->pre, tmp->data)) {
                doub_list_print(dls);
                cout << "&&&\n";
                rm = tmp;
                tmp = tmp->next;
                counter--;
            }
        }
    }
}
