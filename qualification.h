#ifndef QUALIFICATION_H
#define QUALIFICATION_H

class Qualification
{
public:
    Qualification();
    Qualification(std::string pD, std::string dD, std::aD, tuple<int, int, int, int> qL);
    std::string getPersonalDescription();
    std::string getDesiredDescription();
    std::string getAdminDescription();
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
