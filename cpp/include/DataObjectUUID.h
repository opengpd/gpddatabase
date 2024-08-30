#ifndef DATAOBJECTUUID_H
#define DATAOBJECTUUID_H

#include "PythonObject.h"

#include <string>

class DataObjectUUID : public PythonObject {

public:

    DataObjectUUID(PyObject* pyObject);

    std::string get_uuid();
};

#endif