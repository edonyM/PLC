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
 # Last modified: 2015-06-23 19:57
 #
 # Filename: shuff.cc
 #
 # Description: All Rights Are Reserved
 ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;

string card[54] = {
                    "S1", "S2", "S3", "S4", "S5", "S6", "S7", "S8", "S9", "S10", "S11", "S12", "S13",
                    "H1", "H2", "H3", "H4", "H5", "H6", "H7", "H8", "H9", "H10", "H11", "H12", "H13",
                    "C1", "C2", "C3", "C4", "C5", "C6", "C7", "C8", "C9", "C10", "C11", "C12", "C13",
                    "D1", "D2", "D3", "D4", "D5", "D6", "D7", "D8", "D9", "D10", "D11", "D12", "D13",
                    "J1", "J2"
};

int main() {
    int times;
    cin >> times;
    int pos[54];
    for (int i=0; i < 54; i++) cin >> pos[i];
    //cout << "pos\n";
    //for (int r=0; r < 54; ++r) { cout << pos[r] << " ";}
    string card_shuff[54];
    for (int j=0; j < 54; ++j) {
        card_shuff[j] = card[j];
    }
    //for (int r=0; r < 54; ++r) { cout << card_shuff[r] << " ";}
    //cout << endl;
    string re[54];
    for (int k=0; k < times; ++k) {
        for (int j=0; j < 54; ++j) {
            re[pos[j]-1] = card_shuff[j];
        }
        for (int j=0; j < 54; ++j) {
            card_shuff[j] = re[j];
        }
    }
    for (int r=0; r < 54; ++r) {
        if (r == 53) cout << re[r];
        else cout << re[r] << " ";
    }
}
