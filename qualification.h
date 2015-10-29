#ifndef QUALIFICATION_H
#define QUALIFICATION_H

#include <string>
#include <vector>

using namespace std;

class Qualification
{
public:
    Qualification();
    Qualification(string pD, string dD, string aD, int _id, int _type, int _range, int _value);

    string getPersonalDescription();
    string getDesiredDescription();
    string getAdminDescription();
    int getId();
    int getType();
    int getRange();
    int getValue();

    void setPersonalDescription(std::string pD);
    void setDesiredDescription(std::string dD);
    void setAdminDescription(std::string aD);
    void setQVals(int _id, int _type, int _range, int _value);


private:
    std::string PersonalDescription;
    std::string DesiredDescription;
    std::string AdminDescription;

    int id, type, range, value;

    };

#endif // QUALIFICATION_H
