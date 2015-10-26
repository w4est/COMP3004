#ifndef STORAGEMANAGER_H
#define STORAGEMANAGER_H

#include "VS_Files/ProfileEntity.h"
#include "StorageObject.h"

class StorageManager
{
public:
    StorageManager();
    ~StorageManager();

    bool isActive();
    int getProjectCount();
    int getUserCount();

    /*core actions*/
    void registerUser(const ProfileEntity&);
    void modifyUser(const ProfileEntity&);
    void removeUser(const ProfileEntity&);

    /*temp username incase of multiuser database*/
    void setNamePlaceholder(std::string);
    void removeNamePlaceholder(std::string);

private:
    StorageObject* dbObject;

};

#endif // STORAGEMANAGER_H
