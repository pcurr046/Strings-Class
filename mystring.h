//*************************************************************************************
//This file is the declaration file of MyString class.
//*************************************************************************************
//MyStrings class is an ADT that encapsulates a dynamically allocated array of
//characters into an object that uses it's own methods to operate on a sequence of
// characters.
//The class's invariant is that the length() of the object's must be
//zero (in which case, the element contained by the dynamically allocated array will
//be '\0') or more at any point in time during the existence of the MyString object.
//The length() may return a zero because strlen() counts all elements of a c-string
//array without including the terminating null character itself. The private member
//variable of the MyString class is also designed to never overflow.
//Another crucial condition for our class to exist is that *str private data variable
//must always be non-null.
//Throughout the methods, we make use of C standard library in built functions.
//Following operators are overloaded to simplify common operation execution: +, +=,
//<,>,<=,>=,==,!=,[],= as well as the extraction >> and insertion << operators.
//A copy constructor, destructor and overloaded assignment operator is provided to
//run the proper memory allocation and de-allocation as necessary.
//*************************************************************************************
//class MyString {
// private:
//    char *str;
// public:
//    static const int MAX_INPUT_SIZE = 127;
//    this is a static constant variable used for temp array size

//    int length() const;
//    function returns length of private variable

//    MyString();
//    default constructor

//    MyString(const char* inString);
//    parameterized constructor

//    ~MyString();
//    class destructor

//    MyString operator=(const MyString& right);
//    Function overloads assignment operator

//    MyString(const MyString& copyMe);
//    Copy constructor, makes a deep copy

//    MyString operator += (const MyString& rightOp);
//    Function overloads addition to self operator

//    friend MyString operator + (const MyString& leftOp, const MyString& rightOp);
//    Function overloads addition operator

//    friend std::ostream& operator << (std::ostream &out, const MyString& printMe);
//    Function overloads extraction operator

//    char operator[] (int index) const;
//    Function overloads [] operator, allowing access to value stored in subscript

//    char& operator [] (int index);
//    Function overloads [] operator, allowing changes to value stored in subscript

//    friend bool operator < (const MyString leftOp, const MyString rightOp);
//    Function overloads less than operator

//    friend bool operator <= (const MyString leftOp, const MyString rightOp);
//    Function overloads less or equal operator

//    friend bool operator > (const MyString leftOp, const MyString rightOp);
//    Function overloads greater than operator

//    friend bool operator >= (const MyString leftOp, const MyString rightOp);
//    Function overloads greater than or equal operator

//    friend bool operator == (const MyString leftOp, const MyString rightOp);
//    Function overloads is equal to operator

//    friend bool operator != (const MyString leftOp, const MyString rightOp);
//    Function overloads different than operator

//    friend std::istream& operator >> (std::istream& in, MyString& readMe);
//    Function overloads insertion operator

//    void readline(std::istream& in, char delim);
//    Function parses through a stream and turns parts of stream data into objects
//};
//*************************************************************************************

#ifndef MYSTRING_H
#define MYSTRING_H
#include <fstream>
namespace cs_mystring {
    class MyString {
    private:
        char *str;
    public:
        static const int MAX_INPUT_SIZE = 127;
        int length() const;//use strlen???
        MyString();  // default constructor
        MyString(const char* inString); // parameterized constructor//use strcopy???
        ~MyString();  // class destructor
        MyString operator=(const MyString& right);  // = operator used in client code
        MyString(const MyString& copyMe);  //copy constructor makes a deep copy
        MyString operator += (const MyString& rightOp);
        friend MyString operator + (const MyString& leftOp, const MyString& rightOp);
        friend std::ostream& operator << (std::ostream &out, const MyString& printMe);
        char operator[] (int index) const;
        char& operator [] (int index);
        friend bool operator < (const MyString leftOp, const MyString rightOp);
        friend bool operator <= (const MyString leftOp, const MyString rightOp);
        friend bool operator > (const MyString leftOp, const MyString rightOp);
        friend bool operator >= (const MyString leftOp, const MyString rightOp);
        friend bool operator == (const MyString leftOp, const MyString rightOp);
        friend bool operator != (const MyString leftOp, const MyString rightOp);
        friend std::istream& operator >> (std::istream& in, MyString& readMe);
        void readline(std::istream& in, char delim);
    };
}
#endif

/*Output:
 * Project#4: MyString class (ADT) client program to test CLASS INVARIANT
The class has one private data member defined as follows:
char *str;
str always represents a valid null-terminated c-string for each instance
of a MyString class object class.
The client code provides an interface to test correct operations on MyString
objects

Here is a list of tests and the order in which the tests will be conducted
1. BasicTest
2. RelationTest
3. ConcatTest
4. CopyTest

***********************************************************************
* Basic Test: Testing various member constructor options and nonmember*
* friend ostream << operator for basic MyString object creation &     *
* printing                                                            *
***********************************************************************
string [0] = Wow
string [1] = C++ is neat!
string [2] =
string [3] = a-z

***********************************************************************
* Basic Test: Testing nonmember friend istream >> and ostream <<      *
* operators for reading and display of MyString objects from data file*
***********************************************************************

----- first, word by word
Read string = The
Read string = first
Read string = time
Read string = we
Read string = will
Read string = read
Read string = individual
Read string = words,
Read string = next
Read string = we
Read string = read
Read string = whole
Read string = lines

*************************************************************************
* Basic Test: Testing member function readline read, a nonmember friend *
* istream >> and ostream <<operators for reading and display of MyString*
* objects from data file                                                *
* ***********************************************************************

----- now, line by line
Read string = The  first  time  we  will
Read string =     read individual words, next
Read string = we read whole lines

****************************************************************************
* Basic Test: Testing access to characters (using const and non const)     *
* using constructors, member function length that returns a cstring length,*
* the square bracket [] overloaded operator and a nonmember friend         *
* istream >> for display of MyString objects content                       *
* **************************************************************************

----- Testing access to characters (using const)
Whole string is abcdefghijklmnopqsrtuvwxyz
now char by char: abcdefghijklmnopqsrtuvwxyz

----- Testing access to characters (using non-const)
Start with abcdefghijklmnopqsrtuvwxyz and convert to ABCDEFGHIJKLMNOPQSRTUVWXYZ

***********************************************************************
* RelationTest: Testing nonmember friend binary Boolean <, <=, >, >=, *
*  ==, != relational operators between MyString objects               *
***********************************************************************
Comparing app to apple
	Is left < right? true
	Is left <= right? true
	Is left > right? false
	Is left >= right? false
	Does left == right? false
	Does left != right ? true
Comparing apple to
	Is left < right? false
	Is left <= right? false
	Is left > right? true
	Is left >= right? true
	Does left == right? false
	Does left != right ? true
Comparing  to Banana
	Is left < right? true
	Is left <= right? true
	Is left > right? false
	Is left >= right? false
	Does left == right? false
	Does left != right ? true
Comparing Banana to Banana
	Is left < right? false
	Is left <= right? true
	Is left > right? false
	Is left >= right? true
	Does left == right? true
	Does left != right ? false

***********************************************************************
* RelationTest: Testing nonmember friend binary Boolean <, <=, >, >=, *
*  ==, != relational operators between MyString objects and char      *
***********************************************************************
Comparing he to hello
	Is left < right? true
	Is left <= right? true
	Is left > right? false
	Is left >= right? false
	Does left == right? false
	Does left != right ? true
Comparing why to wackity
	Is left < right? false
	Is left <= right? false
	Is left > right? true
	Is left >= right? true
	Does left == right? false
	Does left != right ? true

************************************************************************
* ConcatTest: Testing nonmember friend binary arithmetic + operator    *
* that do concatenation on MyString objects                            *
************************************************************************

----- Testing concatenation on MyStrings
outrageous + milk = outrageousmilk
milk +  = milk
 + cow = cow
cow + bell = cowbell

************************************************************************
* ConcatTest: Testing nonmember friend binary arithmetic + operator    *
* that do concatenation between MyString objects and char*             *
************************************************************************

----- Testing concatenation between MyString and char *
abcde + XYZ = abcdeXYZ
XYZ + abcde = XYZabcde

************************************************************************
* ConcatTest: Testing member binary arithmetic += operator             *
* that do concatenation between MyString objects and char*             *
************************************************************************

----- Testing shorthand concat/assign using MyString and char *
I love  += programming = I love programming

*****************************************************************************
* CopyTest: Testing default constructor, copy constructor and member        *
* assignment = operator on MyStrings to check for memberwise shallow copy   *
* the member square bracket [] overloaded operator and a nonmember friend   *
* ostream << for display of MyString objects content                        *
* ***************************************************************************

----- Testing copy constructor and operator= on MyStrings
original is cake, copy is fake
original is cake, copy is fake
after self assignment, copy is Copy Cat
Testing pass & return MyStrings by value and ref
after calling Append, sum is BinkyBoo
val is winky
after assign,  val is BinkyBoo

Project#4 -MyString class (ADT) testing now concluded.
MyString class destructor has been invoked and memory from the heap deallocated
Check output for correct results from the MyString class (ADT) implementation.*/