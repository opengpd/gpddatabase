#include "../include/gpddatabase/DataObject.h"

#include <iostream>

#include "../include/gpddatabase/Utility.h"

namespace gpddatabase{

DataObject::DataObject(PyObject* pyObject) : PythonObject(pyObject){
}

std::shared_ptr<DataObjectUUID> DataObject::get_uuid(){
    return std::shared_ptr<DataObjectUUID>(new DataObjectUUID(utility::executeFunction(m_pPyObject, "get_uuid")));
}

std::shared_ptr<DataObjectGeneralInfo> DataObject::get_general_info(){
    return std::shared_ptr<DataObjectGeneralInfo>(new DataObjectGeneralInfo(utility::executeFunction(m_pPyObject, "get_general_info")));    
}

std::shared_ptr<DataObjectCorrelation> DataObject::get_correlation(){
    return std::shared_ptr<DataObjectCorrelation>(new DataObjectCorrelation(utility::executeFunction(m_pPyObject, "get_correlation")));    
}

std::shared_ptr<DataObjectData> DataObject::get_data(){
    return std::shared_ptr<DataObjectData>(new DataObjectData(utility::executeFunction(m_pPyObject, "get_data")));    
}

};