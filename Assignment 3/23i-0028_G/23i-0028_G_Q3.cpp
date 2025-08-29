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






#include "C:\Users\hp\OneDrive\Desktop\23i-0028_G\23i-0028_G_Q3.h"
#include <iostream>
using namespace std;


CAList::CAList() : numKeys(0) {}

CAList::CAEntry& CAList::operator[](const string& key) {
    for (int i = 0; i < numKeys; ++i) {
        if (entries[i].key == key) {
            return entries[i];
        }
    }

    if (numKeys < MAX_KEYS) {
        entries[numKeys] = CAEntry(key);
        return entries[numKeys++];
    }

    cout << ("CAList is full\n");
    return entries[0];
}


void CAList::operator-=(const string& value) {

        for (int i = 0; i < numKeys; ++i) {
            entries[i] -= value;
        }
    
}

                    CAList CAList::operator+(const CAList& other) const {
                        CAList result = *this; 

                        for (int i = 0; i < other.numKeys; ++i) {
                            const CAEntry& otherEntry = other.entries[i];
                            CAEntry& resultEntry = result[otherEntry.key];

                            for (int j = 0; j < otherEntry.count; ++j) {
                               
                                bool valueExists = false;
                                for (int k = 0; k < resultEntry.count; ++k) {
                                    if (resultEntry.values[k] == otherEntry.values[j]) {
                                        valueExists = true;
                                        break;
                                    }
                                }
                               
                                if (!valueExists && resultEntry.count < MAX_VALUES) {
                                    resultEntry.values[resultEntry.count++] = otherEntry.values[j];
                                }
                            }
                        }

                        return result;
}


CAList CAList::operator-(const CAList& other) const {
    CAList result = *this;

    for (int i = 0; i < other.numKeys; ++i) {
        const CAEntry& entry = other.entries[i];
        for (int j = 0; j < entry.count; ++j) {
            result -= entry.values[j];
        }
    }

    return result;
}

CAList& CAList::operator=(const CAList& other) {
    if (this != &other) {
        numKeys = other.numKeys;
        for (int i = 0; i < MAX_KEYS; ++i) {
            if (i < other.numKeys) {
                entries[i] = other.entries[i];
            }
            else {
                entries[i] = CAEntry(); 
            }
        }
    }
    return *this;
}

                

                 ostream& operator<<( ostream& os, const CAList& list) {
                    os << "[ ";
                    for (int i = 0; i < list.numKeys; ++i) {
                        os << list.entries[i];
                        if (i < list.numKeys - 1) {
                            os << "\n ";
                        }
                    }
                    os << " ]" << endl;
                    return os;
                }
