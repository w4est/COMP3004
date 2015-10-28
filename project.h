#ifndef PROJECT_H
#define PROJECT_H

#include <QListWidgetItem>
#include <string>
#include <vector>
#include "qualification.h"

using namespace std;

class Project
{
public:
    Project();
    Project(string name, string owner, string dec, vector<Qualification> qList);
    string getProjectName();
    string getProjectDescription();
    string getOwner();
    vector<Qualification> getQualifications();
    vector<string> getStudents();
    void setProjectName(string name);
    void setProjectDescription(string description);
    void setOwner(string owner);
    void setQualifications(vector<Qualification> qList);
    void setStudents(vector<string> sList);
private:
    string ProjectName;
    string ProjectDescription;
    string Owner;
    vector<Qualification> qualificationList;
    vector<string> students;

};

#endif // PROJECT_H
