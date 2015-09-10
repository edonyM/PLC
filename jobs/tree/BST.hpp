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
 # Last modified: 2015-09-10 20:24
 #
 # Filename: BST.hpp
 #
 # Description: All Rights Are Reserved
 ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
#include <iostream>

using std::cout;
using std::cin;
using std::endl;

typedef struct bstnode_ {
    int data;
    bstnode_ *left;
    bstnode_ *right;
}bstnode;

typedef struct bst_ {
    bstnode *root;
    int size;
}bst;

void bst_init(bst *bstree) {
    bstree->root = NULL;
    bstree->size = 0;
}

bstnode *bst_search(bst *bstree, int data) {
    bstnode *tmp = bstree->root;
    while (tmp) {
        if (data < tmp->data) {
            tmp = tmp->left;
        }
        if (data > tmp->data) {
            tmp = tmp->right;
        }
        if (data == tmp->data) {
            return tmp;
        }
    }
    if (!tmp) return NULL;
}

int bst_ins(bst *bstree, int data) {
    bstnode *ins = (bstnode*)malloc(sizeof(bstnode));
    if (!ins) return 0;
    ins->left = NULL;
    ins->right = NULL;
    ins->data = data;
    bstnode *tmp = bstree->root;
    while (tmp) {
        if (data < tmp->data) {
            if (tmp->left) {
                tmp = tmp->left;
            }
            else {
                tmp->left = ins;
                bstree->size++;
                return 1;
            }
        }
        else {
            if (tmp->right) {
                tmp = tmp->right;
            }
            else {
                tmp->right = ins;
                bstree->size++;
                return 1;
            }
        }
    }
}

int bst_rm(bst *bstree, int data) {
    bstnode *tmp = bst_search(bstree, data);
    if (tmp == NULL) return 0;
    if (tmp->left == NULL && tmp->right == NULL) {
        free(tmp);
        return 1;
    }
    bst_rm(tmp->left, data);
    bst_rm(tmp->right, data);
}
