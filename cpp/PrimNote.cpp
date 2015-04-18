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
 # Last modified: 2015-04-18 19:07
 # 
 # Filename: PrimNote.cpp
 # 
 # Description: All Rights Are Reserved                 
 ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
/*
 * C++ Primer Review Note
 */
#include <iostream>
#include <limits>

void out()
{
    std::cout<<"/*"<<std::endl;
}
void unsi2si()
{
    unsigned i;
    i = -1;//mod operator
    std::cout<<"assign -1 to usigned variable "<<i<<std::endl;
}
void maxofbuiltin()
{
    std::cout<<"max int: "<<std::numeric_limits<int>::max()<<std::endl;
    std::cout<<"max long: "<<std::numeric_limits<long>::max()<<std::endl;
    std::cout<<"max double: "<<std::numeric_limits<double>::max()<<std::endl;
}
void backslash()
{
    std::cout\
        <<"cou \\"<<std::endl\
        <<"t<<..."<<\
        std::endl;
}
double power(double base,int exp)
{
    double val=1;
    while(exp--)
    {val *= base;}
    return val;
}
int main(int argc,char*argv[])
{
    //test the note function
    out();
    unsi2si();
    maxofbuiltin();
    std::cout<<"\nCC\toptions\tfile.[cC]\n"<<std::endl;
    backslash();
    double b;int e;
    std::cin>>b>>e;
    std::cout<<power(b,e)<<std::endl;

}
