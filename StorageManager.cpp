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

        if(temp){
            delete temp;
        }
    }

    while(!projectList.empty())
    {
        Project* temp = projectList.back();
        projectList.pop_back();

        if(temp){
            delete temp;
        }
    }

    while(!outEntities.empty())
    {
        ProfileEntity* temp = outEntities.back();
        outEntities.pop_back();

        if(temp){
            delete temp;
        }
    }

    while(!redundantProfileList.empty())
    {
        ProfileEntity* temp = redundantProfileList.back();
        redundantProfileList.pop_back();

        if(temp){
            delete temp;
        }
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
    if(outEntities.size() > 0){
        ProfileEntity* temp = outEntities.back();
        outEntities.pop_back();
        delete temp;
    }
    outEntities.push_back(dbObject->getProfile(_username));
    return *(outEntities.back());
}

void StorageManager::createProject(Project& _project)
{
    projectList.push_back(&_project);
}

void StorageManager::modifyProject(Project & _project)
{
    if(&_project){}
    //Done by saveProjects Right Now
}

void StorageManager::removeProject(string)
{
    //Not Necessary Right Now
}

void StorageManager::saveProjects()
{
    //dbObject->clearProjects();
    for(unsigned int i = 0; i < projectList.size(); i++){
        //dbObject->addProject(*projectList.at(i));
        dbObject->modifyProject(*projectList.at(i));
    }
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

void StorageManager::saveProfile()
{
    if(outEntities.size() > 0){
        dbObject->modifyProfile(*(outEntities.back()));
    }
}

/**/
void StorageManager::removeNamePlaceholder(std::string _username)
{
    if(userNameExists(_username)){
        removeUser(POST_Placeholder + _username);
        for(unsigned int i = 0; i < outEntities.size(); i++)
        {
            if(_username.compare(outEntities.at(i)->getUsername()) == 0){
                ProfileEntity* temp = outEntities.back();
                outEntities.pop_back();
                delete temp;
                //outEntities.erase(outEntities.begin()+i);
            }
        }
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

ProfileEntity* StorageManager::getProfile(int _index, string _name)
{
    if(redundantProfileList.size() == 0){
        dbObject->getProfileList(redundantProfileList);
    }

    for(int i = 0; i < redundantProfileList.size(); i++)
    {
        ProfileEntity* tEnt = redundantProfileList.at(i);
        if(tEnt->getUsername().compare(_name) == 0)
        {
            return tEnt;
        }
    }

    return NULL;
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
    cout << "projectList::" << projectList.size() << endl;
}
