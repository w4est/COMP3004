#ifndef PROJECT_H
#define PROJECT_H

class Project
{
public:
    Project();
    Project(std::name, std::string owner, std::string dec, std::vector<string> qList);
    std::string getProjectName();
    std::string getProjectDescription();
    std::string getOwner();
    std::vector<Qualification> getQualifications();
    std::vector<string> getStudents();
    void setProjectName(std::string name);
    void setProjectDescription(std::string description);
    void setOwner(std::string owner);
    void setQualifications(std::vector<Qualification> qList);
    void setStudents(std::vector<string> sList);
private:
    std::string ProjectName;
    std::string ProjectDescription;
    std::string Owner;
    std::vector<Qualification> qualificationList;
    std::vector<string> students;

};

#endif // PROJECT_H
