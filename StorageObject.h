#ifndef STORAGEOBJECT_H
#define STORAGEOBJECT_H

#include <vector>
#include <map>
#include "ProfileEntity.h"

#define qualLayout_4 tuple<int, int, int, int>

using namespace std;
class StorageObject
{
public:
	enum Qual_Types {slide_range = 1,
					 list_range,
					 true_false};

	StorageObject();
    virtual ~StorageObject();

	/*manipulate/push to persistant*/
    virtual void addProfile(ProfileEntity&) = 0;
    virtual void modifyProfile(ProfileEntity&) = 0;
    virtual void removeProfile(string) = 0;

	/*get from persistant*/
	virtual ProfileEntity* getProfile(string) = 0;
	virtual void getProfileList(vector<ProfileEntity*>&) = 0;
	const vector<pair<string, qualLayout_4>>& getQualificationList();
	virtual bool profileExists(string)  = 0;
	virtual void algorithmIntelligence(vector<ProfileEntity*>&) = 0;

protected:
	vector<pair<string, qualLayout_4 > > qualList;
	map<string, Qual_Types> typeMap;
};

#endif
