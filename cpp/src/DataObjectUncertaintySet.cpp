#include "../include/DataObjectUncertaintySet.h"

#include <iostream>

#include "../include/Utility.h"

namespace gpddatabase{

DataObjectUncertaintySet::DataObjectUncertaintySet(PyObject* pyObject) : PythonObject(pyObject){
}

std::vector<std::shared_ptr<DataObjectUncertainty> > DataObjectUncertaintySet::get_uncertainties(){
    return Utility::PyListToVectorPointer<DataObjectUncertainty>(Utility::executeFunction(m_pPyObject, "get_uncertainties"));
}

std::string DataObjectUncertaintySet::get_correlation_matrix(){
    return Utility::PyObjectToString(Utility::executeFunction(m_pPyObject, "get_correlation_matrix"));
}

size_t DataObjectUncertaintySet::get_number_of_uncertainties(){
    return Utility::PyObjectToInteger(Utility::executeFunction(m_pPyObject, "get_number_of_uncertainties"));
}

std::shared_ptr<DataObjectUncertainty> DataObjectUncertaintySet::get_uncertainty(size_t i){

    PyObject* pArgs = PyTuple_Pack(1, PyLong_FromSize_t(i));
    PyObject* result = Utility::executeFunction(m_pPyObject, "get_uncertainty", pArgs);
    Py_DECREF(pArgs);

    return std::shared_ptr<DataObjectUncertainty>(new DataObjectUncertainty(result));    
}

};