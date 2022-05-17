// Roulette.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <windows.h>
#include <time.h>
using namespace std;


void Start() //Intro to the game
{
    cout << "Hello Welcome to roulette! \n";
    cout << "You have a 100 credits\n";
    cout << "You choose either red or black\n";
    cout << "For the colour you think it will land on\n";
    cout << "You do the same for the number 0 to 12\n";
    cout << "If you get one out of the two guesses right\n";
    cout << "Like if you guess black and its black you win\n";
    cout << "but if you guess wrong for both you lose\n";
    cout << "Good luck\n" << endl;
}

class roulettenum //credits you start with
{
public:
    int Credits = 100; // number of credits 
};
// I got help by 1000 'n' one passion https://www.youtube.com/watch?v=4bQdVyjvJig and https://www.youtube.com/watch?v=py7nc1Pjgto
class roulette // Setup for roulette
{
public:  //wheel   //Player guess
     int   number, Pnumber;
    string colour, Pcolour;
    void printwheel() // prints player guess and wheel total
    {
        cout << endl;
        cout << "Player guess\n";
        cout << Pcolour << endl;
        cout << Pnumber << endl;
        cout << endl;
        cout << "Wheel total\n";
        cout << colour << endl;
        cout << number << endl;
        cout << endl;
    }

    void printinput()
    {
        roulettenum rounum; // ref of roulettenum

        

            if (Pcolour == colour || Pnumber == number) // check if player guess and wheel total match
            {
                rounum.Credits += 25; // add 25 credits
                cout << rounum.Credits << " " << "Credits\n";
            }
            else // if not minus 25
            {
                rounum.Credits -= 25; //Takes away 25 credits
                cout << rounum.Credits << " " << "Credits\n";
            }

            if (rounum.Credits > 100) // credits more then 100 you win
            {
                cout << "You win\n" << endl;
            }
            else // below that you lose
            {
                cout << "You lose\n" << endl;
            }
        
    }
    
};

roulette output[24], temp; 
void printnumber() // outputs both the wheel and ....
{
    int i;
    for (i = 0; i < 1; i++)
    {
        output[i].printwheel();
        output[i].printinput();
    }
}



void spin() //random colour and number
{
    
    int i, x;
    for (i = 0; i < 24; i++)
    {
        srand(time(0)); // random seed
        x = rand() % 24; // how many different  possibilities
        temp = output[i]; //vaule will be moved to end
        output[i] = output[x]; //end vaule to random spot
        output[x] = temp;// vaule to ebnd the final vaule
    }
}


void game() // game output
{
    roulettenum rounum; // ref of roulettenum

    string colour[] = { "Red", "Black" }; // array of colours
    int number[13] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12 }; // array of numbers
       
    int Pc; // Player colour input 
    int Pn; // Player number input

        enetercolour:
        cout << "what colour do you bet on?\n";
        cout << "0:Red\n" << "1:Black\n";
        cin >> Pc;
        if (Pc > 1)
        {
            cout << "\n";
            cout << "You can only eneter red and black\n";
            goto enetercolour;
        }
        cout << endl;
    eneternumber:
        cout << "\n";
        cout << "What number do you want to bet on?\n";
        cin >> Pn;
        if (Pn > 12)
        {
            cout << "Can only eneter 0 to 12\n";
            
            goto eneternumber;
        }

        int x, y, z{};
        for (x = 0; x < 2; x++)
        {
            for (y = 0; y < 13; y++)
            {
                output[z].Pcolour = colour[Pc];
                output[z].Pnumber = number[Pn];
                output[z].colour = colour[x];
                output[z].number = number[y];
                z++;
            }
        }

        spin();
        printnumber();

        cout << "Want to try again?\n";
        cout << "1:Playagin\n" << "2:finish\n";
       
}

int main()
{
    int Playagain; 
    Start(); // output the intro
    Sleep(1000); // delay for 1 second
    game(); // output the game
    cin >> Playagain;

    switch (Playagain) // restarts game
    {
    case 1:
    {
        return main();
    }
    case 2:
    {
        return 0;
    }
    default:
        cout << "Can only pick these two please pick again\n";
        break;
    }
}

