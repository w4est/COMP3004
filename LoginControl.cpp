#include "LoginControl.h"

class Login;

LoginControl::LoginControl(MasterControl* _control, QWidget* _parent)
{
    m_Parent = _control;
    user = 0;

    login_window = _control->GetForm(0,this, m_Parent->getLastPoint()->x(), m_Parent->getLastPoint()->y());

            //new Login(this, _parent, m_Parent->getLastPoint()->x(), m_Parent->getLastPoint()->y());
    //login_window->show();
}


LoginControl::~LoginControl()
{
    m_Parent = 0;
	user = 0;
    //if(login_window) login_window->deleteLater();
    //login_window = NULL;
}

void LoginControl::shutdown()
{
    m_Parent->kill();
}

int LoginControl::userExists(string _username)
{
    return m_Parent->getStorageAccess().userNameExists(_username);
}

void LoginControl::loginUser(string _username, QPoint* _point)
{
	if (userExists(_username)){
         user = &(m_Parent->getStorageAccess().getProfile(_username));
		 m_Parent->setUserProfile(*user);
         m_Parent->completeLogin(_point);
         //login_window = NULL;
         //(login_window)->deleteLater();
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

void LoginControl::registerUser()
{
    if(user){

        m_Parent->getStorageAccess().registerUser(*user);
        m_Parent->getStorageAccess().removeNamePlaceholder(user->getUsername());
    }
}

void LoginControl::unregisterTempUser(string _username)
{
    m_Parent->getStorageAccess().removeNamePlaceholder(_username);
}

const vector<Qualification*>& LoginControl::getQualList()
{
    return m_Parent->getStorageAccess().getQualificationList();
}

MasterControl* LoginControl::getMParent(){
    return m_Parent;
}
