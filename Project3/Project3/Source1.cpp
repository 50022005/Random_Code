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


//#include<iostream>
//#include<string>
//using namespace std;
#include"C:\Users\hp\source\repos\Project3\Project3\Header.h"
#include"C:\Users\hp\source\repos\Project3\Project3\Source.cpp"







int main() {
    CAList tt, tt2, tt3, tt4;

    tt["OOP"] = "Dr.Ali";
    tt["OOP"] = "Mr.Shehryar";
    tt["OOP"] = "Ms.Hida";
    tt["OOP"] = "Mr.Shams";
    tt["DLD"] = "Mr.Amir";
    tt["DLD"] = "Mr.Shams";
    tt["DLD"] = "Dr.Mehwish";

    cout << tt << endl;

    tt2["Algo"] = "Mr.Owais";
    tt2["OOP"] = "Mr.Shehryar";
    tt2["Pak Stds"] = "Mr.Ajmal";
    tt2["Pak Stds"] += "Ms.Gul";
    tt2["Pak Stds"] = "Ms.Memoona";
    tt2["Islamiat"] = "Dr.Tayab";
    tt2["Islamiat"] += "Ms.Sobia";
    tt2["Islamiat"] = "Mr.Usman";
    tt2["Islamiat"] += "Ms.Gul";
    tt2["Islamiat"] += "Mr.Anas";

    cout << tt2 << endl;

    tt3 = tt + tt2;
    cout << tt3 << endl;

    tt4 = tt - tt2;
    cout << tt4 << endl;

    tt["Math"] = "Dr.John";
    cout << tt << endl;

    return 0;
}