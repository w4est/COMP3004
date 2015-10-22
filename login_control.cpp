#include "login_control.h"

Login_Control::Login_Control()
{
    file.open("username_list.txt");
}

Login_Control::~Login_Control()
{
    file.close();
}

bool Login_Control::validUsername(std::string _name)
{
    std::string line;

    file.clear();
    file.seekg(0);

    while(getline(file, line)){
       if(_name.compare(line) == 0){
           return true;
       }
    }

    return false;
}

void Login_Control::registerUsername(std::string _name)
{

}
