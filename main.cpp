/*COMSC 210 | Lawrence Bryant | Lab 11
IDE used: VSC*/
#include <iostream>
using namespace std;

struct Customers 
{
    bool member;
    string item;
    double paid;
    int* phone;
    string name;

    ~Customers()
    {
        if(phone)
        {
            delete[] phone;
        }
        phone = nullptr;
    }
};

int main()
{


    return 0;
}