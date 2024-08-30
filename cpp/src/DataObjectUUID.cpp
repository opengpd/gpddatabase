#include "../include/gpddatabase/DataObjectUUID.h"

#include <iostream>

#include "../include/gpddatabase/Utility.h"

namespace gpddatabase{

DataObjectUUID::DataObjectUUID(PyObject* pyObject) : PythonObject(pyObject){
}

std::string DataObjectUUID::get_uuid(){
	return Utility::PyObjectToString(Utility::executeFunction(m_pPyObject, "get_uuid"));
}

};