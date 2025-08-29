
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////                                                                                                                                                             ////
/////                                                                                                                                                             ////             
/////                                                                                                                                                             ////
/////                         MUHAMMAD HASHIM RAHIM   Q1   OOP    ASSIGNMENT 2
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


#include"C:\Users\hp\source\repos\OOP_A2\OOP_A2\23i-0028_G_Q1.h"
//#include<iostream>


            // Copy Constructor
            Shop::Shop(const Shop& other) {
                start = nullptr;
                Container* temp = other.start;
                while (temp != nullptr) {
                    add_Container(temp->name, temp->containerno);
                    temp = temp->link;
                }
            }



                    void Shop::add_Container(const char* name, int containerindex) {
                        int len = 0;
                        const char* temp = name;
                        while (*temp++ != '\0') len++;

                        Container* newContainer = new Container;
                        newContainer->name = new char[len + 1];

                        char* newContainerName = newContainer->name;
                        while (*name != '\0') {
                            *newContainerName++ = *name++;
                        }
                        *newContainerName = '\0';

                        newContainer->containerno = containerindex;
                        newContainer->link = nullptr;

                        if (start == nullptr) {
                            start = newContainer;
                        }
                        else {
                            Container* current = start;
                            while (current->link != nullptr) {
                                current = current->link;
                            }
                            current->link = newContainer;
                        }
                    }

                    void Shop::print_Shop() {
                        Container* current = start;
                        while (current != nullptr) {
                            cout << current->name << "-" << current->containerno << endl;
                            current = current->link;
                        }
                    }

                    void Shop::delete_Chain(int containerindex) {
                        Container* current = start;
                        Container* prev = nullptr;

                        if (current != nullptr && current->containerno == containerindex) {
                            start = current->link;
                            delete[] current->name;
                            delete current;
                            return;
                        }

   
    while (current != nullptr && current->containerno != containerindex) {
        prev = current;
        current = current->link;
    }

    
    if (current == nullptr) {
        cout << "Container with index " << containerindex << " not found." << endl;
        return;
    }

    
    prev->link = current->link;
    delete[] current->name;
    delete current;
}

            void Shop::Sort_Chain() {
               
                bool swapped;
                Container* ptr1;
                Container* lptr = nullptr;

                if (start == nullptr) {
                    return;
                }

                do {
                    swapped = false;
                    ptr1 = start;

                    while (ptr1->link != lptr) {
                        if (ptr1->containerno > ptr1->link->containerno) {
                            

                            int temp = ptr1->containerno;
                            ptr1->containerno = ptr1->link->containerno;
                            ptr1->link->containerno = temp;

                            char* tempName = ptr1->name;
                            ptr1->name = ptr1->link->name;
                            ptr1->link->name = tempName;

                            swapped = true;
                        }
                        ptr1 = ptr1->link;
                    }
                    lptr = ptr1;
                } while (swapped);
            }
void Shop::findContainer(int containerindex) {
    Container* current = start;
    while (current != nullptr) {
        if (current->containerno == containerindex) {
            cout << current->name << endl;
            return;
        }
        current = current->link;
    }
    cout << "";
}

void Shop::findContainer(int containerindex1, int containerindex2) {
    Container* current = start;
    while (current != nullptr) {
        if (current->containerno >= containerindex1 && current->containerno <= containerindex2) {
            cout << current->name << endl;
        }
        current = current->link;
    }
}
                void Shop::update_name_at_containerNumber(int containerindex, const char* name) {
                    Container* current = start;
                    while (current != nullptr) {
                        if (current->containerno == containerindex) {
                            delete[] current->name;

                            int len = 0;
                            const char* temp = name;
                            while (*temp++ != '\0') len++;

                            current->name = new char[len + 1];

                            char* newName = current->name;
                            while (*name != '\0') {
                                *newName++ = *name++;
                            }
                            *newName = '\0';

                            return;
                        }
                        current = current->link;
                    }
                    cout << "Container with index " << containerindex << " not found." << endl;
                }

void Shop::remove_Duplicate() {
Container* current = start, * index = nullptr, * temp = nullptr;

while (current != nullptr && current->link != nullptr) {
    index = current;
    while (index->link != nullptr) {
        if (current->containerno == index->link->containerno) {
            temp = index->link;
            index->link = index->link->link;
            delete[] temp->name;
            delete temp;
        }
        else {
            index = index->link;
        }
    }
    current = current->link;
}
}

// Destructor
Shop::~Shop() {
Container* current = start;
while (current != nullptr) {
Container* next = current->link;
delete[] current->name;
delete current;
current = next;
}
}