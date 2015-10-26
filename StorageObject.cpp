#include "StorageObject.h"


StorageObject::StorageObject()
{
	typeMap.insert(pair<string, Qual_Types>("slide_range", slide_range));
	typeMap.insert(pair<string, Qual_Types>("list_range", list_range));
	typeMap.insert(pair<string, Qual_Types>("true_false", true_false));
}


StorageObject::~StorageObject()
{
}

const vector<pair<string, qualLayout_4>>& StorageObject::getQualificationList()
{
	return qualList;
}