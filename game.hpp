#ifndef GAME_H
#define GAME_H
#include<iostream>
#include <array>
class Game{
    public:
        std::array <std::array <char, 5>, 5> initBoard(); //initializing 2D array with ' ' and x
        int play();// loop of game
        bool isWin();//check that if player wins or not
        std::array <std::array <char, 5>, 5> logic(char);//changing place og player
        bool decrease_score();//decrease score of user if go to x and for every movment
        void file(std::string);//storing name and score of player in file

    private:
        std::array <std::array <char, 5>, 5> board;//2D array for game
        std::array <std::string, 6 > cell = {"01", "13", "21", "34", "40", "42"};//places that player can not go to (x)
        struct Position{int x; int y;};//for maintenance place of player in 2D array
        Position findindex();//for finding place of player
        int score = 10;//score of player
};

#endif