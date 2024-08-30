#include "../include/DataObjectCorrelation.h"

#include <iostream>

#include "../include/Utility.h"

namespace gpddatabase{

DataObjectCorrelation::DataObjectCorrelation(PyObject* pyObject) : PythonObject(pyObject){
}

std::map<std::string, std::vector<std::vector<double> > > DataObjectCorrelation::get_correlation_matrices(){
    return Utility::PyDictToMapMatrix(Utility::executeFunction(m_pPyObject, "get_correlation_matrices"));
}

std::vector<std::string> DataObjectCorrelation::get_correlation_matrix_labels(){
    return Utility::PyListToVectorString(Utility::executeFunction(m_pPyObject, "get_correlation_matrix_labels"));
}

std::vector<std::vector<double> > DataObjectCorrelation::get_correlation_matrix(const std::string& label){

	PyObject* pArgs = PyTuple_Pack(1, PyUnicode_FromString(label.c_str()));
	std::vector<std::vector<double> > result = Utility::NumPyMatrixToMatrix(Utility::executeFunction(m_pPyObject, "get_correlation_matrix", pArgs));
	Py_DECREF(pArgs);

	return result;
}

};