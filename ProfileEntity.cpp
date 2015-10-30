#include "ProfileEntity.h"


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

    /*for (int i = 0; i < _perQualList.size(); i++)
	{
        tuple<int, int> tpair;

        get<0>(tpair) = get<0>(_perQualList[i]);
        get<1>(tpair) = get<1>(_perQualList[i]);

        personalQual.push_back(tpair);
    }*/
}

/**/
void ProfileEntity::setDesiredQual(vector<qualLayout>& _desQualList)
{
    for (unsigned int i = 0; i < _desQualList.size(); i++)
	{
		qualLayout temp = _desQualList[i];

		desiredQual.push_back(temp);
	}
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
