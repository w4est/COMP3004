#include "StorageManager.h"


StorageManager::StorageManager()
{
    //dbObject = new SqlStorage();
    dbObject = new SimpleFileStorage();

    this->loadQualifications();
    this->loadProjects();
}


StorageManager::~StorageManager()
{
    delete dbObject;

    while(!qualList.empty())
    {
        Qualification* temp = qualList.back();
        qualList.pop_back();
        delete temp;
    }

    while(!projectList.empty())
    {
        Project* temp = projectList.back();
        projectList.pop_back();
        delete temp;
    }

    while(!outEntities.empty())
    {
        ProfileEntity* temp = outEntities.back();
        outEntities.pop_back();
        delete temp;
    }
}

int StorageManager::getProjectCount()
{
    return projectList.size();
}

int StorageManager::getQualificationCount()
{
    return qualList.size();
}

ProfileEntity& StorageManager::getProfile(string _username)
{
	return *(dbObject->getProfile(_username));
}

void StorageManager::createProject(Project& _project)
{
    projectList.push_back(&_project);
    cout << "created project :: " << getProjectCount() << endl;
}

void StorageManager::modifyProject(Project & _project)
{

}

void StorageManager::removeProject(string)
{

}

void StorageManager::saveProjects()
{
    dbObject->clearProjects();
    for(int i = 0; i < projectList.size(); i++){
        //dbObject->addProject(projectList.at(i));
    }

}

void StorageManager::testClear()
{
    dbObject->clearProfiles();
}

/**/
void StorageManager::registerUser(ProfileEntity& _profile)
{
    if (dbObject->profileExists(_profile.getUsername())){
		return;
    }
	dbObject->addProfile(_profile);
}

void StorageManager::modifyUser(ProfileEntity& _username)
{
    dbObject->modifyProfile(_username);
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
    delete newEnt;
    newEnt = new ProfileEntity(_username);
    outEntities.push_back(newEnt);

    return *outEntities.back();
}

/**/
void StorageManager::removeNamePlaceholder(std::string _username)
{
    if(userNameExists(_username)){
        removeUser(POST_Placeholder + _username);
    }
    return;
}

int StorageManager::userNameExists(std::string _username)
{
	return dbObject->profileExists(_username) || dbObject->profileExists(POST_Placeholder + _username);
}

Project* StorageManager::getProject(int _index, string _name)
{
    if(_index < 0 || _index > getProjectCount())
    {
        for(int i = 0; i < getProjectCount(); i++)
        {
            Project* temp = projectList.at(i);
            if(_name.compare(temp->getProjectName()) == 0)
            {
                return temp;
            }
        }
        return nullptr;
    }
    else
    {
        return projectList.at(_index);
    }
}

vector<Qualification*>& StorageManager::getQualificationList()
{
    return qualList;
}

vector<Project*>& StorageManager::getProjectList()
{
    return projectList;
}

void StorageManager::loadQualifications()
{
    dbObject->getQualificationList(&qualList);
}

void StorageManager::loadProjects()
{
    dbObject->getProjectList(&projectList);
}
