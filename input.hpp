#ifndef INPUT_H
#define INPUT_H
#include<iostream>
class input{
public:
    char input_c();//geting charecter(s,w,a,d)
    void start();//geting name of player
    void set_name(std::string);//set name in privat variable name
    std::string get_name() const;//returning privat variable name
    void set_command(char);//geting command(a,s,d,w) of player
    char get_command() const;//returning command(a,s,d,w) of player
private:
    char command;
    std::string name;
    
};

#endif