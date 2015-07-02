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
# Last modified: 2015-07-02 14:36
#
# Filename: rootAVL.cc
#
# Description: All Rights Are Reserved
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
#include <iostream>

#define AVL_LEFT_HEV 1
#define AVL_BALANCED 0
#define AVL_RIGHT_HEV -1

using std::cout;
using std::cin;
using std::endl;

typedef struct AVLnode_ {
	int data;
	AVLnode_ *left;
	AVLnode_ *right;
	int factor;
}AVLnode;

typedef struct AVLTree_ {
	int size;
	AVLnode *root;
}AVLTree;

void AVLTreeInit(AVLTree *tree) {
	tree->size = 0;
	tree->root = NULL;
};

void RotateLeft(AVLnode **node) {
	AVLnode *left, *grand;
	left = (*node)->left;
	if (left->factor == AVL_LEFT_HEV) {
		// LL rotate
		(*node)->left = left->right;
		left->right = *node;
		(*node)->factor = AVL_BALANCED;
		left->factor = AVL_BALANCED;
		*node = left;
	}
	else {
		// LR rotate
		grand = left->right;
		left->right = grand->left;
		grand->left = left;
		(*node)->left = grand->right;
		grand->right = *node;

		switch(grand->factor) {
			case AVL_LEFT_HEV:
				(*node)->factor = AVL_RIGHT_HEV;
				left->factor = AVL_BALANCED;
				break;
			case AVL_BALANCED:
				(*node)->factor = AVL_BALANCED;
				left->factor = AVL_BALANCED;
				break;
			case AVL_RIGHT_HEV:
				(*node)->factor = AVL_BALANCED;
				left->factor = AVL_LEFT_HEV;
				break;
		}
		grand->factor = AVL_BALANCED;
		*node = grand;
	}
	return;
};

void RotateRight(AVLnode **node) {
	AVLnode *right, *grand;
	right = (*node)->right;
	if (right->factor == AVL_RIGHT_HEV) {
		// RR rotate
		(*node)->right = right->left;
		right->left = *node;
		(*node)->factor = AVL_BALANCED;
		right->factor = AVL_BALANCED;
		*node = right;
	}
	else {
		// RL rotate
		grand = right->left;
		right->left = grand->right;
		grand->right = right;
		(*node)->right = grand->left;
		grand->left = *node;

		switch(grand->factor) {
			case AVL_LEFT_HEV:
				(*node)->factor = AVL_BALANCED;
				right->factor = AVL_RIGHT_HEV;
				break;
			case AVL_BALANCED:
				(*node)->factor = AVL_BALANCED;
				right->factor = AVL_BALANCED;
				break;
			case AVL_RIGHT_HEV:
				(*node)->factor = AVL_LEFT_HEV;
				right->factor = AVL_BALANCED;
				break;
		}
		grand->factor = AVL_BALANCED;
		*node = grand;
	}
	return;
};

void InsLeft(AVLTree *tree, AVLnode **ins_node, AVLnode *new_node) {
	AVLnode **position;
	if (ins_node == NULL) {
		// insert node is empty
		position = &tree->root;
	}
	else {
		position = &(*ins_node)->left;
	}
	*position = new_node;
	tree->size++;
}

void InsRight(AVLTree *tree, AVLnode **ins_node, AVLnode *new_node) {
	AVLnode **position;
	if (ins_node == NULL) {
		// insert node is empty
		position = &tree->root;
	}
	else {
		position = &(*ins_node)->right;
	}
	*position = new_node;
	tree->size++;
}

void AVLTreeIns(AVLTree *tree, AVLnode **node, int data, int *factor) {
	AVLnode **pos;
	AVLnode *new_node = new AVLnode;
	if (node == NULL) {
		// empty tree
		new_node->data = data;
		new_node->left = NULL;
		new_node->right = NULL;
		new_node->factor = AVL_BALANCED;
		InsLeft(tree, node, new_node);
		//tree->root = new_node;
	}
	else {
		// non-empty tree
		// left insert
		if (data < (*node)->data) {
			if ((*node)->left == NULL) {
				new_node->data = data;
				new_node->left = NULL;
				new_node->right = NULL;
				new_node->factor = AVL_BALANCED;
				InsLeft(tree, node, new_node);
				*factor = 0;
			}
			else {
				pos = &((*node)->left);
				AVLTreeIns(tree, pos, data, factor);
			}

			if (!(*factor)) {
				switch((*node)->factor) {
					case AVL_LEFT_HEV:
						RotateLeft(node);
						*factor = 1;
						break;

					case AVL_BALANCED:
						(*node)->factor = AVL_LEFT_HEV;
						break;

					case AVL_RIGHT_HEV:
						(*node)->factor = AVL_BALANCED;
						*factor = 1;
						break;
				}
			}
		}
		//right insert
		else if (data > (*node)->data) {
			if ((*node)->right == NULL) {
				new_node->data = data;
				new_node->left = NULL;
				new_node->right = NULL;
				new_node->factor = AVL_BALANCED;
				InsRight(tree, node, new_node);
				*factor = 0;
			}
			else {
				pos = &((*node)->right);
				AVLTreeIns(tree, pos, data, factor);
			}
			if (!(*factor)) {
				switch((*node)->factor) {
					case AVL_LEFT_HEV:
						(*node)->factor = AVL_BALANCED;
						*factor = 1;
						break;

					case AVL_BALANCED:
						(*node)->factor = AVL_RIGHT_HEV;
						break;

					case AVL_RIGHT_HEV:
						RotateRight(node);
						*factor = 1;
						break;
				}
			}
		}
	}
}

int main() {
	int size;
	cin >> size;
	int *num = new int[size];
	AVLTree *tree = new AVLTree;
	AVLTreeInit(tree);
	int *factor = new int;
	for (int i=0; i < size; ++i) {
		cin >> num[i];
	}
	AVLnode **node = NULL;
	for (int i=0; i < size; ++i) {
		AVLTreeIns(tree, node, num[i], factor);
		node = &(tree->root);
	}
	cout << tree->root->data << endl;
}
