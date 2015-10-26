#include "ProfileEntity.h"


ProfileEntity::ProfileEntity(string _username)
{
	m_username = _username;
}


ProfileEntity::~ProfileEntity()
{
}

void ProfileEntity::setPersonalQual(vector<qualLayout>& _perQualList)
{
	for (int i = 0; i < _perQualList.size(); i++)
	{
		qualLayout temp = _perQualList[i];

		personalQual.push_back(temp);
	}
}

/**/
void ProfileEntity::setDesiredQual(vector<qualLayout>& _desQualList)
{
	for (int i = 0; i < _desQualList.size(); i++)
	{
		qualLayout temp = _desQualList[i];

		desiredQual.push_back(temp);
	}
}

const vector<qualLayout>& ProfileEntity::getPersonalQual()
{
	return personalQual;
}

const vector<qualLayout>& ProfileEntity::getDesiredQual()
{
	return desiredQual;
}

string ProfileEntity::getUsername()
{
	return m_username;
}
