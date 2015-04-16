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
void printtest(int*num,char*name);

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
    //free(p2char);//core dump
    //free(pp2char);//core dump

    int* p2int=(int*)malloc(1*sizeof(int));
    *p2int=13;
    printf("p2int %d\n, size of pointer: %d\n",*p2int,sizeof(p2int));

    int* dp2int=(int*)malloc(2*sizeof(int));
    *dp2int=13;
    *(dp2int+1)=122;
    printf("p2int %d\t %d\n, size of pointer: %d\n",*dp2int,*(dp2int+1),sizeof(dp2int));
    *(dp2int+2)=33;
    printf("print not allocate int %d\n",*(dp2int+2));
    free(p2int);
    free(dp2int);

    //###################################################
    int (*daytab)[3] = malloc(2*sizeof(int[3]));
    int tmp[2][3] = {{1,33,4},{2,45,6}};
    int tmp2[3] = {2,45,6};
    daytab = &tmp[0];
    printf("int[3]: %d\n",sizeof(int[3]));
    printf("daytab: %d\n",daytab);
    printf("daytab: %d\n",daytab+1);
    printf("daytab: %d, %d, %d\n",(*(daytab))[0],(*(daytab))[1],(*(daytab))[2]);
    //printf("daytab: %d, %d, %d\n",(*(daytab-1))[0],(*(daytab-1))[1],(*(daytab-1))[2]);
    printf("daytab: %d, %d, %d\n",(*(daytab+1))[0],(*(daytab+1))[1],(*(daytab+1))[2]);
    printf("daytab: %d, %d, %d\n",(*(daytab+2))[0],(*(daytab+2))[1],(*(daytab+2))[2]);
    //free(daytab);//core dump
    
    //###################################################
    int *daytab1[3];
    int *tint = malloc(3*sizeof(int));
    *tint = 12;
    *(tint+1) = 123;
    *(tint+2) = 33;
    int *tint2 = malloc(2*sizeof(int));
    *tint2 = 45;
    *(tint2+1) = 444;
    int *tint3 = malloc(sizeof(int));
    *tint3 = 4;
    daytab1[0] = tint;daytab1[1] = tint2;
    daytab1[2] = tint3;
    int fi;
    for(fi=0;fi<3;fi++)
    {
       printf("*** %d, %d, %d\n",daytab1[0][0],daytab1[1][1],daytab1[2][0]);
    }
    free(tint);
    free(tint2);
    free(tint3);
    
    //###################################################
    void (*comp)(int*,char*);
    comp = printtest;
    int*num = malloc(3*sizeof(int));
    *num = 12;
    *(num+1) = 3;
    *(num+2) = 34;
    char* name = "edony";

    comp(num,name);
}

void printtest(int*num,char*name)
{
    printf("%d, %d, %d\n",*num,*(num+1),*(num+2));
    printf("name is %s\n",name);
}
