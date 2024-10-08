#include "../include/gpddatabase/DataObjectKinematicBin.h"

#include <iostream>

#include "../include/gpddatabase/Utility.h"

namespace gpddatabase{

DataObjectKinematicBin::DataObjectKinematicBin(PyObject* pyObject) : PythonObject(pyObject){
}

double DataObjectKinematicBin::get_min(){
    return utility::PyObjectToDouble(utility::executeFunction(m_pPyObject, "get_min"));
}

double DataObjectKinematicBin::get_max(){
    return utility::PyObjectToDouble(utility::executeFunction(m_pPyObject, "get_max"));
}

};