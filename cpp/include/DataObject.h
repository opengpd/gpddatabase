#ifndef DATAOBJECT_H
#define DATAOBJECT_H

#include <memory>

#include "PythonObject.h"
#include "DataObjectUUID.h"
#include "DataObjectGeneralInfo.h"
#include "DataObjectCorrelation.h"
#include "DataObjectData.h"

class DataObject : public PythonObject {

public:

    DataObject(PyObject* pyObject);

    std::shared_ptr<DataObjectUUID> get_uuid();
    std::shared_ptr<DataObjectGeneralInfo> get_general_info();
    std::shared_ptr<DataObjectCorrelation> get_correlation();
    std::shared_ptr<DataObjectData> get_data();
};

#endif