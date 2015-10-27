#ifndef STORAGE_MANAGER_H
#define STORAGE_MANAGER_H

#include "ProfileEntity.h"
#include "StorageObject.h"
#include "SimpleFileStorage.h"

#define POST_Placeholder "~~"

class StorageManager
{
public:
	StorageManager();
	~StorageManager();

	int getProjectCount();
	int getUserCount();
	ProfileEntity& getProfile(string);

	/**/
    void registerUser(ProfileEntity&);
    void modifyUser(ProfileEntity&);
    void removeUser(string);

	/**/
    ProfileEntity& setNamePlaceholder(std::string);
	void removeNamePlaceholder(std::string);

	bool userNameExists(std::string);

    /**/
    void getQualificationList(vector<pair<string, tuple<int, int, int, int>>>&);

private:
	StorageObject* dbObject;

};

#endif
