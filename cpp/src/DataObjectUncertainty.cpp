#include "../include/gpddatabase/DataObjectUncertainty.h"

#include <iostream>

#include "../include/gpddatabase/Utility.h"

namespace gpddatabase{

DataObjectUncertainty::DataObjectUncertainty(PyObject* pyObject) : PythonObject(pyObject){
}

double DataObjectUncertainty::get_unc_lower(){
    return utility::PyObjectToDouble(utility::executeFunction(m_pPyObject, "get_unc_lower"));
}

double DataObjectUncertainty::get_unc_upper(){
    return utility::PyObjectToDouble(utility::executeFunction(m_pPyObject, "get_unc_upper"));
}

bool DataObjectUncertainty::is_asymmetric(){
    return utility::PyObjectToBool(utility::executeFunction(m_pPyObject, "is_asymmetric"));
}

double DataObjectUncertainty::get_unc(){
    return utility::PyObjectToDouble(utility::executeFunction(m_pPyObject, "get_unc"));
}

};