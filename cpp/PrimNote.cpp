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
#include <list>
#include <deque>
#include <stack>
#include <utility>
#include <map>
#include <set>
#include <algorithm>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::vector;
using std::bitset;
using std::list;
using std::deque;
using std::stack;
using std::pair;
using std::map;
using std::set;

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
void inlinefun()
{
    //inline function can help to accelerate the execution
    //accturally, replace the inline function calling with the equlity expression
    //inline function is initialized and defined in head files
}
void classmemfunc()
{
    //public&private&protected(member function can access private data member)
    //default constructor needed to initialize members of built-in type
    //constructor can be initialzed with initialize list
    //overload function depends on function signature(prameter's number and type)
    //
    //int lookup(string tr);
    //int lookup(const string str);
    //these two functions are redefinition not overload
    //
    //int lookupa(string &str);
    //int lookupa(const string &str);
    //reference or pointer formula parameter are overload
    //int lookupb(string *str);
    //int lookupb(string *const str);
    //not overload
    //
    //int (*ff(int))(int*,int);
    //ff is a function takes a int parameter and return a pointer to a funtion(int(*)(int*,int))
}
void iolib()
{
    //IO standard library
    //#include <istream>//in stream
    //#include <ostream>//out stream
    //#include <iostream>//derive from istream and ostream
    //#include <fstream>//derive from iostream
                        //ifstream derive from istream
                        //ofstream derive from ostream
    //#include <sstream>//istringstream read from string object, derive from istream
                        //ostringstream write into string object,derive from ostream
                        //stringstream write and read with string object,derive from iostream
}
void containerandalg()
{
    /*******sequential container******/
    //vector, list, deque
    vector<string> svec;
    svec.push_back(string("edony"));
    svec.push_back(string("murphy"));
    vector<string> svec1(svec);
    vector<string>::iterator mid=svec1.begin()+svec1.size()/2;
    vector<string> svec2(svec1.begin(),mid);
    char *words[] = {"stately", "plump", "buck", "mulligan"};
    // calculate how many elements in words
    size_t words_size = sizeof(words)/sizeof(char *);
    cout<<"word size: "<<words_size<<endl;
    // use entire array to initialize words2
    list<string> words2(words, words + words_size);
    list<int> ilist;
    deque<string> items;
    vector<int> v;
    v.push_back(12);
    v.push_back(32);
    v.push_back(34);
    cout<<"v size: "<<v.size()<<endl;
    cout<<"v begin: "<<*v.begin()<<endl;
    cout<<"v end: "<<*v.end()<<endl;
    vector<int>::iterator first = v.begin(),
        last = v.end(); // cache end iterator
    // diaster: behavior of this loop is undefined
    //while (first != last)
    //{
     // do some processing
     // insert new value and reassign first, which otherwise would be invalid
     //first = v.insert(first, 42);
     //++first; // advance first just past the element we added
    //}
    //correct loops
    //while (first != v.end())
    //{
     // do some processing
     // insert new value and reassign first, which otherwise would be invalid
     //first = v.insert(first, 42);
     //cout<<"insert item"<<*first<<endl;
     //++first; // advance first just past the element we added
    //}
    /*******shared container in string******/
    //get details in file ./str.cpp

    /*******select container******/
    //list can better insert and delete element
    //vector deque can better access any element

    /*******container adaptor******/
    //#include <stack>
    //#include <queue>
    deque<int> deq;
    stack<int> stk(deq);
    cout<<"stack is empty: "<<stk.empty()<<endl;
    stk.push(1);
    stk.push(2);
    stk.push(3);
    stk.push(4);
    cout<<"size of stack: "<<stk.size()<<endl;
    cout<<"top of stack: "<<stk.top()<<endl;
    stk.pop();
    cout<<"pop stack: "<<stk.top()<<endl;

    /*******associative container******/
    //type pair----#include <utility>
    pair<string,string> anon;
    pair<string,int> word_count;
    pair<string,string> author("edony","cc");
    cout<<"pair first mem: "<<author.first<<endl;
    cout<<"pair second mem: "<<author.second<<endl;
    string astr("murphy");
    int age = 23;
    word_count = make_pair(astr,age);
    cout<<"makr_pair pair first mem: "<<word_count.first<<endl;
    cout<<"makr_pair pair second mem: "<<word_count.second<<endl;
    //associative container: map----#include <map> using std::map;
    map<string,int> wco;
    wco["edony"] = 23;
    wco["cc"] = 24;//key is const variabel that can not be changed 
    map<string,int>::iterator map_it = wco.begin();
    cout<<"first map member: "<< map_it->first <<endl;
    cout<<"second map member: "<< map_it->second <<endl;
    map<string,int>::key_type kt="longdd";
    cout<<"key type: "<<kt<<endl;
    //associative container: set----#include <set> using std::set;
    vector<int> ivec;
    for(vector<int>::size_type i=0;i!=10;++i)
    {
        ivec.push_back(i);
        ivec.push_back(i);
    }
    set<int> iset(ivec.begin(),ivec.end());
    cout<<"vector size: "<<ivec.size()<<endl;
    cout<<"set size: "<<iset.size()<<endl;
    int iarr[]={12,3,4,53,2,4,1,1,-1};
    vector<int> stvec;
    for(int i=0;i<9;i++)
    {
        stvec.push_back(iarr[i]);
    }
    sort(stvec.begin(),stvec.end());//algorithm head files
    for(vector<int>::size_type j=0;j!=stvec.size();j++)
    {cout<<j<<"th vector: "<<stvec[j]<<endl;}
    vector<int>::iterator enduniq = unique(stvec.begin(),stvec.end());
    int ju = 1;
    for(vector<int>::iterator iter=stvec.begin();iter!=enduniq;++iter)
    {
        cout<<ju<<"th unique vector: "<<*iter<<endl;
        ++ju;
    }
}
//classdetail()
    //class definition end with ';'
    class U_ptr//smart pointer for shared object pointed by some pointers
    {
        friend class constref;
        int *ip;
        size_t use_count;
        U_ptr():ip(new int),use_count(1){};
        U_ptr(int *p):ip(p),use_count(1){};
        ~U_ptr(){delete ip;}
    };
    class constref
    {
        public:
            constref();//default constructor can not initialize reference and const
            constref(int ii):i(ii),ci(ii),ri(i)
            {
                ptr = new U_ptr;
            };//list initialization
            explicit constref(double j):i(j),ci(j),ri(i)
            {
                ptr = new U_ptr;
            };//explicit only on class declaration(head file)
                                                   //explicit avoid implicit convertion
            constref(const constref &cp);//copy constructor
                                         //const formal parameter can not assign into other object
                                         //for this copy constructor take const reference formal parameter
            constref& operator=(const constref& ass);//assign operator overload
                                                     //ass right operator
                                                     //return *this left operator
            ~constref(){if(--ptr->use_count==0)delete ptr;};//destructor
            static double returnrate(){return rate;};
            void dosomethin(int para = crate);//static can ben default real parameter
            std::ostream& operator<<(const constref& cr);

        private:
            int i;
            const int ci;//const varibale can not be assigned
            int &ri;//reference has to initialize when create
            static double rate;
            const static int crate = 0;
            static double initstatic(){return 1.0;};//static member initialize function
            static constref mem1;//ok
            //constref *mem2;//ok
            //constref &mem3=*mem2;//ok
            //constref mem4;//error
            U_ptr *ptr;
    };
    //double constref::rate = 0.0;//direct initialize static member
    double constref::rate = constref::initstatic();
    //friend in class...
    //class static member replace of global variables for all class object access
    //
//operator overload
//be care of few use operator overload
//
//OOP: data abstract; inheritance; dynamic binding(virtual)
//data abstract:
//......public: class member and class friend and outer the class declare and derived subclass
//......protected: class member and class friend and derived subclass 
//......private: class member and class friend
//inheritance:
//......
    //class inh:public constref
    //{
        //...
    //};
//dynamic binding(virtual)
//......option 1: virtual member function
//......option 2: call the function with the reference of base class or pointer to base class
//
//details in file './virinclass.cpp'
//abstract virtual class: only used as a base class to derive from and can not create object of this class
//......class vc
//......{
//......    void interface() const =0;//pure virtual function
//......};
//
//handle class: manage and store base class pointer(pointer to a dynamic object)
//details in file './handleclass.cpp'
//
//generic programming(template)
template <typename T>
int compare(const T &v1, const T &v2)
{
    if(v1<v2)return -1;
    if(v1>v2)return 1;
    return 0;
}
// ok: inline specifier follows template parameter list
// template <typename T> inline T min(const T&, const T&);
// // error: incorrect placement of inline specifier
// inline template <typename T> T min(const T&, const T&);
//template class
template <class T> class Queue
{
    public:
        Queue();
        T &front();
        const T &front()const;
        void push(const T&);
        void pop();
        bool empty() const;
    private:
        //...
};
//non-type template formula parameter
template <typename T, size_t N> void array_init(T (&parm)[N])
{
    for(size_t i=0;i !=N; ++i)
        parm[i] = 0;
}
//generic programming with template needs to be reviewed agian
//
//exception class
//......
//
//memory arangement
//......
//
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
    containerandalg();
    constref cr(12);
    cout<<"static rate: "<<cr.returnrate()<<endl;
    //double outerclassstatic = constref::initstatic();
    double t1=12.3;
    double t2=12.11;
    cout<<"tmplate compared double: "<<compare(t1,t2)<<endl;
    string tstr1="cc";
    string tstr2="edony";
    cout<<"tmplate compared string: "<<compare(tstr1,tstr2)<<endl;
    int x[42];
    double y[10];
    array_init(x);
    array_init(y);
    cout<<"32th x element: "<<x[31]<<endl;
    cout<<"9th y element: "<<y[8]<<endl;
}
