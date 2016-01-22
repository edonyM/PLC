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
 # Last modified: 2015-09-28 19:42
 #
 # Filename: pointer.cc
 #
 # Description: All Rights Are Reserved
 ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
#include <iostream>
#include <string>
#include <cstring>
#include <cstdio>

using std::cout;
using std::cin;
using std::endl;
using std::string;

int main() {
    char *point = new char[3];
    point[0] = 'a';
    point[1] = '#';
    point[2] = '\0';
    cout << point << "<type char *>\n";
    cout << &point << "<pointer address>\n";
    cout << &(point[0]) << "<point[0] address>\n";
    printf("%p<--point[0] address-->\n", point);
    delete [] point;
    cout << &point << "<pointer address after delete>\n";
    int *a = new int[3];
    int b = 123;
    a[0] = 12;
    a[1] = 22;
    a[2] = 33;
    cout << a << "<type int *a\n";
    cout << b << "<type int b\n";
    cout << &a << "<pointer address>\n";
    cout << &b << "<int b address>\n";
    cout << &(a[0]) << "<a[0] address>\n";
    delete [] a;
    cout << &a << "<int array address>\n";
    //////////////////////////////////////////////////////
    //////////////////////////////////////////////////////
    //////////////////////////////////////////////////////
    cout << "//////////////////////////////////////////////////////\n";
    cout << "//////////////////////////////////////////////////////\n";
    cout << "//////////////////////////////////////////////////////\n";

    int *p[2];
    for (int i=0; i < 2; i++) {
        p[i] = new int[3];
    }
    for (int i=0; i < 2; i++) {
        for (int j=0; j < 3; j++) {
            p[i][j] = (1+i)*j;
        }
    }

    for (int i=0; i < 2; i++) {
        for (int j=0; j < 3; j++) {
            cout << *(*(p+i)+j) << endl;
            // cout << (p+i)[j] << endl;
        }
    }

    int (*p1)[3] = new int[2][3];
    for (int i=0; i < 2; i++) {
        for (int j=0; j < 3; j++) {
            p1[i][j] = (1+i)*(j+1);
        }
    }
    for (int i=0; i < 2; i++) {
        for (int j=0; j < 3; j++) {
            cout << p1[i][j] << endl;
        }
    }

    char arg1[] = "123";
    char arg2[] = "c-g";
    char arg3[] = "--outdate";
    char *cp[] = {arg1, arg2, arg3};
    cout << cp[0] << " | " << cp[1] << " | " << cp[2] << endl;

    // wrong for non-equilong string with type char (*)[];
    // char (*cp1)[] = {&arg1, &arg2, &arg3};
    // cout << cp1[0] << " | " << cp1[1] << " | " << cp1[2] << endl;
    char (*cp1)[10] = new char[3][10];
    int k;
    for (k=0; k < 3; k++) {
        strcpy(*(cp1+k), cp[k]);
    }
    cout << cp1[0] << " | " << cp1[1] << " | " << cp1[2] << endl;
}
