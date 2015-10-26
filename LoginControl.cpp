#include "LoginControl.h"

class Login;

LoginControl::LoginControl(MasterControl* _parent)
{
	m_Parent = _parent;
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

void LoginControl::unregisterTempUser(string _username)
{
    m_Parent->getStorageAccess().removeNamePlaceholder(_username);
}
