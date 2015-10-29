#ifndef SQLSTORAGE_H
#define SQLSTORAGE_H

#include <QtSql/QtSql>
#include "StorageObject.h"

#include <string>
#include "ProfileEntity.h"
#include "project.h"

class SqlStorage :
    public StorageObject
{
public:
    SqlStorage();
    ~SqlStorage();

    void clearProfiles();
    void addProfile(ProfileEntity&);
    void modifyProfile(ProfileEntity&);
    void removeProfile(string);

    void clearProjects();
    void addProject(Project&);
    void modifyProject(Project&);
    void removeProject(string);

    ProfileEntity* getProfile(string);
    void getProfileList(vector<ProfileEntity*>&);

    void getProjectList(vector<Project*>*);
    void getQualificationList(vector<Qualification*>*);

    int profileExists(string);
    void algorithmIntelligence(vector<ProfileEntity*>&);

private:
    QSqlDatabase db;
    void test();
};

#endif // SQLSTORAGE_H
