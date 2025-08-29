
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

#include <iostream>
using namespace std;

#ifndef SHOP_H


#define SHOP_H
struct Container {
    char* name;
    int containerno;
    Container* link;
};
class Shop {
public:
    Container* start;

    // Default constructor
    Shop() { start = nullptr; }

    // Copy Constructor
    Shop(const Shop& other);

    // Destructor
    ~Shop();
    
    void add_Container(const char* name, int containerindex);
    void print_Shop();
    void delete_Chain(int containerindex);
    void Sort_Chain();
    void update_name_at_containerNumber(int containerindex, const char* name);
    void remove_Duplicate();
    void findContainer(int containerindex);
    void findContainer(int containerindex1, int containerindex2);
};
#endif // !