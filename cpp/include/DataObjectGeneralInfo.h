#ifndef DATAOBJECTGENERALINFO_H
#define DATAOBJECTGENERALINFO_H

#include "PythonObject.h"

#include <ctime>
#include <string>
#include <map>
#include <any>

namespace gpddatabase{

class DataObjectGeneralInfo : public PythonObject {

public:

    DataObjectGeneralInfo(PyObject* pyObject);

    std::tm get_date();
    std::string get_data_type();
    bool get_pseudodata();
    std::string get_collaboration();
    std::string get_reference();
    std::map<std::string, std::any> get_conditions();
    std::string get_comment();
};

};

#endif