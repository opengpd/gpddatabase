#ifndef DATAOBJECTDATASET_H
#define DATAOBJECTDATASET_H

#include "PythonObject.h"

#include <memory>

#include "DataObjectDataPoint.h"

class DataObjectDataSet : public PythonObject {

public:

    DataObjectDataSet(PyObject* pyObject);

    size_t get_number_of_data_points();
    std::shared_ptr<DataObjectDataPoint> get_data_point(size_t i);
};

#endif