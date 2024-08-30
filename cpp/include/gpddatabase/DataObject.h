#ifndef DATAOBJECT_H
#define DATAOBJECT_H

#include <memory>

#include "gpddatabase/PythonObject.h"
#include "gpddatabase/DataObjectUUID.h"
#include "gpddatabase/DataObjectGeneralInfo.h"
#include "gpddatabase/DataObjectCorrelation.h"
#include "gpddatabase/DataObjectData.h"

namespace gpddatabase{

class DataObject : public PythonObject {

public:

    DataObject(PyObject* pyObject);

    std::shared_ptr<DataObjectUUID> get_uuid();
    std::shared_ptr<DataObjectGeneralInfo> get_general_info();
    std::shared_ptr<DataObjectCorrelation> get_correlation();
    std::shared_ptr<DataObjectData> get_data();
};

};

#endif