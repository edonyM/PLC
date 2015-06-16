#include <iostream>
#include <cassert>
#include <cstring>

using std::cout;
using std::cin;
using std::endl;

typedef struct node_ {
    int num;
    char a[10];
    node_ *next;
}node;

typedef struct list_ {
    int size;
    node *head;
    node *tail;
}list;

list *CreateList() {
    list *tmp = new list;
    tmp->head = new node;
    tmp->tail = new node;
    tmp->size = 0;
    return tmp;
}

void push(list *ls, node *n) {
    if (ls->head->next == NULL) {
        ls->head->next = n;
        ls->tail = n;
        ls->tail->next = NULL;
        ls->size++;
    }
    else {
        cout << ls->size << endl;
        ls->tail->next = n;
        ls->tail = n;
        ls->tail->next = NULL;
        cout << ls->tail << endl;
        ls->size++;
    }
}

node *pop(list *ls) {
    assert(ls->size);
    node *tmp = NULL;
    node *tail_new = ls->head;
    int size = ls->size;
    while (size > 1) {
        tail_new = tail_new->next;
        size--;
    }
    tmp = ls->tail;
    ls->tail = tail_new;
    ls->tail->next = NULL;
    ls->size--;
    cout << tmp << " pop item\n";
    return tmp;
}

list *reverse(list *ls) {
    list *re_ls = new list;
    node *tmp = NULL;
    int size = ls->size;
    while (size > 0) {
        tmp = pop(ls);
        node *tt = ls->head;
        for (int i=0; i<ls->size;i++) {
            cout << tt->next << endl;
            tt = tt->next;
        }
        push(re_ls, tmp);
        size--;
    }
    return re_ls;
}

int main() {
    list *ls;
    char tmp[3][10] = {"edony", "cc", "murphy"};
    ls = CreateList();
    for (int i=0; i < 3; ++i) {
        node *n = new node;
        n->num = i;
        strcpy(n->a,tmp[i]);
        n->next = NULL;
        push(ls, n);
    }
    node *tt = ls->head;
    for (int i=0; i<3;i++) {
        cout << tt->next << endl;
        tt = tt->next;
    }
    int size = ls->size;
    cout << "Reverse: " << endl;
    list *re_ls = NULL;
    re_ls = reverse(ls);
    node *t_node = re_ls->head->next;
    for (int i=1; i<3; ++i) {
        cout << t_node->num << " " << t_node->a << endl;
        t_node = t_node->next;
    }
}
