#include "../include/gpddatabase/ExclusiveDatabase.h"

#include <iostream>
#include <string>

#include "../include/gpddatabase/Utility.h"

namespace gpddatabase{

ExclusiveDatabase* ExclusiveDatabase::m_pInstance = nullptr;

ExclusiveDatabase* ExclusiveDatabase::getInstance(){

    if(m_pInstance == nullptr){
        m_pInstance = new ExclusiveDatabase();
    }

    return m_pInstance;
}

ExclusiveDatabase::ExclusiveDatabase() {

    //names
    const std::string moduleName = "gpd_database";
    const std::string className = "ExclusiveDatabase";

    //initialize the Python interpreter
    Py_Initialize();

    //add path
    PyObject* sysPath = PySys_GetObject("path");
    PyList_Append(sysPath, PyUnicode_FromString("."));
    PyList_Append(sysPath, PyUnicode_FromString("/usr/local/lib/python3.11/site-packages"));

    //load the module
    PyObject* pName = PyUnicode_DecodeFSDefault(moduleName.c_str());
    m_pPythonModule = PyImport_Import(pName);
    Py_DECREF(pName);

    //load class
    if (m_pPythonModule != nullptr) {

        //get the class from the module
        m_pPythonClass = PyObject_GetAttrString(m_pPythonModule, className.c_str());

        if (m_pPythonClass && PyCallable_Check(m_pPythonClass)) {

            //create an instance of the class
            m_pPythonInstance = PyObject_CallObject(m_pPythonClass, nullptr);

            if (!m_pPythonInstance) {
                PyErr_Print();
                std::cerr << "error:" << __func__ << ": failed to create instance of class" << std::endl;
                exit(0);
            }
        } else {
            if (PyErr_Occurred()) PyErr_Print();
            std::cerr << "error:" << __func__ << ": cannot find class " << className << std::endl;
            exit(0);
        }
    } else {
        PyErr_Print();
        std::cerr << "error:" << __func__ << ": failed to load module " << moduleName << std::endl;
        exit(0);
    }
}

ExclusiveDatabase::~ExclusiveDatabase() {

    Py_XDECREF(m_pPythonInstance);
    Py_XDECREF(m_pPythonClass);
    Py_XDECREF(m_pPythonModule);

    Py_Finalize();
}

std::vector<std::string> ExclusiveDatabase::get_uuids(){
    return  utility::PyListToVectorString(utility::executeFunction(m_pPythonInstance, "get_uuids"));
}

std::shared_ptr<DataObject> ExclusiveDatabase::get_data_object(const std::string& uuid){

    PyObject* pArgs = PyTuple_Pack(1, PyUnicode_FromString(uuid.c_str()));
    DataObject* result = new DataObject(utility::executeFunction(m_pPythonInstance, "get_data_object", pArgs));
    Py_DECREF(pArgs);

    return std::shared_ptr<DataObject>(result);
}

};