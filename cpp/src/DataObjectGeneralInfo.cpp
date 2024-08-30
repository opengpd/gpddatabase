#include "../include/DataObjectGeneralInfo.h"

#include <iostream>

#include "../include/Utility.h"

namespace gpddatabase{

DataObjectGeneralInfo::DataObjectGeneralInfo(PyObject* pyObject) : PythonObject(pyObject){
}

std::tm DataObjectGeneralInfo::get_date(){
	return Utility::PyObjectToDate(Utility::executeFunction(m_pPyObject, "get_date"));
}

std::string DataObjectGeneralInfo::get_data_type(){
	return Utility::PyObjectToString(Utility::executeFunction(m_pPyObject, "get_data_type"));
}

bool DataObjectGeneralInfo::get_pseudodata(){
	return Utility::PyObjectToBool(Utility::executeFunction(m_pPyObject, "get_pseudodata"));
}

std::string DataObjectGeneralInfo::get_collaboration(){
	return Utility::PyObjectToString(Utility::executeFunction(m_pPyObject, "get_collaboration"));
}

std::string DataObjectGeneralInfo::get_reference(){
	return Utility::PyObjectToString(Utility::executeFunction(m_pPyObject, "get_reference"));
}

std::map<std::string, std::any> DataObjectGeneralInfo::get_conditions(){
	return Utility::PyDictToMapAny(Utility::executeFunction(m_pPyObject, "get_conditions"));
}

std::string DataObjectGeneralInfo::get_comment(){
	return Utility::PyObjectToString(Utility::executeFunction(m_pPyObject, "get_comment"));
}

};