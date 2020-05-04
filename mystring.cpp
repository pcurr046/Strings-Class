//*************************************************************************************
//MyString class implementation file
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

#include "mystring.h"
#include <cstring>
#include <string.h>
#include <cassert>
#include <iostream>
#include <fstream>
using namespace std;

namespace cs_mystring{
    //*************************************************************************************
    //This function counts the number of elements of the dynamically allocated char array
    //private member variable by using C standard library inbuilt function strlen().
    //Function will operate on read-only self and return an int of size zero or greater
    //*************************************************************************************
    int MyString::length() const//use strlen
    {
        int length = strlen(this->str);
        return length;
    }

    //*************************************************************************************
    //This is the default constructor. It will dynamically allocate memory for the private
    //data variable, making the default dynamically allocated array of a size zero,
    //therefore only contain the '\0' element.
    //*************************************************************************************
    MyString::MyString()  // default constructor
    {
        str = new char[0];
        strcpy(str, "\0");
    }

    //*************************************************************************************
    //This is the parameterized constructor that takes in as a parameter a read-only
    //pointer to an array of characters. It will then correctly dynamically allocate
    //memory to assign to the new object it creates, and copy inString data into the
    //new object's private member variable
    //*************************************************************************************
    MyString::MyString(const char* inString) // parameterized constructor --> use strcopy
    {
        int size = strlen(inString) + 1;
        str = new char[size];
        strcpy(str, inString);
    }

    //*************************************************************************************
    //This is the destructor. As long as str pointer is not null, it will deallocate
    //the memory as long as it has been previously allocated to it, therefore destroying
    //the object.
    //*************************************************************************************
    MyString::~MyString()  // class destructor
    {
        if(str != nullptr)
            delete [] str;
    }

    //*************************************************************************************
    //This is the overloaded "=" operator. It will create a deep copy of the read only
    //object passed by reference and store it in the calling object (aka left operand or
    //self).
    //*************************************************************************************
    MyString MyString::operator=(const MyString &right)  // = operator used in client code
    {

        if(this != &right){
            delete [] str;
            int size = right.length()+1;
            str = new char[size];
            strcpy(str, right.str);
        }
        return *this;
    }

    //*************************************************************************************
    //This is the copy constructor. The copy constructor will be called when a new object
    //is created and initialized with an existing object's data. New memory will be
    //dynamically allocated to specs and copyMe's data will be copied in the new object
    //created.
    //*************************************************************************************
    MyString::MyString(const MyString& copyMe)  //copy constructor makes a deep copy
    {
        int size = copyMe.length();
        str = new char [size+1];
        strcpy(str, copyMe.str);
    }

    //*************************************************************************************
    //This is the overloaded insertion operator. It allows us to insert the object in
    //the out stream.
    //*************************************************************************************
    std::ostream& operator << (std::ostream &out, const MyString& printMe)
    {
        out << printMe.str;
        return out;
    }

    //*************************************************************************************
    //This is the overloaded "[]". This will give our class an "array-like" behaviour.
    //It will allow access to a certain subscript of the MyString class as long as the
    //subscript requested access to is valid.
    //Because the function returns a character by value (an rvalue), it can be used to
    //create expressions only on the right side of the assignment operator.
    //*************************************************************************************
    char MyString::operator[] (int index) const
    {
        assert(index >= 0 && index < strlen(str));
        return str[index];
    }

    //*************************************************************************************
    //This is the overloaded "[]". This will give our class an "array-like" behaviour.
    //It will allow access to a certain subscript of the MyString class as long as the
    //subscript requested access to is valid.
    //This function returns a reference to the element in the object's data indexed by the
    //subscript,(an lvalue), therefore the return can be used to create expressions placed
    //on the left side of the assignment operator.
    //*************************************************************************************
    char& MyString::operator [] (int index)
    {
        assert(index >= 0 && index < strlen(str));
        return str[index];
    }

    //*************************************************************************************
    //This is the overloaded "<" operator. It assesses if the leftOp object is less than
    //the rightOp object with the help of the strcmp C Standard library inbuilt function.
    //*************************************************************************************
    bool operator < (const MyString leftOp, const MyString rightOp)
    {
        if(strcmp(leftOp.str, rightOp.str)<0)
            return true;
        else
            return false;
    }

    //*************************************************************************************
    //This is the overloaded "<=" operator. It assesses if the leftOp object is less or
    //equal than the rightOp object with the help of the strcmp C Standard library inbuilt
    //function.
    //*************************************************************************************
    bool operator <= (const MyString leftOp, const MyString rightOp)
    {
        if(strcmp(leftOp.str, rightOp.str)<=0)
            return true;
        else
            return false;
    }

    //*************************************************************************************
    //This is the overloaded ">" operator. It assesses if the leftOp object is greater than
    //the rightOp object with the help of the strcmp C Standard library inbuilt function.
    //*************************************************************************************
    bool operator > (const MyString leftOp, const MyString rightOp)
    {
        if(strcmp(leftOp.str, rightOp.str)>0)
            return true;
        else
            return false;
    }

    //*************************************************************************************
    //This is the overloaded ">=" operator. It assesses if the leftOp object is greater or
    //equal than the rightOp object with the help of the strcmp C Standard library inbuilt
    //function.
    //*************************************************************************************
    bool operator >= (const MyString leftOp, const MyString rightOp)
    {
        if(strcmp(leftOp.str, rightOp.str)>=0)
            return true;
        else
            return false;
    }

    //*************************************************************************************
    //This is the overloaded "==" operator. It assesses if the leftOp object is equal to
    //the rightOp object with the help of the strcmp C Standard library inbuilt function.
    //*************************************************************************************
    bool operator == (const MyString leftOp, const MyString rightOp)
    {
        if(strcmp(leftOp.str, rightOp.str)==0)
            return true;
        else
            return false;
    }

    //*************************************************************************************
    //This is the overloaded "!=" operator. It assesses if the leftOp object is different
    //than the rightOp object with the help of the strcmp C Standard library inbuilt
    //function.
    //*************************************************************************************
    bool operator != (const MyString leftOp, const MyString rightOp)
    {
        if(strcmp(leftOp.str, rightOp.str)!=0)
            return true;
        else
            return false;
    }

    //*************************************************************************************
    //This is the overloaded insertion operator. It allows us to take data from the istream
    //and process it. getline() is called as we copy data of "MAX_INPUT_SIZE" size into a
    // temporary array "temp" until a whitespace is encountered.
    //The function further accommodates for carriage return or newline characters if those
    //are added at the very end of the array.
    //The memory space of "readMe.str" is deleted, new memory is allocated for it to specs
    //and the data stored in temp is then copied in "readMe.str".
    //*************************************************************************************
    std::istream& operator >> (std::istream& in, MyString& readMe)
    {
        char temp[MyString::MAX_INPUT_SIZE+1];
        while (isspace(in.peek())){ //needed to ignore leading whitespaces
            in.ignore();
        }
        in.getline(temp, MyString::MAX_INPUT_SIZE, (' ')); //read input of characters store in temp

        int count = 0;
        int i =0;
        while(temp[i] != '\0'){
            count++;
            i++;
        }
        if (temp[count-1]=='\n'){
            temp[count-1]='\0';
            if(temp[count-2]=='\r'){
                temp[count-2]='\0';
            }
        }
        delete [] readMe.str; //delete memory space
        readMe.str = new char[strlen(temp)+1]; //create new memory space
        strcpy(readMe.str, temp); //swap from temp to readMe.str
        return in;
    }

    //*************************************************************************************
    //This function receives an istream(by reference) and a character(by value, as a
    //delimiter) as parameters. It then uses getline parse through the istream for the
    //length and until the delimiter is encountered and stores that in a temp char array
    //"temp" of predetermined "MAX_INPUT_SIZE + 1" length. "str's memory space is deleted
    //new memory space is created for str of "new MAX_INPUT_SIZE + 1" size. temp's content
    //is then copied in "str".
    //*************************************************************************************
    void cs_mystring::MyString::readline(std::istream& in, char delim)
    {
        char temp[MyString::MAX_INPUT_SIZE + 1];
        int len = MyString::MAX_INPUT_SIZE + 1;
        in.getline( temp, len, delim);
        delete [] str;
        str = new char[strlen(temp) + 1];
        strcpy(str, temp);
    }

    //*************************************************************************************
    //This is the "+" overloaded operator. It determines the new size of the concatenated
    //objects. A "temp" temporary object is created. "temp.str"'s memory space is deleted
    //and new memory space is created for "temp.str" of "leftOp.length() + rightOp.length()
    //+ 1" size. Using strcat() C standard library inbuilt function, the content of
    //"leftOp.str" is copied in temp and then the content of "rightOp.str" is added on
    //to that as well. Temp is returned.
    //*************************************************************************************
    MyString operator + (const MyString& leftOp, const MyString& rightOp)
    {
        int size = leftOp.length() + rightOp.length() + 1;
        cs_mystring::MyString temp;
        delete [] temp.str;
        temp.str = new char[size];
        strcat(temp.str, leftOp.str);
        strcat(temp.str, rightOp.str);
        return temp;
    }

    //*************************************************************************************
    //This is the "+=" overloaded operator. It determines the new size of the concatenated
    //objects(self and rightOp). A "temp" temporary object is created. "temp.str"'s memory
    //space is deleted and new memory space is created for "temp.str" of "length() +
    //rightOp.length()+ 1" size. Using strcat() C standard library inbuilt function, the
    //content of "this->str" is copied in temp and then the content of "rightOp.str" is
    //added onto that as well. Temp is returned
    //*************************************************************************************
    cs_mystring::MyString cs_mystring::MyString::operator += (const cs_mystring::MyString& rightOp)
    {
        int size = cs_mystring::MyString::length() + rightOp.length() + 1;
        cs_mystring::MyString temp;
        delete [] temp.str;
        temp.str= new char[size];
        strcat(temp.str, this->str);
        strcat(temp.str, rightOp.str);
        return temp;
    }
}
