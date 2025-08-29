
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////                                                                                                                                                             ////
/////                                                                                                                                                             ////             
/////                                                                                                                                                             ////
/////                         MUHAMMAD HASHIM RAHIM   Q2   OOP    ASSIGNMENT 2
/////                                                                                                                                    ////
/////                                             23i-0028                                                                                                                        ////
/////                                                //                                                                                                             ////
/////                                                //                                                                                                             ////
/////                                                //                                                                                                             ////
/////                                                //                                                                                                             ////          
/////                                           ////////////                                                                                                                 ////                        
/////                                            /////////                                                                                                                ////
/////                                             //////                                                                                                               ////
/////                                              ///                                                                                                              ////                                                                                                                                                             ////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////







#include <iostream>
using namespace std;


#ifndef STRING_H
#define STRING_H



class String {
private:
    char* data;
    int size;

public:
    String(); // default constructor
    String(const char* str); // initializes the string with constant c-string
    String(const String& other); // copy constructor
    String(int x); // initializes a string of predefined size
    ~String(); // destructor

    // Member Functions
    char* getdata() const; // returns the string inside the object
    int length(const char* ptr);
    // Sub-script Operators
    const char operator[](int i) const; // returns the character at index [x]

    // Arithmetic Operators
    String operator+(const String& str) ; // appends a String at the end of the String
    String operator+(const char& ch) ; // appends a char at the end of the String
    String operator+(const char* str) ; // appends a String at the end of the String
    String operator-(const String& substr) ; // removes the substr from the String
    String operator-(const char& ch) ; // removes all occurrences of char from the String
    String operator-(const char* str) ; // removes the str from the String

    // Assignment Operators
    String& operator=(const String& other); // copies one String to another
    String& operator=(const char* str); // copies one c-string to another

    // Logical Operators
    bool operator==(const String& other) const; // returns true if two Strings are equal
    bool operator==(const char* str) const; // returns true if the c-string is equal to the String

    // Unary Operators
    bool operator!() const; // returns true if the String is empty

    // Function-Call Operators
    int operator()(char ch) const; // returns the first index of the character being searched
    int operator()(const String& str) const; // returns the first index of the String being searched
    int operator()(const char* str) const; // returns the index of the c-string being searched

    // Conversion Operator
    operator int() const; // returns the length of string

    // Friend functions for Input/Output
    friend ostream& operator<<(ostream& output, const String& str);
    friend istream& operator>>(istream& input, String& str);
};

#endif// STRING_H 

