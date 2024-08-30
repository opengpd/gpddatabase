#include "../include/gpddatabase/DataObjectData.h"

#include <iostream>

#include "../include/gpddatabase/Utility.h"

namespace gpddatabase{

DataObjectData::DataObjectData(PyObject* pyObject) : PythonObject(pyObject){
}

std::map<std::string, std::shared_ptr<DataObjectDataSet> > DataObjectData::get_data_sets(){
    return utility::PyDictToMapPointer<DataObjectDataSet>(utility::executeFunction(m_pPyObject, "get_data_sets"));
}

std::vector<std::string> DataObjectData::get_data_set_labels(){
    return utility::PyListToVectorString(utility::executeFunction(m_pPyObject, "get_data_set_labels"));
}

std::shared_ptr<DataObjectDataSet> DataObjectData::get_data_set(const std::string& label){

	PyObject* pArgs = PyTuple_Pack(1, PyUnicode_FromString(label.c_str()));
	PyObject* result = utility::executeFunction(m_pPyObject, "get_data_set", pArgs);
	Py_DECREF(pArgs);

	return std::shared_ptr<DataObjectDataSet>(new DataObjectDataSet(result));    
}

};