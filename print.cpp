#include<iostream>
#include<array>
#include"print.hpp"
using namespace std;
void print::print_board(array <array <char, 5>, 5> board)
{

    system("cls || clear");
    cout << "  -------------------------------" << endl;
    for (size_t i = 0; i < 5; i++)
    {
        for (size_t j = 0; j < 5; j++)
        {
            char car = board[i][j];
            
            cout << "  |  ";
            cout << car;
            // cout << i << j;

        }
        cout << "  |  " << endl;

        cout << "  -------------------------------" << endl;    

    }

}

void print::start_game()
{
     cout << "welcome to our game" << endl
         <<  "enter your name : ";
}

void print::win()
{
    cout << "you win" << endl;
}

void print::lose()
{
    cout << "you lose" << endl;

}
