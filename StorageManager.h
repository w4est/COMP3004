#ifndef STORAGE_MANAGER_H
#define STORAGE_MANAGER_H

#include "ProfileEntity.h"
#include "project.h"
#include "qualification.h"
#include "StorageObject.h"
#include "SimpleFileStorage.h"
//#include "sqlstorage.h"

#define POST_Placeholder "~~"

class StorageManager
{
public:
	StorageManager();
	~StorageManager();

	int getProjectCount();
    int getQualificationCount();

    /*Project modification*/
    Project& getProject(string);
    void createProject(Project&);
    void modifyProject(Project&);
    void removeProject(string);
    void saveProjects();

    /*Profile modification*/
    void testClear();
    ProfileEntity& getProfile(string);
    void registerUser(ProfileEntity&);
    void modifyUser(ProfileEntity&);
    void removeUser(string);

    /*Testing availability*/
    ProfileEntity& setNamePlaceholder(std::string);
	void removeNamePlaceholder(std::string);

    int userNameExists(std::string);

    /*Lists*/
    Project* getProject(int _index, string _name);
    vector<Qualification*>& getQualificationList();
    vector<Project*>& getProjectList();

private:
	StorageObject* dbObject;

    vector<ProfileEntity*> outEntities;
    vector<Project*> projectList;
    vector<Qualification*> qualList;

    void loadQualifications();
    void loadProjects();

};

#endif
