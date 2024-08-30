#ifndef DATAOBJECTDATA_H
#define DATAOBJECTDATA_H

#include "PythonObject.h"

#include <string>
#include <map>
#include <vector>
#include <memory>

#include "DataObjectDataSet.h"

namespace gpddatabase{

class DataObjectData : public PythonObject {

public:

    DataObjectData(PyObject* pyObject);

    std::map<std::string, std::shared_ptr<DataObjectDataSet> > get_data_sets();
    std::vector<std::string> get_data_set_labels();
    std::shared_ptr<DataObjectDataSet> get_data_set(const std::string& label);
};

};

#endif