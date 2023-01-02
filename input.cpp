#include <iostream>
#include"input.hpp"
using namespace std;

char input::input_c()
{
    cin >> command;
    command = tolower(command);
    set_command(command);
    return command;
}

void input::start()
{
    string n;
    cin >> n;
    set_name(n);
}
void input::set_name(string n)
{
    name = n;
}
string input::get_name() const
{
    return name;
}
void input::set_command(char c)
{
    command = c;
}
char input::get_command() const
{
    return command;
}