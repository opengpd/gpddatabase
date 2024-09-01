#include "../include/gpddatabase/DataObjectUncertaintySet.h"

#include <iostream>

#include "../include/gpddatabase/Utility.h"

namespace gpddatabase{

DataObjectUncertaintySet::DataObjectUncertaintySet(PyObject* pyObject) : PythonObject(pyObject){
}

std::vector<std::shared_ptr<DataObjectUncertainty> > DataObjectUncertaintySet::get_uncertainties(){
    return utility::PyListToVectorPointer<DataObjectUncertainty>(utility::executeFunction(m_pPyObject, "get_uncertainties"));
}

std::vector<std::vector<double> > DataObjectUncertaintySet::get_correlation_matrix(){
    return utility::NumPyMatrixToMatrix(utility::executeFunction(m_pPyObject, "get_correlation_matrix"));
}

size_t DataObjectUncertaintySet::get_number_of_uncertainties(){
    return utility::PyObjectToInteger(utility::executeFunction(m_pPyObject, "get_number_of_uncertainties"));
}

std::shared_ptr<DataObjectUncertainty> DataObjectUncertaintySet::get_uncertainty(size_t i){

    PyObject* pArgs = PyTuple_Pack(1, PyLong_FromSize_t(i));
    PyObject* result = utility::executeFunction(m_pPyObject, "get_uncertainty", pArgs);
    Py_DECREF(pArgs);

    return std::shared_ptr<DataObjectUncertainty>(new DataObjectUncertainty(result));    
}

};