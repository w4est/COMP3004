#ifndef SIMPLE_STORAGE_H
#define SIMPLE_STORAGE_H

#include "StorageObject.h"
#include <fstream>
#include <streambuf>
#include <stdio.h>
#include "rapidxml.hpp"
#include "rapidxml_print.hpp"
#include "rapidxml_utils.hpp"



#define usernameFile "username_list.txt"
#define qualFile "Qualification_List.xml"
#define profileFile "profile_list.xml"
#define projectFile "project_list.xml"

class SimpleFileStorage :
	public StorageObject
{
public:
	SimpleFileStorage();
	~SimpleFileStorage();

	void addProfile(ProfileEntity&);
	void modifyProfile(ProfileEntity&);
	void removeProfile(string);

	ProfileEntity* getProfile(string);
	void getProfileList(vector<ProfileEntity*>&);
    int profileExists(string);
	void algorithmIntelligence(vector<ProfileEntity*>&);

private:
	rapidxml::xml_document<> doc;
	rapidxml::xml_node<> *root_node, *prof_root, *proj_root;
	vector<char> profileBuffer, projectBuffer;

	bool isProjectModified = true;
	bool isProfileModified = true;

	void reloadXMLFile(int, int _flag = 0);
	void loadQualifications();
};

#endif
