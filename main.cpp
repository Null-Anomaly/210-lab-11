/*COMSC 210 | Lawrence Bryant | Lab 11
IDE used: VSC*/
#include <iostream>
#include <stdio.h>      
#include <stdlib.h>     
#include <time.h>  
using namespace std;

//A struct for customers coming into a store to buy games.
//Has a boolean for if they have a membership, how much they paid, etc.
//If they aren't a member, all other values will be generic/null
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

void enterCustomer();
void displayCustomer();

int main()
{
    //The randomness for however many people come into a store
    srand (time(NULL));
    const int folks = rand() % 5 + 1;

    Customers *list = new Customers[folks];

    for(int i = 0; i < folks; i++)
    {
        
    }

    return 0;
}