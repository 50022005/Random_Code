
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





#include "C:\Users\hp\source\repos\OOP_A2\OOP_A2\23i-0028_G_Q2.h"
//#include <iostream>




// Default constructor
String::String() : data(nullptr), size(0) {
}

            // Constructor with const char*
            String::String(const char* str) {
                int size = 0;
                while (str[size] != '\0') {
                    ++size;
                }
                this->size = size;
                if (this->size != 0) {


                    this->data = new char[size + 1];
                    for (int i = 0; i < size; ++i) {
                        this->data[i] = str[i];
                    }
                    this->data[size] = '\0';
                }
                else
                    this->data = 0;

            }

            // Copy constructor
            String::String(const String& const copy) {
                this->size = copy.size;
                if (this->size != 0) {
                    this->data = new char[size + 1];
                    for (int i = 0; i < size; ++i) {
                        this->data[i] = copy.data[i];
                    }
                    this->data[this->size] = '\0';
                }
                else
                    this->data = nullptr;
            }

            // Constructor with predefined size
            String::String(int x) {
                this->size = x;
                this->data = new char[this->size+1];
                for (int i = 0; i < size; ++i) {
                    this->data[i] = '\0';
                }
                this->data[this->size] ='\0';
            }

            // Destructor
            String::~String() {
                if (data != nullptr) {
                    delete[] this->data;
                }
            }

            // Get data function
            char* String::getdata() const {
                return this->data;
            }

            int String::length(const char* ptr)
            {
                int i = 0;
                while (*ptr != '\0')
                {
                    i++;
                    ptr++;
                }
                return ++i;
            }

            // Sub-script Operator
            const char String::operator[](int i) const {
                if (i < 0) {
                    i = size + i;
                }

                if (i < 0 || i >= size) {
                    return '\0';
                }

                return this->data[i];
            }

//// Arithmetic Operators
String String::operator+(const String& str)  {
    int newLength = size + str.size;
    char* newData = new char[newLength + 1];
    int i = 0;
    for (; i < size; ++i) {
        newData[i] = data[i];
    }

    for (int j = 0; j < str.size; ++j, ++i) {
        newData[i] = str.data[j];
    }

    newData[newLength] = '\0';

    String result(newData);
    delete[] newData;
    this->data = result.data;
    this->size = result.size;
    return *this;
}

    String String::operator+(const char& ch)  {
        int newLength = size + 1;
        char* newData = new char[newLength + 1];

        int i = 0;
        for (; i < size; ++i) {
            newData[i] = data[i];
        }

        newData[i] = ch;
        ++i;
        newData[i] = '\0';

        String result(newData);
        delete[] newData;
        this->data = result.data;
        this->size = result.size;
        return *this;
    }

    String String::operator+(const char* str)  {
        int strLen = 0;
        while (str[strLen] != '\0') {
            ++strLen;
        }

        int newLength = size + strLen;
        char* newData = new char[newLength + 1];

        int i = 0;
        for (; i < size; ++i) {
            newData[i] = data[i];
        }

        for (int j = 0; j < strLen; ++j, ++i) {
            newData[i] = str[j];
        }

        newData[newLength] = '\0';
        String result(newData);
        delete[] newData;
        this->data = result.data;
        this->size = result.size;
        return *this;
    }

                    String String::operator-(const String& substr) {
                        char* newData = new char[this->size + 1];
                        int newSize = 0;
                        int i = 0;
                        while (this->data[i] != '\0') {
                            bool match = true;
                            for (int j = 0; substr.data[j] != '\0' && match; j++) {
                                if (this->data[i + j] != substr.data[j]) {
                                    match = false;
                                }
                            }
                            if (match) {
                                i += strlen(substr.data);
                            }
                            else {
                                newData[newSize++] = this->data[i++];
                            }
                        }
                        newData[newSize] = '\0';
                        String newString;
                        this->data = newData;
                        this->size = newSize;
                        return *this;
                    }


                    String String::operator-(const char& c) {
                        char* newData = new char[this->size + 1];
                        int newSize = 0;
                        for (int i = 0; i < this->size; i++) {
                            if (this->data[i] != c) {
                                newData[newSize++] = this->data[i];
                            }
                        }
                        newData[newSize] = '\0';
                        String newString;
                        this->data = newData;
                        this->size = newSize;
                        return *this;

                    }


                    String String::operator-(const char* str) {
                        char* newData = new char[this->size + 1];
                        int newSize = 0;
                        int i = 0;
                        while (this->data[i] != '\0') {
                            bool match = true;
                            for (int j = 0; str[j] != '\0' && match; j++) {
                                if (this->data[i + j] != str[j]) {
                                    match = false;
                                }
                            }
                            if (match) {
                                i += strlen(str);
                            }
                            else {
                                newData[newSize++] = this->data[i++];
                            }
                        }
                        newData[newSize] = '\0';
                        String newString;
                        this->data = newData;
                        this->size = newSize;
                        return *this;
                    }
// Assignment Operators
String& String::operator=(const String& other) {
    if (this != &other) {
        if (data != nullptr) {
            delete[] data;
        }

        size = other.size;
        data = new char[size + 1];
        for (int i = 0; i < size; ++i) {
                data[i] = other.data[i];
        }
        data[size] = '\0';
    }
    return *this;
}

                String& String::operator=(const char* str) {
                    if (data != nullptr) {
                        delete[] data;
                    }

                    size = 0;
                    while (str[size] != '\0') {
                        ++size;
                    }

                    data = new char[size + 1];
                    for (int i = 0; i < size; ++i) {
                        data[i] = str[i];
                    }
                    data[size] = '\0';

                    return *this;
                }

            // Logical Operators
            bool String::operator==(const String& other) const {
                if (size != other.size) {
                    return false;
                }

                for (int i = 0; i < size; ++i) {
                    if (data[i] != other.data[i]) {
                        return false;
                    }
                }

                return true;
            }

bool String::operator==(const char* str) const {
int i = 0;
while (str[i] != '\0') {
    if (data[i] != str[i]) {
        return false;
    }
    ++i;
}

return (size == i);
}

// Unary Operators
bool String::operator!() const {
return (this->size == 0 || this->data[0]=='\0');
}

// Function-Call Operators
int String::operator()(char ch) const {
    for (int i = 0; i < size; ++i) {
        if (data[i] == ch) {
            return i;
        }
    }

    return -1;
}

int String::operator()(const String& str) const {
    for (int i = 0; i < size - str.size + 1; ++i) {
        int j;
        for (j = 0; j < str.size; ++j) {
            if (data[i + j] != str.data[j]) {
                break;
            }
        }
        if (j == str.size) {
            return i;
        }
    }

    return -1;
}

int String::operator()(const char* str) const {
    int strLen = 0;
    while (str[strLen] != '\0') {
        ++strLen;
    }

    for (int i = 0; i < size - strLen + 1; ++i) {
        int j;
        for (j = 0; j < strLen; ++j) {
            if (data[i + j] != str[j]) {
                break;
            }
        }
        if (j == strLen) {
            return i;
        }
    }

    return -1;
}

// Conversion Operator
String::operator int() const {
    if (this->data[0] == '\0')
        return 0;
    return size;
}

// Friend functions for Input/Output
std::ostream& operator<<(std::ostream& output, const String& str) {
    output << str.data;
    return output;
}

std::istream& operator>>(std::istream& input, String& str) {
    char buffer[5000];
    input >> buffer;
    str = buffer;
    return input;
}

