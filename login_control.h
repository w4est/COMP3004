#ifndef LOGIN_CONTROL_H
#define LOGIN_CONTROL_H
#include <string>
#include <fstream>
#include <streambuf>
#include <stdio.h>
#include <iostream>

class Login_Control
{
public:
    Login_Control(std::string);
    ~Login_Control();

    bool validUsername(std::string _name);
    bool registerTempUsername(std::string _name);
    void registerUsername(std::string _name);
    void unregisterTempUsername(std::string _name);

private:
    std::string temp_PostSig;

    std::ifstream ifile;
};

#endif // LOGIN_CONTROL_H
