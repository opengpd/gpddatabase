#ifndef EXCLUSIVE_DATABASE_H
#define EXCLUSIVE_DATABASE_H

#include <Python.h>
#include <vector>
#include <string>
#include <memory>

#include "DataObject.h"

namespace gpddatabase{

class ExclusiveDatabase {

public:

	static ExclusiveDatabase* getInstance();

    ~ExclusiveDatabase();

    std::vector<std::string> get_uuids();
    std::shared_ptr<DataObject> get_data_object(const std::string& uuid);

private:

	static ExclusiveDatabase* m_pInstance;

    ExclusiveDatabase();

    PyObject* m_pPythonModule; 
    PyObject* m_pPythonClass; 
    PyObject* m_pPythonInstance;
};

};

#endif