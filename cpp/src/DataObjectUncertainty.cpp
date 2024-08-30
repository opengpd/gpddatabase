#include "../include/DataObjectUncertainty.h"

#include <iostream>

#include "../include/Utility.h"

DataObjectUncertainty::DataObjectUncertainty(PyObject* pyObject) : PythonObject(pyObject){
}

double DataObjectUncertainty::get_unc_lower(){
    return Utility::PyObjectToDouble(Utility::executeFunction(m_pPyObject, "get_unc_lower"));
}

double DataObjectUncertainty::get_unc_upper(){
    return Utility::PyObjectToDouble(Utility::executeFunction(m_pPyObject, "get_unc_upper"));
}

bool DataObjectUncertainty::is_asymmetric(){
    return Utility::PyObjectToBool(Utility::executeFunction(m_pPyObject, "is_asymmetric"));
}

double DataObjectUncertainty::get_unc(){
    return Utility::PyObjectToDouble(Utility::executeFunction(m_pPyObject, "get_unc"));
}