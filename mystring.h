//header file
//namespace cs_mystring
#ifndef MYSTRING_H
#define MYSTRING_H
#include <fstream>
namespace cs_mystring {
    class MyString {
    protected:
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
