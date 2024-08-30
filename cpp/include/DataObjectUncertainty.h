#ifndef DATAOBJECTUNCERTAINTY_H
#define DATAOBJECTUNCERTAINTY_H

#include "PythonObject.h"

class DataObjectUncertainty : public PythonObject {

public:

    DataObjectUncertainty(PyObject* pyObject);

    double get_unc_lower();
    double get_unc_upper();
    bool is_asymmetric();
    double get_unc();
};

#endif