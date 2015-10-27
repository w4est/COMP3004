#include "qualification.h"

Qualification::Qualification()
{
    PersonalDescription ="";
    DesiredDescription = "";
    AdminDescription = "";
}
Qualification::Qualification(std::string pD, std::string dD, std::aD, tuple<int, int, int, int> qL){
    PersonalDescription = pD;
    DesiredDescription = dD;
    AdminDescription = aD;
    qVals = qL;
}

std::string Qualification::getPersonalDescription(){
    return PersonalDescription;
}

std::string Qualification::getDesiredDescription(){
    return DesiredDescription;
}

std::string Qualification::getAdminDescription(){
    return AdminDescription;
}

tuple<int, int, int, int> Qualification::getQVals(){
    return qVals;
}

void Qualification::setPersonalDescription(std::string pD){
    PersonalDescription = pD;
}

void Qualification::setDesiredDescription(std::string dD){
    DesiredDescription = dD;
}

void Qualification::getAdminDescription(std::string aD){
    AdminDescription = aD;
}

void Qualification::setQVals(tuple<int, int, int,int>qL){
    qVals = qL;
}
