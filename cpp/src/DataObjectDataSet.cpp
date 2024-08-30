#include "../include/gpddatabase/DataObjectDataSet.h"

#include <iostream>

#include "../include/gpddatabase/Utility.h"

namespace gpddatabase{

DataObjectDataSet::DataObjectDataSet(PyObject* pyObject) : PythonObject(pyObject){
}

size_t DataObjectDataSet::get_number_of_data_points(){
	return utility::PyObjectToInteger(utility::executeFunction(m_pPyObject, "get_number_of_data_points"));
}

std::shared_ptr<DataObjectDataPoint> DataObjectDataSet::get_data_point(size_t i){

	PyObject* pArgs = PyTuple_Pack(1, PyLong_FromSize_t(i));
	PyObject* result = utility::executeFunction(m_pPyObject, "get_data_point", pArgs);
	Py_DECREF(pArgs);

	return std::shared_ptr<DataObjectDataPoint>(new DataObjectDataPoint(result));   
}

};