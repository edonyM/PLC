 /*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
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
 # Last modified: 2015-04-02 10:06
 # 
 # Filename: swap.c
 # 
 # Description: All Rights Are Reserved                 
 ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/ 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void swap(int *a, int *b) {
    int *p;
    p = a;
    a = b;
    b = p;
    
}
void getmemory(char *p, int num) {
    /*
     * when call getmemory(char*, int) int main()
     * it runs like that getmemory(p=str, num=100);
     * p is a local variable that will be destroied after the function call finish
     * p = tmp do not change str
     */
    char *tmp;
    tmp = (char *)malloc(sizeof(char)*num);
    p = tmp;
}
int main()
{
    double a,b;
    int cou;
    cou = scanf("%lf %lf",&a,&b);
    //a,b = (b,a);
    printf("%lf, %lf\n",a,b);
    printf("%d\n",cou);
    double tmp;
    tmp = a;
    //a = b;
    //b = tmp;
    printf("%f\n",tmp);
    int c = 1, d = 2;
    swap(&c, &d);
    printf("%d, %d\n", c, d);
    char *str=NULL;
    printf("before %d", str);
    getmemory(str, 100);
    printf("after %d", str);
    strcpy(str, "hello");
    printf("%s", str);
}
