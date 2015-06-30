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
 # Last modified: 2015-06-23 18:44
 #
 # Filename: circlemove.cc
 #
 # Description: All Rights Are Reserved
 ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int *CircleMove(int *num_list, int move, int size) {
    int step = move;
    while (step > 0) {
        int tmp = num_list[size-1];
        for (int i=size-2; i >= 0; i--) {
            num_list[i+1] = num_list[i];
        }
        num_list[0] = tmp;
        step--;
    }
    return num_list;
}

int main() {
    int size;
    cin >> size;
    int move;
    cin >> move;
    int *num_list = new int[size];
    for (int i=0; i < size; ++i) {
        cin >> num_list[i];
    }
    int *move_list = NULL;
    move_list = CircleMove(num_list, move, size);
    for (int j=0; j < size; ++j) {
        if (j < (size-1)) cout << move_list[j] << ' ';
        else cout << move_list[j];
    }
//    cout << endl;
}
