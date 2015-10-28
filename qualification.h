#ifndef QUALIFICATION_H
#define QUALIFICATION_H

#include <string>
#include <vector>
#include <tuple>

using namespace std;

class Qualification
{
public:
    Qualification();
    Qualification(string pD, string dD, string aD, tuple<int, int, int, int> qL);
    string getPersonalDescription();
    string getDesiredDescription();
    string getAdminDescription();
    tuple<int, int, int, int> getQVals();
    void setPersonalDescription(std::string pD);
    void setDesiredDescription(std::string dD);
    void getAdminDescription(std::string aD);
    void setQVals(tuple<int, int, int,int>qL);


private:
    std::string PersonalDescription;
    std::string DesiredDescription;
    std::string AdminDescription;
    tuple<int, int, int, int> qVals;
    };

#endif // QUALIFICATION_H
