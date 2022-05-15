// Roulette.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <windows.h>
#include <time.h>
using namespace std;





void Start()
{
    cout << "Hello Welcome to roulette! \n";
    cout << "You will have a 100 credits to start \n";
    cout << "Your goal is to reach 1000 \n";
    cout << "You can bet on a numebr up to 12 and whether it will be red or black \n";
    cout << "Good luck \n" << endl;
}

/*
  int add()
  {

  }

  int sub()
  {

  }

 */

int main()
{
    string colours[] = { "Red", "Black" };
    int i;
    int number[12] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12 };
    int Credits = 100;
    int Bet;
    Start();
    Sleep(1000);

Enterbet:
    cout << "\n";
    cout << "How much do you want to bet?\n";
    cin >> Bet;


    if (Bet > Credits)
    {
        cout << "Can't bet what you don't have";
        goto Enterbet;
    }

Entercolour:
    cout << "\n";
    cout << "What colour do you want to bet on?\n";
    cout << "0: red \n" << "1: black \n";
    cin >> i;
    cout << colours[i] << endl;
    if (i > 2)
    {
        cout << "Red or Black only\n";
        goto Entercolour;
    }

Enternumber:
    cout << "\n";
    cout << "What number do you want to bet on?\n";
    cout << "1 to 12\n";
    for (int i = 0; i < 1; ++i)
    {
        cin >> number[i];
        cout << number[i] << endl;
        if (number[i] > 13)
        {
            cout << "Only 1 to 12";
            goto Enternumber;
        }

    }

}
