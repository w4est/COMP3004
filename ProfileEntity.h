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
	ProfileEntity(string _username);
	~ProfileEntity();

	void setPersonalQual(vector<qualLayout>&);
	void setDesiredQual(vector<qualLayout>&);

	const vector<qualLayout>& getPersonalQual();
	const vector<qualLayout>& getDesiredQual();
	string getUsername();

private:
	string m_username;

	vector<qualLayout> personalQual, desiredQual;
};

#endif