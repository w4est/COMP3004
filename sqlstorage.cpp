#include "sqlstorage.h"

SqlStorage::SqlStorage()
{
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("MyDatabase");

    if(db.open()){
        QSqlQuery query(db);

        query.exec("CREATE TABLE Qualification_List ()");
    }
}

SqlStorage::~SqlStorage()
{

}

void SqlStorage::clearProfiles()
{

}

void SqlStorage::addProfile(ProfileEntity&)
{

}

void SqlStorage::modifyProfile(ProfileEntity&)
{

}

void SqlStorage::removeProfile(string)
{

}

void SqlStorage::clearProjects()
{

}

void SqlStorage::addProject(Project&)
{

}

void SqlStorage::modifyProject(Project&)
{

}

void SqlStorage::removeProject(string)
{

}

ProfileEntity* SqlStorage::getProfile(string)
{

}

void SqlStorage::getProfileList(vector<ProfileEntity*>&)
{

}

void SqlStorage::getProjectList(vector<Project*>*)
{

}

void SqlStorage::getQualificationList(vector<Qualification*>*)
{

}

int SqlStorage::profileExists(string)
{

}

void SqlStorage::algorithmIntelligence(vector<ProfileEntity*>&)
{

}

void SqlStorage::test()
{

}
