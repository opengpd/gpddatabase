#ifndef DATAOBJECTUNCERTAINTYSET_H
#define DATAOBJECTUNCERTAINTYSET_H

#include "PythonObject.h"

#include <string>
#include <vector>
#include <memory>

#include "DataObjectUncertainty.h"

namespace gpddatabase{

class DataObjectUncertaintySet : public PythonObject {

public:

    DataObjectUncertaintySet(PyObject* pyObject);

    std::vector<std::shared_ptr<DataObjectUncertainty> > get_uncertainties();
    std::vector<std::vector<double> > get_correlation_matrix();
    size_t get_number_of_uncertainties();
    std::shared_ptr<DataObjectUncertainty> get_uncertainty(size_t i);
};

};

#endif