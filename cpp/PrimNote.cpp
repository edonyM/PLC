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
void namestyle()
{
    std::cout<<"1. variables are named with lowercase\n"
             <<"2. identifier(variables) should be readable\n"
             <<"3. multi-words identifier split with _\n"
             <<"4. keep personal style\n";
}
void InitializeNotAssign()
{
    std::cout<<"1. identifier's initialize doesn't equal its assignment\n"
             <<"... Initialization is create a variable and assign it\n"
             <<"... assignment is change the exsited value\n"
             <<"2. int ival(1024); // direct-initialization\n"
             <<"... int ival = 1024; // copy-initialization\n"
             <<"... direct-initialization is efficient\n"
             <<"3. builtin types are hardly recommended to initialized for avoiding safety issues\n";
}
void DeclareDefinition()
{
    std::cout<<"definition is declaring a variable and allocate it\n"
             <<"declare is declaring a variable to the program\n"
             <<"you can declared the variable more than one time but you can not redefinition\n";
    extern int i; //declare but does not define i
    extern double pi = 3.14159; //this is definition for the declared pi are initialized
                                //this working with global extern declaration is possibly not in function
    int idd; //declare and define idd
}
void ConstIsLocal()
{
    std::cout<<"// file_1.cc\n"
             <<"// defines and initializes a const that is accessible to other files\n"
             <<"extern const int bufSize = fcn();\n"
             <<"// file_2.cc\n"
             <<"extern const int bufSize; // uses bufSize from file_1\n"
             <<"// uses bufSize defined in file_1\n"
             <<"for (int index = 0; index != bufSize; ++index)\n"
             <<"    // ...\n";
}
void Reference()
{
    int ival = 1024;
    int &refVal = ival; // ok: refVal refers to ival
    std::cout<<"int &refVal2; // error: a reference must be initialized\n";
    std::cout<<"int &refVal3 = 10; // error: initializer must be an object\n";
    const int cival = 1024;
    const int &crefVal = cival; // ok: both reference and object are const
    std::cout<<"int &ref2 = ival; // error: non const reference to a const object\n";
    int i = 42;
    const int &r = 42;//legal for const reference only
    const int &r1 = i + 2;//legal for const reference only
    double dval = 3.14;
    const int &ri = dval;/*int tmp = dval;
                          *const int &ri = tmp;
                          */
}
void Class()
{

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
