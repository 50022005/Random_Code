#include<iostream>
using namespace std;

////class AEmployee {
////	virtual void AskForPromotion()=0;
////};
////
////
////class Employee:AEmployee {
////protected:
////	string names;
////	string Company;
////	int age;
////public:#include <iostream>
using namespace std;
class A
{
public:
    void  print()
    {
        cout << "A" << endl;
    }
};
class B :virtual public A
{
public:
    void print()
    {
        cout << "B" << endl;
    }

};
class C :virtual public A
{
public:

};
class D :virtual public A
{
public:

};
class E : public B, public C, public D
{
public:


};
int main()
{
    E d;
    d.print();
}
//output?
////	static int count;
////	void setnames(string name) {
////		this->names = name;
////	}
////	string getname() {
////		return this->names;
////	}
////	void setCompany(string comp)
////	{
////		this->Company = comp;
////
////	}
////	string getCompany() {
////		return this->Company;
////	}
////	void setage(int a) {
////		this->age = a;
////
////	}
////	int getage() {
////		return this->age;
////	}
////	Employee(string a="nn", string b="dd", int age=12) {
////		this->names = a;
////		this->Company = b;
////		this->age = age;
////		count++;
////		cout << "\nEmployee Number " << count << "Created" << endl;
////		
////	}
////	void introduce() {
////		cout << "\nName  :" << this->names;
////		cout << "\nCompany  :" << this->Company;
////		cout << "\nAge   :" << this->age;
////		cout << "\nCount  :" << count;
////	}
////
////	~Employee() {
////		cout << "\nDestroyed Employee Number :" << count;
////		count--;
////
////	}
////	void AskForPromotion() {
////		if (age > 30)
////		{
////			this->introduce();
////			cout << "\nCongrats on your Promotion" << endl;
////		}
////		else
////		{
////			this->introduce();
////			cout << "\nPromotion Rejected" << endl;
////
////		}
////	}
////	virtual void Work() {
////		cout<<"\n" << names << " is checking Email and so on...." << endl;
////	}
////};
////int Employee::count = 0;
////
////class Dev:public Employee {
////	string Favlang;
////public:
////	Dev(string name, string Company, int age, string lang="C++") :Employee(name, Company, age)
////	{
////		
////		this->Favlang = lang;
////		cout << "Dev created " << endl;
////	}
////	void setFavlang(string f) {
////		this->Favlang = f;
////	}
////		string getFavlang(){
////			return this->Favlang;
////	}
////		void introduce() {
////			Employee::introduce();
////			cout << "\nFav Language" << getFavlang() << endl;
////	}
////		void fixbug() {
////			cout <<"\n"<< getname() << "  is fixing bugs using " << getFavlang() << endl;
////	}
////		void Work(){
////			cout << "\n" << names << " is doing code work   " << endl;
////
////		}
////		~Dev() {
////			cout << "\nDestroyed Dev" <<" number "<<count<< endl;;
////		}
////};
////class Teacher :public Dev {
////public:
////	string Sub;
////	void Preparelesson() {
////		cout <<"\n" << getname() << " is preparing " << Sub << "  lesson." << endl;
////	}
////	Teacher(string name, string company, int age, string lan, string sub) :Dev(name,company,age,lan)
////	{
////		this->Sub = sub;
////		cout << "Teacher  created" << endl;;
////	}
////	void Work() {
////		cout << "\n" << names << " is Teaching " << Sub << endl;
////	}
////	~Teacher() {
////		cout << "\nTeacher " << names << " is destroyed" << endl;
////
////		cout << count;
////	}
////};
//
//class Youtubechannel {
//
//	string name;
//	int Subcount;
//public:
//	Youtubechannel(string name,int subc)
//	{
//		this->name = name;
//		this->Subcount = subc;
//
//	}
//	friend ostream& operator<<(ostream& out, Youtubechannel& yt);
//	friend istream& operator>>(istream& in, Youtubechannel& yt);
//};
//ostream& operator<<(ostream& out, Youtubechannel& yt) {
//	out << "\n Name :" << yt.name << endl;
//	out << " \nSubscribers  :" << yt.Subcount << endl;
//	return out;
//}
//istream& operator>>(istream& in, Youtubechannel& yt) {
//	cout << "\nenter Name :";
//	string a;
//	int b;
//	in >> a;
//		yt.name = a;
//
//		cout << " \nSubscribers count :";
//		in >> b;
//		yt.Subcount = b;
//	return in;
//}
//int main() {
//	///*if (1)
//	//{
//	//	Employee emp1, emp2("ha", "gooo", 19);
//	//	emp1.introduce();
//	//	emp2.introduce();
//	//}
//	//Employee emp("arham"),emp1("ja","sd",40);
//	//emp.introduce();
//	//emp.AskForPromotion();
//	//emp1.AskForPromotion();*/
//	//Dev d("hashim", "google", 40, "C++");
//	////d.AskForPromotion();
//	//Teacher t("Jack", "scool", 45, "python", "Cs");
//	////t.Preparelesson();
//	////t.AskForPromotion();
//	////d.Work();
//	////t.Work();
//	//Employee* e1 = &d;
//	//Dev* e2 = &t;
//	//e1->Work();
//	//e2->Work();
//
//
//	Youtubechannel y1("hashim", 65443);
//	cout << y1;
//	cin >> y1;
//	cout << y1;
//
//}