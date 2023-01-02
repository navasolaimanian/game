#include "game.hpp"
#include <cstdlib>
#include <iostream>
#include<random>
#include<fstream>
#include"input.hpp"
#include"print.hpp"
using namespace std;

array <std::array <char, 5>, 5> Game::initBoard()
{
    for (size_t i = 0; i < 5; i++)
    {
        for (size_t j = 0; j < 5; j++)
        {
            string code = to_string(i) + to_string(j);
            
            for (auto item : cell)
            {
                if(code == item)
                {
                    board[i][j] = 'x';
                    break;
                }
                else
                {
                    board[i][j] = ' ';
                }
            }
        }
    }
    board[0][0] = 'b';    
    board[4][4] = 'a';    
    return board;
}

int Game::play()
{
    input in;
    print p;
    p.start_game();
    in.start();
    p.print_board(initBoard());
    while(!isWin())
    {
        board = logic(in.input_c());
        p.print_board(board);
        if(!decrease_score())
        {
            p.lose();
            exit(0); 
        }

    }
    if(isWin())
    {
        p.print_board(board);
        p.win();
        file(in.get_name());
    }
    return 0;
}

bool Game::isWin()
{
    for (size_t i = 0; i < 5; i++)      // Row traversal 
    {
        for (size_t j = 0; j < 5; j++)      // Column traversal
        {
            if(board[i][j] == 'a')
            {
                board[1][0] = ' ';    
                return true;

            }
            else
            {
                return false;
            }
        }
    }

    return true;
}

std::array <std::array <char, 5>, 5> Game::logic(char command)
{
    Position index = findindex();
   
    if(command == 's' && board[index.x + 1][index.y] != 'x' &&  index.x + 1 < 5)
    {
        swap(board[index.x][index.y], board[index.x + 1][index.y]);
    }
    if(command == 'w' && board[index.x - 1][index.y] != 'x' && index.x - 1 >= 0)
    {
        swap(board[index.x][index.y], board[index.x - 1][index.y]);
    }
    else if(command == 'a' && board[index.x][index.y - 1] != 'x' && index.y - 1 >= 0)
    {
        swap(board[index.x][index.y], board[index.x][index.y - 1]);
    }
    else if(command == 'd' && board[index.x][index.y + 1] != 'x' && index.y + 1 < 5)
    {
        swap(board[index.x][index.y], board[index.x][index.y + 1]);
    }
    
    return board;
}

Game::Position Game::findindex()
{
    Position index;

    for (size_t i = 0; i < 5; i++)      // Row traversal 
    {
        for (size_t j = 0; j < 5; j++)      // Column traversal
        {
            if(board.at(i).at(j) == 'a')
            {
                index.x = i;
                index.y = j;
                return index;
            }
        }
    }

    return index;
}    

bool Game::decrease_score(){
    if(score >= 0)
    {
        score--;
        return true;
    }
    else
    {
        return false;
    }
}

void Game::file(string name){
    fstream f;
    f.open("file.txt", ios::app);
    if(!f)
    {
        // cout << "error";
    }

    f <<  "name: " << name << "    score: " << score << endl;
}

