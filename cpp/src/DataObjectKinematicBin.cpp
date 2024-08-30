#include "../include/gpddatabase/DataObjectKinematicBin.h"

#include <iostream>

#include "../include/gpddatabase/Utility.h"

namespace gpddatabase{

DataObjectKinematicBin::DataObjectKinematicBin(PyObject* pyObject) : PythonObject(pyObject){
}

double DataObjectKinematicBin::get_min(){
    return Utility::PyObjectToDouble(Utility::executeFunction(m_pPyObject, "get_min"));
}

double DataObjectKinematicBin::get_max(){
    return Utility::PyObjectToDouble(Utility::executeFunction(m_pPyObject, "get_max"));
}

};