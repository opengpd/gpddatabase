#include "../include/gpddatabase/DataObjectCorrelation.h"

#include <iostream>

#include "../include/gpddatabase/Utility.h"

namespace gpddatabase{

DataObjectCorrelation::DataObjectCorrelation(PyObject* pyObject) : PythonObject(pyObject){
}

std::map<std::string, std::vector<std::vector<double> > > DataObjectCorrelation::get_correlation_matrices(){
    return utility::PyDictToMapMatrix(utility::executeFunction(m_pPyObject, "get_correlation_matrices"));
}

std::vector<std::string> DataObjectCorrelation::get_correlation_matrix_labels(){
    return utility::PyListToVectorString(utility::executeFunction(m_pPyObject, "get_correlation_matrix_labels"));
}

std::vector<std::vector<double> > DataObjectCorrelation::get_correlation_matrix(const std::string& label){

	PyObject* pArgs = PyTuple_Pack(1, PyUnicode_FromString(label.c_str()));
	std::vector<std::vector<double> > result = utility::NumPyMatrixToMatrix(utility::executeFunction(m_pPyObject, "get_correlation_matrix", pArgs));
	Py_DECREF(pArgs);

	return result;
}

};