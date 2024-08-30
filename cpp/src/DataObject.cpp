#include "../include/DataObject.h"

#include <iostream>

#include "../include/Utility.h"

namespace gpddatabase{

DataObject::DataObject(PyObject* pyObject) : PythonObject(pyObject){
}

std::shared_ptr<DataObjectUUID> DataObject::get_uuid(){
    return std::shared_ptr<DataObjectUUID>(new DataObjectUUID(Utility::executeFunction(m_pPyObject, "get_uuid")));
}

std::shared_ptr<DataObjectGeneralInfo> DataObject::get_general_info(){
    return std::shared_ptr<DataObjectGeneralInfo>(new DataObjectGeneralInfo(Utility::executeFunction(m_pPyObject, "get_general_info")));    
}

std::shared_ptr<DataObjectCorrelation> DataObject::get_correlation(){
    return std::shared_ptr<DataObjectCorrelation>(new DataObjectCorrelation(Utility::executeFunction(m_pPyObject, "get_correlation")));    
}

std::shared_ptr<DataObjectData> DataObject::get_data(){
    return std::shared_ptr<DataObjectData>(new DataObjectData(Utility::executeFunction(m_pPyObject, "get_data")));    
}

};