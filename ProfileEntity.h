#ifndef PROFILE_ENTITY_H
#define PROFILE_ENTITY_H

#include <vector>
#include <string>
#include <tuple>
#include <iostream>

#define qualLayout tuple<int, int>

using namespace std;
class ProfileEntity
{
public:
    ProfileEntity();
	ProfileEntity(string _username);
	~ProfileEntity();

	void setPersonalQual(vector<qualLayout>&);
	void setDesiredQual(vector<qualLayout>&);
    void setAdminPrivilege(bool);

    vector<qualLayout>& getPersonalQual();
    vector<qualLayout>& getDesiredQual();
	string getUsername();
    bool isAdmin();

private:
	string m_username;
    bool adminPriv;

	vector<qualLayout> personalQual, desiredQual;
};

#endif
