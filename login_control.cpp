#include "login_control.h"

Login_Control::Login_Control(std::string file)
{
    temp_PostSig = "~~";
    ifile.open(file.c_str());
}

Login_Control::~Login_Control()
{
    ifile.close();
}

/*
 * Returns TRUE if the username is valid and in USE.
 *
 * */

bool Login_Control::validUsername(std::string _name)
{
    std::string line;

    ifile.clear();
    ifile.seekg(0);

    while(getline(ifile, line)){
       if(_name.compare(line) == 0){
           return true;
       }
    }

    return false;
}

/* Used when full portfolio is registered */
void Login_Control::registerUsername(std::string _name)
{

}



/* Used as a safety measure if/when multisystem use is involved, more than
 * one instance at similar times
 * RETURNS TRUE WHEN GOOD.
 */
bool Login_Control::registerTempUsername(std::string _name)
{
    std::string line = _name + temp_PostSig;

    std::ofstream ofile;
    ofile.open("username_list.txt", std::ofstream::out | std::ofstream::app);

    if(validUsername(_name)){
        return false;
    }

    ofile << line.c_str() << std::endl;

    return true;
}

void Login_Control::unregisterTempUsername(std::string _name)
{
    std::string tempName, line;
    tempName = _name + temp_PostSig;

    std::fstream ofile;
    ofile.open("temp_File.txt", std::ofstream::out | std::ofstream::trunc);

    //std::cout << "write to temp :: " << ofile.is_open() << std::endl;

    ifile.clear();
    ifile.seekg(0);

    while(getline(ifile, line)){
        if(tempName.compare(line) != 0)
        {
            ofile << line << std::endl;
        }
    }

   ofile.close();
   ifile.close();

   remove("username_list.txt");
   rename("temp_File.txt", "username_list.txt");

   ifile.open("username_list.txt");
}
