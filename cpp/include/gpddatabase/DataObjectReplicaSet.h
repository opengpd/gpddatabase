#ifndef DATAOBJECTREPLICASET_H
#define DATAOBJECTREPLICASET_H

#include "PythonObject.h"

#include <vector>

namespace gpddatabase{

class DataObjectReplicaSet : public PythonObject {

public:

    DataObjectReplicaSet(PyObject* pyObject);

    std::vector<double> get_values();
};

};

#endif