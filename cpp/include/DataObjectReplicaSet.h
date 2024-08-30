#ifndef DATAOBJECTREPLICASET_H
#define DATAOBJECTREPLICASET_H

#include "PythonObject.h"

#include <vector>

class DataObjectReplicaSet : public PythonObject {

public:

    DataObjectReplicaSet(PyObject* pyObject);

    std::vector<double> get_values();
};

#endif