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
                                         string key;
                                         string values[MAX_VALUES];
                                        int count;

                                        CAEntry() : key(""), count(0) {}
                                        CAEntry(const  string& k) : key(k), count(0) {}

                                        CAEntry& operator+=(const  string& value) {
                                            if (count < MAX_VALUES) {
                                                values[count++] = value;
                                            }
                                            return *this;
                                        }

                                        CAEntry& operator=(const  string& value) {
                                           
                                            for (int i = 0; i < count; ++i) {
                                                if (values[i] == value) {
                                                    return *this; 
                                                }
                                            }
                                           
                                            if (count < MAX_VALUES) {
                                                values[count++] = value;
                                            }
                                            return *this;
                                        }


                                        CAEntry& operator-=(const  string& value) {
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

                                        friend  ostream& operator<<( ostream& os, const CAEntry& entry) {
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

                CAEntry& operator[](const  string& key);
                void operator-=(const  string& value);
                CAList operator+(const CAList& other) const;
                CAList operator-(const CAList& other) const;
                CAList& operator=(const CAList& other);

                friend  ostream& operator<<( ostream& os, const CAList& list);
            };

#endif // CALIST_H