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
 # Last modified: 2015-06-26 21:59
 #
 # Filename: formularoot.cc
 #
 # Description: All Rights Are Reserved
 ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cassert>

using std::cout;
using std::cin;
using std::endl;

typedef struct BiTreeNode_ {
    double value;
    BiTreeNode_ *right;
    BiTreeNode_ *left;
}BiTreeNode;

typedef struct BiTree_ {
    int size;
    BiTreeNode *root;
}BiTree;

double F_x(double para[4], double x) {
    return para[0]*pow(x,3) + para[1]*pow(x,2) + para[2]*x + para[3];
}

double FindRL(double para[4], double a, double b) {
    assert(a<=b);
    double right = 0.0;
    double left = 0.0;
    right = F_x(para, a) * F_x(para, (a+b)/2);
    left = F_x(para, (a+b)/2) * F_x(para, b);
    if (right < 0) {
        return a;
    }
    else if (left < 0) {
        return b;
    }
}

bool HasTwoDec(double value, double results) {
    if (std::abs(value - results) < 0.001) {
        return true;
    }
    else {
        return false;
    }
}

void InitFormulaBiTree(BiTree *tree, double para[4], double a, double b) {
    BiTreeNode *a_n = new BiTreeNode;
    BiTreeNode *b_n = new BiTreeNode;
    BiTreeNode *root = new BiTreeNode;
    a_n->value = a;
    a_n->right = NULL;
    a_n->left = NULL;
    b_n->value = b;
    b_n->right = NULL;
    b_n->left = NULL;
    root->value = (a+b)/2;
    root->left = a_n;
    root->right = b_n;
    int size = 3;
    double results = a; 

    while (1) {
        if (HasTwoDec(root->value, results)) break;
        results = root->value;
        double middle = (root->left->value + root->right->value)/2;
        double endpoint = FindRL(para, root->left->value, root->right->value);
        BiTreeNode *mid = new BiTreeNode;
        mid->value = middle;
        mid->left = root->left;
        mid->right = root->right;
        BiTreeNode *end = new BiTreeNode;
        end->value = endpoint;
        end->left = NULL;
        end->right = NULL;
        if (middle > endpoint) {
            root->left = end;
            root->right = mid;
        }
        else {
            root->left = mid;
            root->right = end;
        }
        root->value = (mid->value + end->value)/2;
        size += 2;
        //cout << "val " << root->value << endl;
        //cout << "res " << results << endl;
        //cout << results << " " << root->value << " " << root->left->value  << " " << root->right->value << endl;
    }
    tree->size = size;
    tree->root = root;
}

int main() {
    double para[4];
    for (int i=0; i < 4; ++i) {
        cin >> para[i];
    }
    double a,b;
    cin >> a >> b;
    BiTree *tree = new BiTree;
    InitFormulaBiTree(tree, para, a, b);
    printf("%.2f\n", tree->root->value);
}
