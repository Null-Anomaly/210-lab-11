/*COMSC 210  | Lab 11 | Lawrence Bryant
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
    int* visits;
    string name;

    ~Customers()
    {
        if(visits)
        {
            delete[] visits;
        }
        visits = nullptr;
    }
};

void enterCustomer(Customers *,int);
void displayCustomer(Customers*);

int main()
{
    //The randomness for however many people come into a store and how often
    srand (time(NULL));
    const int folks = rand() % 3 + 1;
    const int arrive = rand() % 3 + 1;

    Customers *list = new Customers[folks];

    for(int i = 0; i < folks; i++)
    {
        enterCustomer(&list[i],arrive);
        displayCustomer(&list[i]);
    }

    return 0;
}

//Function for entry of customer data
//Takes a person object and an integer as arguments.
void enterCustomer(Customers *person,int here)
{
    //For figuring out what they bought
    cout << "What did they buy from gamestop?: ";
    cin >> person->item;

    //For entering how much money they paid
    cout << "How much did they spend on it?: ";
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
        person->name = "blank";
        person->visits = new int[here];
        for(int i = 0; i < here; i++)
        {
            person->visits[i] = 0;
        }
    }
    else
    {
        cout << "What is this member's name?: ";
        cin >> person->name;
        person->visits = new int[here];
        int check = 0;
        cout << "Please list all dates they have visited (mmddyyyy)";
        for(int i = 0; i < here; i++)
        {
            cout << "Date " << i << ": ";
            cin >> check;
            while(check < 1010000 || check > 12319999)
            {
                cout << "Please input a valid date: ";
                cin >> check;
            }
            person->visits[i] = check;
        }
    }
}

//I realize I only made this because it was in the example code
//But it makes it useful to see customer info. Takes Customer objects.
void displayCustomer(Customers *person)
{
    cout << "This customer paid " << person->paid << "$\n";
    cout << ""
}