#include "LoginControl.h"

class Login;

LoginControl::LoginControl(MasterControl* _parent)
{
	m_Parent = _parent;
    user = 0;
    login_window = new Login(this, NULL);
    login_window->show();
}


LoginControl::~LoginControl()
{
	m_Parent = 0;
	user = 0;
}

bool LoginControl::userExists(string _username)
{
    return m_Parent->getStorageAccess().userNameExists(_username);
}

void LoginControl::loginUser(string _username)
{
	if (userExists(_username)){
		 user = &(m_Parent->getStorageAccess().getProfile(_username));
		 m_Parent->setUserProfile(*user);
		 m_Parent->completeLogin();
	}
}

bool LoginControl::registerTempUser(string _username)
{
    if(!userExists(_username)){
        user = &(m_Parent->getStorageAccess().setNamePlaceholder(_username));
        return true;
    }
    else{
        return false;
    }
}

ProfileEntity* LoginControl::getCurrentUser()
{
    return user;
}

void LoginControl::unregisterTempUser(string _username)
{
    m_Parent->getStorageAccess().removeNamePlaceholder(_username);
}

void LoginControl::getQualList(vector<pair<string, tuple<int, int, int, int>>>& _list)
{
    m_Parent->getStorageAccess().getQualificationList(_list);
}
