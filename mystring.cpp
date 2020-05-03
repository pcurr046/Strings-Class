//implementation file
#include "mystring.h"
#include <cstring>
#include <string.h>
#include <cassert>
#include <iostream>
#include <fstream>
using namespace std;

namespace cs_mystring{
    int MyString::length() const//use strlen???
    {
        int length = strlen(this->str);
        return length;
    }
    MyString::MyString()  // default constructor
    {
        str = new char[1];
        strcpy(str, "");
    }
    MyString::MyString(const char* inString) // parameterized constructor --> use strcopy
    {
        int size = strlen(inString) + 1;
        str = new char[size];
        strcpy(str, inString);
    }
    MyString::~MyString()  // class destructor
    {
        if(str!=nullptr)
            delete [] str;
    }
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
    MyString::MyString(const MyString& copyMe)  //copy constructor makes a deep copy
    {
        int size = copyMe.length();
        str = new char [size+1];
        strcpy(str, copyMe.str);
    }
    std::ostream& operator << (std::ostream &out, const MyString& printMe)
    {
        out << printMe.str;
        return out;
    }
    char MyString::operator[] (int index) const
    {
        assert(index >= 0 && index < strlen(str));
        return str[index];
    }
    char& MyString::operator [] (int index)
    {
        assert(index >= 0 && index < strlen(str));
        return str[index];
    }
    bool operator < (const MyString leftOp, const MyString rightOp)
    {
        if(strcmp(leftOp.str, rightOp.str)<0)
            return true;
        else
            return false;
    }
    bool operator <= (const MyString leftOp, const MyString rightOp)
    {
        if(strcmp(leftOp.str, rightOp.str)<=0)
            return true;
        else
            return false;
    }
    bool operator > (const MyString leftOp, const MyString rightOp)
    {
        if(strcmp(leftOp.str, rightOp.str)>0)
            return true;
        else
            return false;
    }
    bool operator >= (const MyString leftOp, const MyString rightOp)
    {
        if(strcmp(leftOp.str, rightOp.str)>=0)
            return true;
        else
            return false;
    }
    bool operator == (const MyString leftOp, const MyString rightOp)
    {
        if(strcmp(leftOp.str, rightOp.str)==0)
            return true;
        else
            return false;
    }
    bool operator != (const MyString leftOp, const MyString rightOp)
    {
        if(strcmp(leftOp.str, rightOp.str)!=0)
            return true;
        else
            return false;
    }
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
           // cout << "Temp[" << i << "]" << temp[i];
            i++;
        }
        //cout << endl;
       // cout << "Length is " << count << endl;
        if (temp[count-1]=='\n'){
            temp[count-1]='\0';
            if(temp[count-2]=='\r'){
                temp[count-2]='\0';
            }
        }
        delete [] readMe.str; //delete memory space
        readMe.str = new char[strlen(temp)+1]; //create new memory space
        strcpy(readMe.str, temp); //swap from temp to target.description
        return in;
    }

    void cs_mystring::MyString::readline(std::istream& in, char delim)
    {
        char temp[MyString::MAX_INPUT_SIZE + 1];
        int len = MyString::MAX_INPUT_SIZE + 1;
        in.getline( temp, len, delim);
        delete [] str;
        str = new char[strlen(temp) + 1];
        strcpy(str, temp);
    }
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
