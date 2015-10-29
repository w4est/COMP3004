#ifndef STORAGEOBJECT_H
#define STORAGEOBJECT_H

#include <vector>
#include "ProfileEntity.h"
#include "qualification.h"
#include "project.h"

#define qualLayout_4 tuple<int, int, int, int>

using namespace std;
class StorageObject
{
public:
    enum Qual_Types {slide_range = 0,
					 list_range,
                     true_false,
                     grade};

	StorageObject();
    virtual ~StorageObject();

    /*push to persistant*/
    virtual void clearProjects() = 0;
    virtual void addProject(Project&) = 0;
    virtual void modifyProject(Project&) = 0;
    virtual void removeProject(string) = 0;

	/*manipulate/push to persistant*/
    virtual void clearProfiles() = 0;
    virtual void addProfile(ProfileEntity&) = 0;
    virtual void modifyProfile(ProfileEntity&) = 0;
    virtual void removeProfile(string) = 0;

	/*get from persistant*/
	virtual ProfileEntity* getProfile(string) = 0;
	virtual void getProfileList(vector<ProfileEntity*>&) = 0;

    virtual void getProjectList(vector<Project*>*) = 0;
    virtual void getQualificationList(vector<Qualification*>*) = 0;


    virtual int profileExists(string)  = 0;
	virtual void algorithmIntelligence(vector<ProfileEntity*>&) = 0;

protected:
    string typeMap[4];
};

#endif
