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

class roulette
{
public:
    int number, Pnumber;
    string colour, Pcolour;
    void printroulette()
    {
        cout << "Player guess\n";
        cout << Pcolour << endl;
        cout << Pnumber << endl;

        cout << "Wheel total\n";
        cout << colour << endl;
        cout << number << endl;
    }
};
roulette output[24], temp;

void printnumber()
{
    int i;
    for (i = 0; i < 1; i++)
    {
        output[i].printroulette();
    }
}


void spin()
{
    srand(time(NULL));
    int i, x;
    for (i = 0; i < 1; i++)
    {
        x = rand() % 24;
        temp = output[i];
        output[i] = output[x];
        output[x] = temp;
    }
}

int Add(int a, int b)
{
    return (a + b);
}

int Sub(int a, int b)
{
    return (a - b);
}

int main()
{
   
    Start();
    Sleep(1000);

    string colour[] = { "Red", "Black" };
    int number[13] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12 };

    int Bet, i, o;


    int Credits = 100;
    int total;

    total = Credits;
placebet:
    cout << "How much would you like to bet?\n";
    cin >> Bet;

    if (Bet > Credits)
    {
        cout << "Can't bet what you don't have\n";
    }

    cout << "what colour do you bet on?\n";
    cout << "0:Red\n" << "1:Black\n";
    cin >> i;

    cout << "What number do you want to bet on?\n";
    cin >> o;


    int x, y, z{};
    for (x = 0; x < 2; x++)
    {
        for (y = 0; y < 12; y++)
        {
            output[z].Pcolour = colour[i];
            output[z].Pnumber = number[o];
            output[z].colour = colour[x];
            output[z].number = number[y];
            z++;
        }
    }
    spin();
    printnumber();
    if (x == i || y == o)
    {
        total = Add(Credits, Bet);
        cout << total << " " << "Credits\n";

    }
    else
    {
        total = Sub(Credits, Bet);
        cout << total << " " << "Credits\n";

    }

}
