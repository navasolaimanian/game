#ifndef PRINT_H
#define PRINT_H
#include<iostream>
#include<array>
class print
{
private:

public:
    void print_board(std::array <std::array <char, 5>, 5>);//printing board of game
    void start_game();//printing welcome message
    void win();//print if player wins
    void lose();//print if player lose

};
#endif 

