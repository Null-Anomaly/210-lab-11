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

void enterCustomer(Customers *);
void displayCustomer();

int main()
{
    //The randomness for however many people come into a store
    srand (time(NULL));
    const int folks = rand() % 5 + 1;

    Customers *list = new Customers[folks];

    for(int i = 0; i < folks; i++)
    {
        enterCustomer(&list[i]);
    }

    return 0;
}

void enterCustomer(Customers *person)
{
    //For entering how much money they paid
    cout << "How much did they spend at gamestop?: ";
    cin >> person->paid;

    //The porition of code for determining membership
    string check = " ";
    cout << "Is this gamestop customer a member? (Enter y or n): ";
    cin >> check;
    if(check == "y")
    {
        person->member = true;
    }
    else if(check == "n")
    {
        person->member = false;
    }
    else
    {
        while(check != "y" && check != "n")
        {
            cout << "Please select y or n: ";
            cin >> check;
        }
        if(check == "y")
        {
        person->member = true;
        }
        if(check == "n")
        {
        person->member = false;
        }
    }
    
    //From here, it will auto-fill if it's false and manual fill if true
    if(person->member == false)
    {

    }
    else
    {
        
    }
}