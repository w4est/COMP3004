#include "StorageManager.h"


StorageManager::StorageManager()
{
	dbObject = new SimpleFileStorage();
}


StorageManager::~StorageManager()
{
	if (dbObject) delete dbObject;
}

int StorageManager::getProjectCount()
{
	return 0;
}

int StorageManager::getUserCount()
{
	return 0;
}

ProfileEntity& StorageManager::getProfile(string _username)
{
	return *(dbObject->getProfile(_username));
}

/**/
void StorageManager::registerUser(ProfileEntity& _profile)
{
	if (dbObject->profileExists(_profile.getUsername())){
		return;
	}
	dbObject->addProfile(_profile);
}

void StorageManager::modifyUser(ProfileEntity&)
{
}

void StorageManager::removeUser(string _username)
{
	dbObject->removeProfile(_username);
}

/**/
ProfileEntity& StorageManager::setNamePlaceholder(std::string _username)
{
    ProfileEntity* newEnt = new ProfileEntity(POST_Placeholder + _username);
    dbObject->addProfile(*newEnt);
    return *(dbObject->getProfile(POST_Placeholder + _username));
}

void StorageManager::removeNamePlaceholder(std::string _username)
{
    if(userNameExists(_username)){
        removeUser(POST_Placeholder + _username);
    }
    return;
}

bool StorageManager::userNameExists(std::string _username)
{
	return dbObject->profileExists(_username) || dbObject->profileExists(POST_Placeholder + _username);
}

void StorageManager::getQualificationList(vector<pair<string, tuple<int, int, int, int>>>& _list)
{
    _list = dbObject->getQualificationList();
}
