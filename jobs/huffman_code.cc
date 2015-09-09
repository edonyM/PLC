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
 # Last modified: 2015-09-09 10:29
 #
 # Filename: huffman_tree.cc
 #
 # Description: All Rights Are Reserved
 ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
// no use dynamic library: STL, MFC, ALT
// TODO(edony): need to tested
#include <iostream>
#include "link_list.hpp"

using std::cout;
using std::cin;
using std::endl;

typedef struct bTree_ {
    int data;
    bTree_ *left;
    bTree_ *right;
}bTree;

void HuffTree(vector<bTree*> q, bTree *hufftree) {
    if (q->size == 1) return;
    bTree *new_node = (bTree*)malloc(sizeof(bTree));
    sort(q.begin(), q.end());
    new_node->data = q[0]->data + q[1]->data[1];
    if (q[0]->data < q[1]->data) {
        new_node->left = q[0];
        new_node->right = q[1];
    }
    else {
        new_node->left = q[1];
        new_node->right = q[0];
    }
    q.erase(q[0]);
    q.erase(q[1]);
    q.push_back(new_node);
    HuffTree(q, hufftree);
}

int HuffCompress(bTree *hufftree, char *code, char **compressed, int size) {
    int com_code = 0;
    for (int i=0; i < size; ++i) {
        char tmp = code[i];
        bTree *b_tmp = bufftree;
        vector<char> c_code;
        while (b_tmp->data != tmp) {
            if (!b_tmp) return -1;
            if (b_tmp->data < tmp) {
                com_code << 1;
                c_code.push_back('0');
                b_tmp = b_tmp->left;
            }
            else {
                com_code << 1;
                com_code |= 1;
                c_code.push_back('1');
                b_tmp = b_tmp->right;
            }
        }
        size_t len = c_code.size();
        char *mem_code = (char*)malloc(sizeof(char)*len + 1);
        vector<char>::iterator iter = c_code.begin();
        int counter = 0;
        for(; iter != c_code.end(); ++iter) {
            mem_code[counter++] = *iter;
        }
        mem_code[counter] = '\0';
        compressed[i] = mem_code;
    }
}

int HuffUncompress(bTree *hufftree, char **compressed, char *code) {
    char **tmp = compressed;
    int len = sizeof(tmp)/sizeof(char *);
    code = (char*)malloc(sizeof(char)*len);
    for (int i=0; i < len; ++i) {
        char *com_code = tmp[i];
        bTree *tree_tmp = hufftree;
        while (com_code!='\0') {
            if (com_code == '0') {
                tree_tmp = tree_tmp->left;
            }
            else {
                tree_tmp = tree_tmp->right;
            }
            com_code++;
        }
        code[i] = tree_tmp->data;
    }
}
