#include<iostream>
using namespace std;







void line(int n, char a)
{
    if (n <= 0)
        return;
    cout << a;
    line(n - 1, a);

}

void RecursivePattern1(int start, int end)
{   
    if (start ==end)
        return;
    if (start < end / 2 + 1)
    {
        line(start, ' ');
        cout << "*" << endl;
        RecursivePattern1(start + 1, end);
    }
    else
    {  
        RecursivePattern1(start+1, end);
        line(start-4, ' ');
        cout << "*" << endl;
    }
    




}


void RecursivePattern2(int n1, int n2)
{

}


void RecursivePattern3(int n1, int n2)
{

}


int main() {

   
    RecursivePattern1(1, 10);
}