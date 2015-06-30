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
 # Last modified: 2015-06-30 15:35
 #
 # Filename: treetraversal.cc
 #
 # Description: All Rights Are Reserved
 ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
#include <iostream>
#include <string>

#define N 30

using std::cout;
using std::cin;
using std::endl;
using std::string;

typedef struct node_ {
    int num;
    node_ *left;
    node_ *right;
}node;

typedef struct BiTree_ {
    int size;
    node *root;
}BiTree;

void PostOrder(int *pre, int *in, int *post, int len) {
    if (len == 0) {
        return;
    }
    if (len == 1) {
        *post = *pre;
        return;
    }
    int root = *pre;
    *(post+len-1) = root;
    int i;
    for (i=0; i < len; ++i) {
        if (*(in+i) == root) break;
    }
    int left_len = i;
    int right_len = len - left_len - 1;
    // left
    PostOrder(pre+1, in, post, left_len);
    // right
    PostOrder(pre+left_len+1, in+left_len+1, post+left_len, right_len);
}

int main() {
    int n;
    cin >> n;
    string operate[2*n];
    int inorder[n];
    int preorder[n];
    int postorder[n];
    int stack[n];
    int top = -1;
    int counter = 0;
    int counter_pre = 0;
    for (int i=0; i < 2*n; ++i) {
        cin >> operate[i];
        if (operate[i] == "Push") {
            top++;
            cin >> stack[top];
            preorder[counter_pre] = stack[top];
            counter_pre++;
        }
        else {
            inorder[counter] = stack[top];
            top--;
            counter++;
        }
    }
//    for (int i=0; i < n; ++i) {
//        cout << inorder[i] << endl;
//    }
//    for (int i=0; i < n; ++i) {
//        cout << preorder[i] << endl;
//    }
    PostOrder(preorder, inorder, postorder, n);
    for (int i=0; i < n; ++i) {
        if (i == n-1) cout << postorder[i] << endl;
        else cout << postorder[i] << " ";
    }
}
