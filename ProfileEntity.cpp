#include "ProfileEntity.h"
ProfileEntity::ProfileEntity()
{
    m_username = "";
    adminPriv = false;
    personalQual = vector<tuple<int, int>>();
    desiredQual = vector<tuple<int, int>>();
}

ProfileEntity::ProfileEntity(string _username)
{
	m_username = _username;
    adminPriv = false;
    personalQual = vector<tuple<int, int>>();
    desiredQual = vector<tuple<int, int>>();
}


ProfileEntity::~ProfileEntity()
{
}

void ProfileEntity::setPersonalQual(vector<tuple<int, int>>& _perQualList)
{
    personalQual = _perQualList;


}

/**/
void ProfileEntity::setDesiredQual(vector<qualLayout>& _desQualList)
{
    desiredQual = _desQualList;
}

void ProfileEntity::setAdminPrivilege(bool _right)
{
    adminPriv = _right;
}

vector<qualLayout>& ProfileEntity::getPersonalQual()
{
	return personalQual;
}

vector<qualLayout>& ProfileEntity::getDesiredQual()
{
	return desiredQual;
}

string ProfileEntity::getUsername()
{
	return m_username;
}

bool ProfileEntity::isAdmin()
{
    return adminPriv;
}
