#include "../include/DataObjectDataSet.h"

#include <iostream>

#include "../include/Utility.h"

DataObjectDataSet::DataObjectDataSet(PyObject* pyObject) : PythonObject(pyObject){
}

size_t DataObjectDataSet::get_number_of_data_points(){
	return Utility::PyObjectToInteger(Utility::executeFunction(m_pPyObject, "get_number_of_data_points"));
}

std::shared_ptr<DataObjectDataPoint> DataObjectDataSet::get_data_point(size_t i){

	PyObject* pArgs = PyTuple_Pack(1, PyLong_FromSize_t(i));
	PyObject* result = Utility::executeFunction(m_pPyObject, "get_data_point", pArgs);
	Py_DECREF(pArgs);

	return std::shared_ptr<DataObjectDataPoint>(new DataObjectDataPoint(result));   
}