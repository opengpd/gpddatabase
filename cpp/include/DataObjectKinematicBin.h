#ifndef DATAOBJECTKINEMATICBIN_H
#define DATAOBJECTKINEMATICBIN_H

#include "PythonObject.h"

namespace gpddatabase{

class DataObjectKinematicBin : public PythonObject {

public:

    DataObjectKinematicBin(PyObject* pyObject);

    double get_min();
    double get_max();
};

};

#endif