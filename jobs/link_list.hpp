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
 # Last modified: 2015-09-02 10:54
 #
 # Filename: link_list.hpp
 #
 # Description: All Rights Are Reserved
 ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

// TODO(edony): link list tail pointer problem

#include <iostream>
#include <cstdlib>

using std::cout;
using std::cin;
using std::endl;

typedef struct node_ {
    int data;
    node_ *next;
}node;

typedef struct list_ {
    node *head;
    node *tail;
    int size;
}list;

int list_size (list *ls) {
    if (ls) return ls->size;
    else return -1;
}

void list_init(list *ls) {
    //ls = (list *)malloc(sizeof(list));
    ls->head = NULL;
    ls->tail = NULL;
    ls->size = 0;
}

int list_ins_next(list *ls, node *pos, int data) {
    node *ins = (node *)malloc(sizeof(node));
    if (!ins) return 0;
    ins->data = data;
    if (!pos) {
        if (!ls->head) {
            ins->next = NULL;
            ls->head = ins;
            ls->tail = ins;
        }
        else {
            node *tmp_next = ls->head;
            ins->next = tmp_next;
            ls->head = ins;
        }
        ls->size++;
        return 1;
    }
    else {
        if (!ls->head) {
            return 0;
        }
        else {
            node *tmp_next = pos->next;
            if (!tmp_next) {ls->tail = ins;}
            pos->next = ins;
            ins->next = tmp_next;
            ls->size++;
            return 1;
        }
    }
}

int list_rm_next(list *ls, node *pos, int &data) {
    if (!ls->head) {
        return 0;
    }
    if (!pos) {
        node *rm = ls->head;
        if (!rm->next) {ls->tail = pos;}
        ls->head = ls->head->next;
        data = rm->data;
        rm->next = NULL;
        free(rm);
        ls->size--;
        return 1;
    }
    else {
        node *rm = pos->next;
        if (!rm->next) {ls->tail = pos;}
        pos->next = pos->next->next;
        data = rm->data;
        rm->next = NULL;
        free(rm);
        ls->size--;
        return 1;
    }
}

void list_print(list *);
void swap(int &a, int &b) {
    int tmp = a;
    a = b;
    b = tmp;
}
void list_sort(list *ls) {
    int len = ls->size;
    for (int i=1; i <= len; ++i) {
        int counter = len - i;
        node *start_tmp = ls->head;
        node *end_tmp = ls->head;
        while (counter > 0) {
            end_tmp = end_tmp->next;
            counter--;
        }
        int flag = 0;
        while (start_tmp) {
            if (start_tmp == end_tmp) break;
            node *tmp = start_tmp->next;
            if (tmp) {
                if (start_tmp->data > tmp->data) {
                    swap(start_tmp->data, tmp->data);
                }
                else {
                    flag++;
                }
            }
            start_tmp = start_tmp->next;
        }
        if (flag == (len-i)) {cout << i << " flag\n";return;}
        //list_print(ls);
    }
}

void list_print(list *ls) {
    int len = ls->size;
    node *tmp = ls->head;
    while(tmp) {
        cout << tmp->data << endl;
        tmp = tmp->next;
    }
}

void list_reverse(list *ls) {
    node *head_bak = ls->head;
    node *old_node = ls->head;
    node *new_node = ls->head->next;
    while (new_node) {
        if (old_node == ls->head) old_node->next = NULL;
        node *tmp = new_node->next;

        new_node->next = old_node;

        old_node = new_node;
        new_node = tmp;
    }
    ls->head = old_node;
    ls->tail = head_bak;
}

node *list_circle(list *ls) {
    node *fast = ls->head;
    node *slow = ls->head;
    while (fast && fast->next) {
        fast = fast->next->next;
        slow = slow->next;
        if (fast == slow) {
            break;
        }
    }
    if ((fast == NULL) || (fast->next == NULL)) {
        return NULL;
    }
    else {
        cout << fast->data << " same\n";
        slow = ls->head;
        while (slow != fast) {
            slow = slow->next;
            fast = fast->next;
        }
        return slow;
    }
}
