#include "qualification.h"

Qualification::Qualification()
{
    PersonalDescription ="";
    DesiredDescription = "";
    AdminDescription = "";
}
Qualification::Qualification(string pD, string dD, string aD, int _id, int _type, int _range, int _value){
    PersonalDescription = pD;
    DesiredDescription = dD;
    AdminDescription = aD;

    setQVals(_id, _type, _range, _value);
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

int Qualification::getId()
{
    return id;
}

int Qualification::getType()
{
    return type;
}

int Qualification::getRange()
{
    return range;
}

int Qualification::getValue()
{
    return value;
}

void Qualification::setPersonalDescription(string pD){
    PersonalDescription = pD;
}

void Qualification::setDesiredDescription(string dD){
    DesiredDescription = dD;
}

void Qualification::setAdminDescription(string aD){
    AdminDescription = aD;
}

void Qualification::setQVals(int _id, int _type, int _range, int _value){
    id = _id;
    type = _type;
    range = _range;
    value = _value;
}
