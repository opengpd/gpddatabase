#include "../include/gpddatabase/DataObjectReplicaSet.h"

#include <iostream>

#include "../include/gpddatabase/Utility.h"

namespace gpddatabase{

DataObjectReplicaSet::DataObjectReplicaSet(PyObject* pyObject) : PythonObject(pyObject){
}

std::vector<double> DataObjectReplicaSet::get_values(){
    return utility::PyListToVectorDouble(utility::executeFunction(m_pPyObject, "get_values"));
}

};