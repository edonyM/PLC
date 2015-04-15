 /*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
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
 # ##########################################################################################
 # 
 # Author: edony - edonyzpc@gmail.com                 
 # 
 # twitter : @edonyzpc                                
 # 
 # Last modified: 2015-04-15 16:08
 # 
 # Filename: pointer.c
 # 
 # Description: All Rights Are Reserved                 
 ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

#include <stdio.h>
#include <stdlib.h>
/* declare about the pointer
 * char **argv
 *     argv:  pointer to char
 * int (*daytab)[13]
 *     daytab:  pointer to array[13] of int
 * int *daytab[13]
 *     daytab:  array[13] of pointer to int
 * void *comp()
 *     comp: function returning pointer to void
 * void (*comp)()
 *     comp: pointer to function returning void
 * char (*(*x())[])()
 *     x: function returning pointer to array[] of
 *     pointer to function returning char
 * char (*(*x[3])())[5]
 *     x: array[3] of pointer to function returning
 *     pointer to array[5] of char
 */

int main(int argc,char *argv[])
{
    char* errp2char;
    errp2char = "edony";
    printf("p2char: %s\n, size of pointer: %d\n",errp2char,sizeof(errp2char));
    
    char* p2char=(char*)malloc(10*sizeof(char));
    p2char = "edony";
    printf("p2char: %s\n, size of pointer: %d\n",p2char,sizeof(p2char));
    char** pp2char=(char**)malloc(3*sizeof(char*));
    *pp2char = "Edony";
    *(pp2char+1) = "CC";
    *(pp2char+2) = "Murphy";
    int i;
    for(i=0;i<3;i++)
        printf("pp2char %d: %s\n",i+1,*(pp2char+i));

    //int* p2int;
    //*p2int=13;
    //printf("p2int %d",*p2int);

    int* p2int=(int*)malloc(1*sizeof(int));
    *p2int=13;
    printf("p2int %d\n, size of pointer: %d\n",*p2int,sizeof(p2int));

    int* dp2int=(int*)malloc(2*sizeof(int));
    *dp2int=13;
    *(dp2int+1)=122;
    printf("p2int %d\t %d\n, size of pointer: %d\n",*dp2int,*(dp2int+1),sizeof(dp2int));
    *(dp2int+2)=33;
    printf("print not allocate int %d\n",*(dp2int+2));
}
