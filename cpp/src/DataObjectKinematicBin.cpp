#include "../include/DataObjectKinematicBin.h"

#include <iostream>

#include "../include/Utility.h"

DataObjectKinematicBin::DataObjectKinematicBin(PyObject* pyObject) : PythonObject(pyObject){
}

double DataObjectKinematicBin::get_min(){
    return Utility::PyObjectToDouble(Utility::executeFunction(m_pPyObject, "get_min"));
}

double DataObjectKinematicBin::get_max(){
    return Utility::PyObjectToDouble(Utility::executeFunction(m_pPyObject, "get_max"));
}