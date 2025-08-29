//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////                                                                                                                                                             ////
/////                                                                                                                                                             ////             
/////                                                                                                                                                             ////
/////                         MUHAMMAD HASHIM RAHIM   Q3   OOP    ASSIGNMENT 2
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
#include <string>
using namespace std;




#ifndef CALIST_H
#define CALIST_H



class CAList {
private:
    static const int MAX_VALUES = 6;
    static const int MAX_KEYS = 7;

    struct CAEntry {
        std::string key;
        std::string values[MAX_VALUES];
        int count;

        CAEntry() : key(""), count(0) {}
        CAEntry(const std::string& k) : key(k), count(0) {}

        CAEntry& operator+=(const std::string& value) {
            if (count < MAX_VALUES) {
                values[count++] = value;
            }
            return *this;
        }

        CAEntry& operator=(const std::string& value) {
            if (count < MAX_VALUES) {
                values[count++] = value;
            }
            return *this;
        }

        CAEntry& operator-=(const std::string& value) {
            for (int i = 0; i < count; ++i) {
                if (values[i] == value) {
                    for (int j = i; j < count - 1; ++j) {
                        values[j] = values[j + 1];
                    }
                    count--;
                    break;
                }
            }
            return *this;
        }

        friend std::ostream& operator<<(std::ostream& os, const CAEntry& entry) {
            os << entry.key << " : { ";
            for (int i = 0; i < entry.count; ++i) {
                os << entry.values[i];
                if (i < entry.count - 1) {
                    os << ", ";
                }
            }
            os << " }";
            return os;
        }
    };

    CAEntry entries[MAX_KEYS];
    int numKeys;

public:
    CAList();

    CAEntry& operator[](const std::string& key);
    CAEntry& operator=(const std::string& key);
    void operator-=(const std::string& value);
    CAList operator+(const CAList& other) const;
    CAList operator-(const CAList& other) const;
    CAList& operator=(const CAList& other);
    CAList& operator=(const std::pair<std::string, std::string>& keyValue);

    friend std::ostream& operator<<(std::ostream& os, const CAList& list);
};
 
#endif // CAList
