#include "project.h"

Project::Project()
{
    ProjectName = "";
    ProjectDescription = "";
    Owner = "";

}

Project::Project(std::name, std::string owner, std::string dec, std::vector<string> qList){
    ProjectName = name;
    ProjectDescription = dec;
    Owner = owner;
    qualificationList =qList;
}

std::string Project::getProjectName()
{
    return ProjectName;
}

std::string Project::getProjectDescription(){
    return ProjectDescription;
}

std::string Project::getOwner(){
    return Owner;
}

std::vector<Qualification> Project::getQualifications(){
    return qualificationList;
}

std::vector<string> Project::getStudents(){
    return students;
}

void Project::setProjectName(std::string name){
    ProjectName = name;
}

void Project::setProjectDescription(std::string description){
    ProjectDescription = description;
}

void Project::setOwner(std::string owner){
    Owner  = owner;
}

void Project::setQualifications(std::vector<Qualification> qList){
    qualificationList = qList;
}

void Project::setStudents(std::vector<string> sList){
    students = sList;
}

