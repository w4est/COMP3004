#include "SimpleFileStorage.h"


SimpleFileStorage::SimpleFileStorage()
{
    reloadXMLFile(0);
    reloadXMLFile(1);
}


SimpleFileStorage::~SimpleFileStorage()
{
    proj_root->remove_all_nodes();
    prof_root->remove_all_nodes();
    root_node->remove_all_nodes();
    doc.clear();

    vector<char> empty, empty1;
    empty.swap(profileBuffer);
    empty1.swap(projectBuffer);
}

void SimpleFileStorage::clearProjects()
{
    isProjectModified = true;
    reloadXMLFile(1);

    vector<rapidxml::xml_node<>*> to_del;

    for(rapidxml::xml_node<>* stuNode = proj_root->first_node("Project"); stuNode; stuNode = stuNode->next_sibling("Project"))
    {
        to_del.push_back(stuNode);
    }

    for(int i = 0; i < to_del.size(); i++)
    {
        proj_root->remove_node(to_del.back());
        to_del.pop_back();
    }

    string text = "\r\n";
    rapidxml::print(back_inserter(text), doc, 0);

    ofstream out(projectFile);
    out << doc;
    out.close();
}

void SimpleFileStorage::addProject(Project &_project)
{

}

void SimpleFileStorage::modifyProject(Project &_project)
{
    removeProject(_project.getProjectName());
    addProject(_project);
}

void SimpleFileStorage::removeProject(string _name)
{
    ifstream temp(projectFile);

    if (!temp.is_open())
    {
        cout << "ERROR: Project_List.xml non-existant" << endl;
        return;
    }

    vector<char> proBuffer;
    proBuffer = vector<char>(istreambuf_iterator<char>(temp), istreambuf_iterator<char>());
    proBuffer.push_back('\0');

    doc.parse<0>(&proBuffer[0]);
    proj_root = doc.first_node("Project_List");


    rapidxml::xml_node<> *to_del = 0;

    for (rapidxml::xml_node<> * stuNode = proj_root->first_node("Project"); stuNode; stuNode = stuNode->next_sibling())
    {
        if (_name.compare(stuNode->first_attribute("name")->value()) == 0)
        {
            to_del = stuNode;
            break;
        }
    }

    if (!to_del){
        return;
    }

    proj_root->remove_node(to_del);
    string text = "\r\n";
    rapidxml::print(back_inserter(text), doc, 0);

    ofstream out(projectFile);
    out << doc;
    out.close();
}

void SimpleFileStorage::clearProfiles()
{
    isProfileModified = true;
    reloadXMLFile(0);

    vector<rapidxml::xml_node<>*> to_del;

    for(rapidxml::xml_node<>* stuNode = prof_root->first_node("Student"); stuNode; stuNode = stuNode->next_sibling("Student"))
    {
       to_del.push_back(stuNode);
    }

    for(int i = 0; i < to_del.size(); i++)
    {
        prof_root->remove_node(to_del.back());
        to_del.pop_back();
    }

    string text = "\r\n";
    rapidxml::print(back_inserter(text), doc, 0);

    ofstream out(profileFile);
    out << doc;
    out.close();

    isProfileModified = true;
    reloadXMLFile(0);
}

void SimpleFileStorage::addProfile(ProfileEntity& _profile)
{
	isProfileModified = true;
	reloadXMLFile(0, 1);
	
	rapidxml::xml_node<>* newStu = doc.allocate_node(rapidxml::node_element, "Student");
	char* newStu_name = doc.allocate_string(_profile.getUsername().c_str());
	rapidxml::xml_attribute<>* newStu_attr = doc.allocate_attribute("name", newStu_name);

	newStu->append_attribute(newStu_attr);

	rapidxml::xml_node<>* newStu_Pers = doc.allocate_node(rapidxml::node_element, "PersonalQualifications");
	rapidxml::xml_node<>* newStu_Des = doc.allocate_node(rapidxml::node_element, "DesiredQualifications");

	//
	prof_root->append_node(newStu);
	//

	vector<tuple<int, int> > perQual = _profile.getPersonalQual();
	for (int i = 0; i < perQual.size(); i++){
		rapidxml::xml_node<>* tempNode = doc.allocate_node(rapidxml::node_element, "Qualification");
		char* id_value = doc.allocate_string((to_string(get<0>(perQual[i]))).c_str());
		char* value_value = doc.allocate_string((to_string(get<1>(perQual[i]))).c_str());


		rapidxml::xml_attribute<>* temp_id = doc.allocate_attribute("id", id_value);
		rapidxml::xml_attribute<>* temp_value = doc.allocate_attribute("value", value_value);

		tempNode->append_attribute(temp_id);
		tempNode->append_attribute(temp_value);

		newStu_Pers->append_node(tempNode);
	}

	vector<tuple<int, int> > desQual = _profile.getDesiredQual();
	for (int i = 0; i < perQual.size(); i++){
		rapidxml::xml_node<>* tempNode = doc.allocate_node(rapidxml::node_element, "Qualification");
		char* id_value = doc.allocate_string((to_string(get<0>(desQual[i]))).c_str());
		char* value_value = doc.allocate_string((to_string(get<1>(desQual[i]))).c_str());


		rapidxml::xml_attribute<>* temp_id = doc.allocate_attribute("id", id_value);
		rapidxml::xml_attribute<>* temp_value = doc.allocate_attribute("value", value_value);

		tempNode->append_attribute(temp_id);
		tempNode->append_attribute(temp_value);

		newStu_Des->append_node(tempNode);
	}

	newStu->append_node(newStu_Pers);
	newStu->append_node(newStu_Des);

	//TO_SAVE___

	string text = "\r\n";
	rapidxml::print(back_inserter(text), doc, 0);

	ofstream out(profileFile);
	out << doc;
	out.close();

	isProfileModified = true;
}

void SimpleFileStorage::modifyProfile(ProfileEntity& _profile)
{
	removeProfile(_profile.getUsername());
	addProfile(_profile);

	isProfileModified = true;
}

void SimpleFileStorage::removeProfile(string _username)
{
    isProfileModified = true;
    reloadXMLFile(0);

	rapidxml::xml_node<> *to_del = 0;

	for (rapidxml::xml_node<> * stuNode = prof_root->first_node("Student"); stuNode; stuNode = stuNode->next_sibling())
	{
		if (_username.compare(stuNode->first_attribute("name")->value()) == 0)
		{
			to_del = stuNode;
			break;
		}
	}

	if (!to_del){
		return;
	}

	prof_root->remove_node(to_del);
	string text = "\r\n";
	rapidxml::print(back_inserter(text), doc, 0);
	
	ofstream out(profileFile);
	out << doc;
	out.close();
}

void SimpleFileStorage::getProfileList(vector<ProfileEntity*>&)
{

}

ProfileEntity* SimpleFileStorage::getProfile(string _username)
{
    ProfileEntity* newProf = new ProfileEntity(_username);
    vector<qualLayout> tempPers, tempDes;

    for(rapidxml::xml_node<> * adminNode = prof_root->first_node("Admin"); adminNode; adminNode = adminNode->next_sibling("Admin"))
    {
        if(_username.compare(adminNode->first_attribute("name")->value()) == 0)
        {
            newProf->setAdminPrivilege(true);
            return newProf;
        }
    }

    for (rapidxml::xml_node<> * stuNode = prof_root->first_node("Student"); stuNode; stuNode = stuNode->next_sibling("Student"))
    {
        if (_username.compare(stuNode->first_attribute("name")->value()) == 0)
        {

            rapidxml::xml_node<> * typeNode = stuNode->first_node("PersonalQualifications");

            for(rapidxml::xml_node<> * qualNode = typeNode->first_node("Qualification"); qualNode; qualNode = qualNode->next_sibling())
            {
                tempPers.push_back(make_tuple(std::stoi(qualNode->first_attribute()->value()), std::stoi(qualNode->last_attribute()->value())));
            }

            typeNode = stuNode->first_node("DesiredQualifications");
            for(rapidxml::xml_node<> * qualNode = typeNode->first_node(); qualNode; qualNode = qualNode->next_sibling())
            {
                tempDes.push_back(make_tuple(std::stoi(qualNode->first_attribute()->value()), std::stoi(qualNode->last_attribute()->value())));
            }
            //cout << "type" << tempPers.size() << "||" << tempDes.size() << endl;

            newProf->setPersonalQual(tempPers);
            newProf->setDesiredQual(tempDes);

            return newProf;
        }
    }
    delete newProf;
	return nullptr;
}



void SimpleFileStorage::getProjectList(vector<Project *> *_pList)
{
    ifstream temp(projectFile);

    if (!temp.is_open())
    {
        cout << "ERROR: Project_List.xml non-existant" << endl;
        return;
    }

    vector<char> proBuffer;
    proBuffer = vector<char>(istreambuf_iterator<char>(temp), istreambuf_iterator<char>());
    proBuffer.push_back('\0');

    doc.parse<0>(&proBuffer[0]);
    proj_root = doc.first_node("Project_List");

    Project* newPro;

    for (rapidxml::xml_node<> * proNode = proj_root->first_node("Project"); proNode; proNode = proNode->next_sibling("Project"))
    {
        newPro = new Project();
        newPro->setOwner(proNode->first_attribute("owner")->value());
        newPro->setProjectName(proNode->first_attribute("name")->value());

        for (rapidxml::xml_node<> * stuNode = proNode->first_node(); stuNode; stuNode = stuNode->next_sibling())
        {
            string comp = stuNode->name();

            if(comp.compare("Description") == 0)
            {
                newPro->setProjectDescription(stuNode->value());
            }
            else if(comp.compare("Student_List") == 0)
            {
                vector<string> sList;
                for (rapidxml::xml_node<> * lNode = stuNode->first_node("Student"); lNode; lNode = lNode->next_sibling("Student"))
                {
                    sList.push_back(lNode->value());
                }

                newPro->setStudents(sList);
            }
            else if(comp.compare("Qualification_List") == 0)
            {
                vector<pair<int, int>> qList;
                for (rapidxml::xml_node<> * lNode = stuNode->first_node("Qualification"); lNode; lNode = lNode->next_sibling("Qualification"))
                {
                    qList.push_back(make_pair<int, int>(std::atoi(lNode->first_attribute("id")->value()), std::atoi(lNode->value())));
                }

                newPro->setQualifications(qList);
            }
        }
    }

    _pList->push_back(newPro);
}

void SimpleFileStorage::getQualificationList(vector<Qualification *> *_qList)
{
    ifstream temp(qualFile);

    if (!temp.is_open())
    {
        cout << "ERROR: Qualifications_List.xml non-existant" << endl;
        return;
    }

    vector<char> qualBuffer;
    qualBuffer = vector<char>(istreambuf_iterator<char>(temp), istreambuf_iterator<char>());
    qualBuffer.push_back('\0');

    doc.parse<0>(&qualBuffer[0]);
    root_node = doc.first_node("Qualification_List");

    Qualification* newQual;

    for (rapidxml::xml_node<> * qualNode = root_node->first_node("Qualification"); qualNode; qualNode = qualNode->next_sibling())
    {
        newQual = new Qualification();
        int id = 0, type = 0, range = 0, value = 0;

        id = std::atoi(qualNode->first_attribute("id")->value());

        for (rapidxml::xml_node<> * attriNode = qualNode->first_node(); attriNode; attriNode = attriNode->next_sibling())
        {
            string _comp = attriNode->name();

            if (_comp.compare("PersonalDescription") == 0){
                newQual->setPersonalDescription(attriNode->value());
            }
            else if (_comp.compare("DesiredDescription") == 0){
                newQual->setDesiredDescription(attriNode->value());
            }
            else if (_comp.compare("AdminDescription") == 0){
                newQual->setAdminDescription(attriNode->value());
            }
            else if (_comp.compare("Type") == 0){
                type = typeMap.find(attriNode->value())->second;
            }
            else if (_comp.compare("Range") == 0){
                range = std::atoi(attriNode->value());
            }
            else if (_comp.compare("Value") == 0){
                value = std::atoi(attriNode->value());
            }
        }

        newQual->setQVals(id, type, range, value);

        _qList->push_back(newQual);
    }

    root_node = 0;
    temp.close();
}












int SimpleFileStorage::profileExists(string _username)
{
    for (rapidxml::xml_node<> * stuNode = prof_root->first_node("Admin"); stuNode; stuNode = stuNode->next_sibling())
    {
        if (_username.compare(stuNode->first_attribute("name")->value()) == 0)
        {
            return -1;
        }
    }
    for (rapidxml::xml_node<> * stuNode = prof_root->first_node("Student"); stuNode; stuNode = stuNode->next_sibling())
	{
		if (_username.compare(stuNode->first_attribute("name")->value()) == 0)
		{
            return 1;
		}
	}
    return 0;
}

void SimpleFileStorage::algorithmIntelligence(vector<ProfileEntity*>&)
{

}













//Private

void SimpleFileStorage::reloadXMLFile(int _which, int _flag) //0 = profile, 1 = project
{
	if (_which == 0 && isProfileModified){
		ifstream profileStream;
		if (!profileStream.is_open()){
			profileStream.open(profileFile);
			if (!profileStream.is_open()){				//make storage file if non-existant
				ofstream newFile(profileFile, ios::app);
				newFile.close();
				profileStream.open(profileFile);
			}
		}

		profileBuffer = vector<char>(istreambuf_iterator<char>(profileStream), istreambuf_iterator<char>());
		profileBuffer.push_back('\0');

		profileStream.close();
		isProfileModified = false;

		if (_flag == 0){
			doc.parse<0>(&profileBuffer[0]);
		}
		else{
			doc.parse<rapidxml::parse_no_data_nodes>(&profileBuffer[0]);
		}
		
		prof_root = doc.first_node("Profile_List");
	}
	else if (_which == 1 && isProjectModified){
		ifstream projectStream;
		if (!projectStream.is_open()){
			projectStream.open(projectFile);
			if (!projectStream.is_open()){				//make storage file if non-existant
				ofstream newFile(projectFile, ios::app);
				newFile.close();
				projectStream.open(projectFile);
			}
		}

		projectBuffer = vector<char>(istreambuf_iterator<char>(projectStream), istreambuf_iterator<char>());
		projectBuffer.push_back('\0');

		projectStream.close();
		isProjectModified = false;

		doc.parse<0>(&projectBuffer[0]);
		proj_root = doc.first_node("Project_List");
	}
}
