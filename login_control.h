#ifndef LOGIN_CONTROL_H
#define LOGIN_CONTROL_H
#include <string>
#include <fstream>
#include <streambuf>
#include <iostream>
#include <QDir>
#include "rapidxml-1.13/rapidxml.hpp"

using namespace rapidxml;
class Login_Control
{
public:
    Login_Control();
    ~Login_Control();

    bool validUsername(std::string _name);
    void registerUsername(std::string _name);

private:
    std::fstream file;
    xml_document<> doc;
};

#endif // LOGIN_CONTROL_H
