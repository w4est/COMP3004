#include "project.h"

Project::Project()
{

    ProjectName = "";
    ProjectDescription = "";
    Owner = "";

}

Project::Project(string name, string owner, string dec, vector<pair<int, int>> qList){
    ProjectName = name;
    ProjectDescription = dec;
    Owner = owner;
    qualificationList = qList;
}

string Project::getProjectName()
{
    return ProjectName;
}

string Project::getProjectDescription(){
    return ProjectDescription;
}

string Project::getOwner(){
    return Owner;
}

const vector<pair<int, int>>& Project::getQualifications(){
    return qualificationList;
}

const vector<string>& Project::getStudents(){
    return students;
}

void Project::setProjectName(string name){
    ProjectName = name;
}

void Project::setProjectDescription(string description){
    ProjectDescription = description;
}

void Project::setOwner(string owner){
    Owner  = owner;
}

void Project::setQualifications(vector<pair<int, int>> qList){
    qualificationList = qList;
}

void Project::setStudents(vector<string> sList){
    students = sList;
}

