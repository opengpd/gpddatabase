#include "../include/gpddatabase/DataObjectGeneralInfo.h"

#include <iostream>

#include "../include/gpddatabase/Utility.h"

namespace gpddatabase{

DataObjectGeneralInfo::DataObjectGeneralInfo(PyObject* pyObject) : PythonObject(pyObject){
}

std::tm DataObjectGeneralInfo::get_date(){
	return utility::PyObjectToDate(utility::executeFunction(m_pPyObject, "get_date"));
}

std::string DataObjectGeneralInfo::get_data_type(){
	return utility::PyObjectToString(utility::executeFunction(m_pPyObject, "get_data_type"));
}

bool DataObjectGeneralInfo::get_pseudodata(){
	return utility::PyObjectToBool(utility::executeFunction(m_pPyObject, "get_pseudodata"));
}

std::string DataObjectGeneralInfo::get_collaboration(){
	return utility::PyObjectToString(utility::executeFunction(m_pPyObject, "get_collaboration"));
}

std::string DataObjectGeneralInfo::get_reference(){
	return utility::PyObjectToString(utility::executeFunction(m_pPyObject, "get_reference"));
}

std::map<std::string, std::any> DataObjectGeneralInfo::get_conditions(){
	return utility::PyDictToMapAny(utility::executeFunction(m_pPyObject, "get_conditions"));
}

std::string DataObjectGeneralInfo::get_comment(){
	return utility::PyObjectToString(utility::executeFunction(m_pPyObject, "get_comment"));
}

};