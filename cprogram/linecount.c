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
 # Last modified: 2015-06-09 22:15
 #
 # Filename: linecount.c
 #
 # Description: All Rights Are Reserved
 ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
#include <stdio.h>

int main(int argc, char *argv[]) {
    if (argc == 2) {
        int counter = 0;
        int byte_counter = 0;
        FILE *fp = NULL;
        char ch;
        fp = fopen(argv[1], "rb");
        if (fp == NULL) {
            printf("Can not open file %s", argv[1]);
            return 1;
        }
        while ((ch=fgetc(fp)) != EOF) {
            //printf("%c", ch);
            ++byte_counter;
            //if (ch == '\n' || ch == '\r') {
            //    ++counter;
            //}
        }
        rewind(fp);
        //fseek(fp, 0, SEEK_SET);
        //freopen(argv[1], "rb", fp);
        while (!feof(fp)) {
            char str[256];
            fgets(str, 256, fp);
            printf("%s", str);
            ++counter;
        }
        fclose(fp);
        fp = NULL;
        printf("Total Line: %d \nTotal Size: %d Bytes\n", counter, byte_counter);
    }
}
