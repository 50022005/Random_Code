//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////                                                                                                                                                             ////
/////                                                                                                                                                             ////             
/////                                                                                                                                                             ////
/////                         MUHAMMAD HASHIM RAHIM   Q3   OOP    ASSIGNMENT 2
/////                                                                                                                                                               ////
/////                                             23i-0028                                                                                                          ////
/////                                                //                                                                                                             ////
/////                                                //                                                                                                             ////
/////                                                //                                                                                                             ////
/////                                                //                                                                                                             ////          
/////                                           ////////////                                                                                                       ////                        
/////                                            /////////                                                                                                         ////
/////                                             //////                                                                                                           ////
/////                                              ///                                                                                                             ////                                                                                                                                                             ////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////



#include "C:\Users\hp\source\repos\Project3\Project3\Header.h"

CAList::CAList() : numKeys(0) {}

CAList::CAEntry& CAList::operator[](const std::string& key) {
    for (int i = 0; i < numKeys; ++i) {
        if (entries[i].key == key) {
            return entries[i];
        }
    }

    if (numKeys < MAX_KEYS) {
        entries[numKeys] = CAEntry(key);
        return entries[numKeys++];
    }

    throw std::out_of_range("CAList is full");
}

CAList::CAEntry& CAList::operator=(const std::string& key) {
    for (int i = 0; i < numKeys; ++i) {
        if (entries[i].key == key) {
            return entries[i];
        }
    }

    if (numKeys < MAX_KEYS) {
        entries[numKeys] = CAEntry(key);
        return entries[numKeys++];
    }

    throw std::out_of_range("CAList is full");
}

void CAList::operator-=(const std::string& value) {
    for (int i = 0; i < numKeys; ++i) {
        entries[i] -= value;
    }
}

CAList CAList::operator+(const CAList& other) const {
    CAList result = *this;

    for (int i = 0; i < other.numKeys; ++i) {
        const CAEntry& entry = other.entries[i];
        for (int j = 0; j < entry.count; ++j) {
            result[entry.key] += entry.values[j];
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
        for (int i = 0; i < numKeys; ++i) {
            entries[i] = other.entries[i];
        }
    }
    return *this;
}

CAList& CAList::operator=(const std::pair<std::string, std::string>& keyValue) {
    (*this)[keyValue.first] = keyValue.second;
    return *this;
}

std::ostream& operator<<(std::ostream& os, const CAList& list) {
    os << "[ ";
    for (int i = 0; i < list.numKeys; ++i) {
        os << list.entries[i];
        if (i < list.numKeys - 1) {
            os << ", ";
        }
    }
    os << " ]";
    return os;
}