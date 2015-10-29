#include "MasterControl.h"

MasterControl::MasterControl(QWidget* _parent)
{
    current_user_profile = 0;
    login_control = 0;
    admin_control = 0;
    student_control = 0;
    lastPoint = 0;

    parent = _parent;
    storage_control = new StorageManager();
    /*setUserProfile(storage_control->getProfile("Christine"));

    //createLoginControl();

    Project* temp = new Project();
    temp->setOwner("Christine");
    temp->setProjectName("Trial project");
    temp->setProjectDescription("Nothing");
    vector<pair<int, int>> p;
    vector<string> s;
    for(int i = 0; i < 36; i++)
    {
        p.push_back(make_pair<int, int>(i+1, i*88));
        s.push_back("adasads");
    }
    temp->setQualifications(p);
    temp->setStudents(s);


    storage_control->createProject(*temp);

    /*vector<Project*> z = storage_control->getProjectList();
    std::cout << z.front()->getProjectName() <<std::endl;
    std::cout << z.front()->getProjectDescription() <<std::endl;
    std::cout << z.front()->getOwner() <<std::endl;
    std::cout << z.front()->getQualifications().size() <<std::endl;
    std::cout << z.front()->getStudents().size() <<std::endl;
    */
    //cout << "here " << endl;
    //createAdminControl();
    //storage_control = new SimpleFileStorage();
    createLoginControl();
}


MasterControl::~MasterControl()
{
    if (current_user_profile) delete current_user_profile;
    if (login_control) delete login_control;
    if (admin_control) delete admin_control;
    if (student_control) delete student_control;
    if (storage_control) delete storage_control;
    if (lastPoint) delete lastPoint;
}


StorageManager& MasterControl::getStorageAccess()
{
	return *storage_control;
}

void MasterControl::createLoginControl()
{
    if(!login_control){
        login_control = new LoginControl(this, parent);
    }
}

void MasterControl::createAdminControl()
{

    if(!admin_control){
        admin_control = new AdminControl(this, parent);
    }
}

void MasterControl::createStudentControl()
{
    if(!student_control){
        student_control = new StudentControl(this, parent);
    }
}

void MasterControl::setUserProfile(ProfileEntity& _user)
{
	current_user_profile = &_user;
}

void MasterControl::completeLogin(QPoint* _point)
{
    if (current_user_profile)
    {
        changePoint(_point);

        delete login_control;
        login_control = 0;

        if(current_user_profile->isAdmin()){
            createAdminControl();
        }
        else{
            createStudentControl();
        }
	}
}

void MasterControl::logout(QPoint* _point)
{
    if(current_user_profile)
    {
        changePoint(_point);

        bool admin = current_user_profile->isAdmin();

        if(current_user_profile) delete current_user_profile;
        current_user_profile = 0;

        if(admin){
            delete admin_control;
            admin_control = 0;
        }
        else{
            delete student_control;
            student_control = 0;
        }
        createLoginControl();
    }
}

ProfileEntity* MasterControl::getLoggedUser()
{
    return current_user_profile;
}

const QPoint* MasterControl::getLastPoint()
{
    return lastPoint;
}

void MasterControl::changePoint(QPoint *_point)
{
    if(lastPoint){
        delete lastPoint;
    }
    lastPoint = _point;
}
