#include "StorageObject.h"


StorageObject::StorageObject()
{
    typeMap[0] = "slide_range";
    typeMap[1] = "list_range";
    typeMap[2] = "true_range";
    typeMap[3] = "grade";

    //typeMap.insert(pair<string, Qual_Types>("slide_range", slide_range));
    //typeMap.insert(pair<string, Qual_Types>("list_range", list_range));
    //typeMap.insert(pair<string, Qual_Types>("true_false", true_false));
    //typeMap.insert(pair<string, Qual_Types>("grade", grade));
}


StorageObject::~StorageObject()
{

}
