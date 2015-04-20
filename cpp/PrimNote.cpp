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
#include <string>
#include <vector>
#include <bitset>
#include <cstring> //c-style string standard library
#include <cstdio>
#include <cassert>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::vector;
using std::bitset;

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
    //extern double pi = 3.14159; //this is definition for the declared pi are initialized
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
    //int &rv;//reference initialized when definition
    //rv = i;
    //cout<<"reference definition: "<<rv<<endl;
}
void Class()
{
    std::cout<<"//Each class defines an interface and implementation\n";
    std::cout<<"//The interface consists of the operations that we expect code that uses the class to execute\n";
    std::cout<<"//The implementation typically includes the data needed by the class.\n";
    std::cout<<"//The implementation also includes any functions needed to define the class but that are not intended for general use\n";
    std::cout<<"//Define a class: define interface-->class data && some other functions to implement\n";
}
void HeadFile()
{
    std::cout<<"head file accumulate the declare\n";
    std::cout<<"head file should not include definition to avoid multi-definition link error except class definition, const object and inline function\n";
    std::cout<<"#include <> //standard head file\n";
    std::cout<<"#include \"\" //customized head file\n";
}
void StdLib()
{
    //using std::cout;
    //using std::cin;
    //using std::string;
    cout<<"Standard Library includes string, vector and bitset\n";
    /*******std::string******/
    string s1;//default construct
    string s2("edony");
    string s3(s2);
    string s4(5,'e');
    cout<<s1<<endl
        <<s2<<endl
        <<s3<<endl
        <<s4<<endl
        <<s2.empty()<<endl
        <<s3.size()<<endl //string size type is string::size_type
        <<s3[1]<<endl;
    cout<<"read a line\n";
    string line;
    cin.get();//ignore the \n in cin buffer
    getline(cin,line);
    cout<<line<<endl;
    const char* fromstr;
    fromstr = s2.c_str();
    cout<<fromstr<<endl;
    /*******std::vector******/
    vector<int> ivec1(2);//default int vector
    vector<int> ivec2(ivec1);
    int i=12;
    vector<int> ivec3(3,i);
    ivec3.push_back(i+2);
    ivec3.size();//size type is vector<int>::size_type
    ivec3.empty();
    /*******iterator******/
    vector<int>::iterator iter;
    iter = ivec2.begin();
    *iter = i;
    cout<<"exer3.15: "<<ivec2[0]<<endl;
    for(vector<int>::const_iterator i = ivec3.begin();
            i != ivec3.end();
            i++)
    {
        cout<<*i<<endl;
    }
    for(vector<int>::size_type is=0;
            is != ivec3.size();
            is++)
    {
        cout<<ivec3[is]<<endl;
    }
    /*******bitset******/
    bitset<16> bitvec1(0xffff);//0~15 equals 1
    bitset<32> bitvec2(0xffff);//0~15 equals 1 and 16~31 equals 0
    string strval("1100");
    bitset<32> bitvec3(strval);
    cout<<bitvec3<<endl;
    cout<<bitvec2<<endl;
    cout<<bitvec1<<endl;
}
void PointArray()
{
    //if you are not focus on the performence of the code ,you'd better use vector rather than array
    /******* Array Definition and Initialization ******/
    // both buf_size and max_files are const
    const unsigned buf_size = 512, max_files = 20;
    int staff_size = 27; // nonconst
    //const unsigned sz = get_size(); // const value not known until run time
    char input_buffer[buf_size]; // ok: const variable
    string fileTable[max_files + 1]; // ok: constant expression
    //double salaries[staff_size]; // error: non const variable
    //int test_scores[get_size()]; // error: non const expression
    //int vals[sz]; // error: size not known until run time
    /******* Pointer ******/
    cout<<"RULE NO.1\n"
        <<"... avoid using non-initialized pointer\n"
        <<"... pointed object comes first\n"
        <<"... initialize the pointer point to object or NULL\n";
    const int c_ival = 0;
    int* pi;
    //pi = c_ival;//legal but call segmentation fault
    pi=0;//or pi=NULL
    cout<<" : "<<pi<<endl;
    // const object pointer
    double pd = 3.14;
    const double d = 23.4;
    const double *cptr=&d;
    const void* cpv=&d;
    const double* cptr_=&pd;
    cout<<"point to const pointing plain: "<<*cptr_<<endl;
    //const pointer
    int num = 2;
    int* const curErr = &num;
    *curErr = 23;
    cout<<curErr<<endl;
    //typedef and pointer
    typedef string* pstring;
    string s("edony");
    const pstring cstr=&s;//equals string* const cstr
    pstring const cstr1=&s;//same type with cstr
    /*******c-style string******/
    char a1[]={'C','+','+'};//no NULL,not c-style string
    char a2[]={'C','+','+','\0'};
    char a3[]= "C++";//c-style string(NULL terminator added automatically)
    const char *cp = "C++";//c-style
    //s-style string standard library
    //#include <cstring>
    cout<<"origin length"<<strlen(cp)<<endl;
    cout<<"strcmp: "<<strcmp(cp,a2)<<endl;
    //a2 point to new a c-style string that equals strcat(a2,cp)
    cout<<"before strcat() the address of a2: "<<&a2<<endl;
    strcat(a2,cp);
    cout<<"after strcat() the address of a2: "<<&a2<<endl;
    cout<<"after strcat()"<<strlen(a2)<<endl;
    strncat(a2,cp,2);
    cout<<"cat 2 elements in cp into a2: "<<a2<<endl;
    strcpy(a3,"edony");
    cout<<"copy new string into a3 with strcpy(): "<<a3<<endl;
    /*******dynamic array******/
    char* in=new char[10];
    cin>>in;
    cout<<"Your input c-style string: "<<in<<endl;
    //delete in;//oops!!!maybe memory leakage
    delete []in;//remind that we are to free the array object not a single object
    /*******multidimensional array******/
    //array with its element is array
    int ia[2][2]={
                  {1,2},
                  {3,4}
                 };
    //typedef for multi-dim array
    typedef int int_array[2];
    int_array *pia = ia;
    for(int i=0;i<2;i++)
        for(int j=0;j<2;j++)
        {
            cout<<(*(pia+i))[j]<<" ";
            if(j%2!=0)cout<<endl;
        }
}
void Expression()
{
    //expression in c++ consist of operator symbol and operator object
    //bitwise operation
    unsigned int bit = 1;
    bit<<2;
    bit>>2;//right shift need the operator object bit is non-negative number and the digits in bit must larger than left operator object
    cout<<bit<<endl;
    int b1 = 013;
    int b2 = 023;
    cout<<"XOR: "<<(b1^b2)<<endl;
    cout<<"AND: "<<(b1&b2)<<endl;
    cout<<"OR: "<<(b1|b2)<<endl;
    /******* bitset & bitwise operation******/
    bitset<32> bitset_quizl;
    unsigned long int_quizl = 0;
    bitset_quizl.set(27);
    int_quizl |= 1UL<<27;
    bitset_quizl.reset(27);
    int_quizl &= ~(1UL<<27);
    //assignment operator has a lower precedence
    int itest=0;
    while((itest=1)==0)
    {cout<<"enter the loops!\n";}
    cout<<"itest: "<<itest<<endl;
    int arr[2]={2,4};
    int* pprecedence=arr;
    cout<<*pprecedence++<<endl;
    cout<<*pprecedence<<endl;
    //dangling pointer
    int *pi = new int();
    *pi = 3;
    delete pi;
    //now pi is a dangling pointer,best way to do is set the pi NULL
    pi=NULL;
    //type cast
    //... dynamic_cast(later)
    //... const_cast
    const char* pc_str="edony";
    char t[3]="cc";
    char* p_str=t;//=const_cast<char*>(pc_str);
    cout<<pc_str<<endl;
    cout<<p_str<<endl;
    //... statci_cast
    double dn = 3.14;
    int r = 3;
    cout<<"area: "<<r*static_cast<int>(dn)<<endl;
    int cn = static_cast<char>('a');
    switch(cn)
    {
        case'a':
            cn++;//oops! missing break;
        case'c':
            cn++;//executed
        case'e':
            cn++;//executed again
        case'd':
            cn++;//executed again
    }
    //case true:
    // error: declaration precedes a case label
    // string file_name = get_file_name();
    // break;
    //case false:
    // ...
    switch(static_cast<bool>(cn))
    {
        case true:
        {
            const char* filename="dp.txt";
            printf("file name %s\n",filename);
            //do something
        }
        break;
        case false:
            cout<<"end of define a new variable in case\n";
    }
    cout<<"cn: "<<static_cast<char>(cn)<<endl;
    //exception
    string word;
    if(cin>>word)
    {
        std::cerr<<"Error: "<<__FILE__
                 <<":line "<<__LINE__<<endl
                 <<"    Compiled on "<<__DATE__
                 <<" at "<<__TIME__<<endl
                 <<"    Word read was "<<word
                 <<":Length too short"<<endl;
    }
    assert(word.size()>3);//head file <cassert>
}
void reset(int*p)
{
    *p = 122;
    p=0;
}
void printval(const int* beg,const int* end)
{
    while(beg!=end)
    {cout<<*beg++<<endl;}
}
char whilereturn(const string &str1);//function prototype and mostly in head files
int ff(int i2,int i=4,int i3=5);//default parameter
void func()
{
    int num=12;
    reset(&num);
    cout<<num<<endl;
    int a[3] = {13,3,4};
    printval(a,&a[2]);
    //function can not nest definition
    //
    string ss = "edonta";
    string ss2 = "ooq";
    char tmp = whilereturn(ss2);
    cout<<tmp<<endl;//nothing to cout if there is no return after while loops and the compile cannot detect it
    cout<<whilereturn(ss)<<endl;
    cout<<"ff: default parameter "<<ff(12)<<endl;
    cout<<"ff(10) "<<ff(12,10)<<endl;

}
int ff(int i2,int i,int i3)
{
    return (i3+i)*(i2+i);
}
char whilereturn(const string &str1)
{
    size_t len=str1.size();
    while(len)
    {
        if(str1[len--]=='a')
            return str1[len+1];
        else
            continue;
    }
    //error: control might flow off the end of the function without return
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
    StdLib();
    PointArray();
    Expression();
    func();

}
