#include "qualification.h"

Qualification::Qualification()
{
    PersonalDescription ="";
    DesiredDescription = "";
    AdminDescription = "";
}
Qualification::Qualification(string pD, string dD, string aD, tuple<int, int, int, int> qL){
    PersonalDescription = pD;
    DesiredDescription = dD;
    AdminDescription = aD;
    qVals = qL;
}

string Qualification::getPersonalDescription(){
    return PersonalDescription;
}

string Qualification::getDesiredDescription(){
    return DesiredDescription;
}

string Qualification::getAdminDescription(){
    return AdminDescription;
}

tuple<int, int, int, int> Qualification::getQVals(){
    return qVals;
}

void Qualification::setPersonalDescription(string pD){
    PersonalDescription = pD;
}

void Qualification::setDesiredDescription(string dD){
    DesiredDescription = dD;
}

void Qualification::getAdminDescription(string aD){
    AdminDescription = aD;
}

void Qualification::setQVals(tuple<int, int, int,int>qL){
    qVals = qL;
}
