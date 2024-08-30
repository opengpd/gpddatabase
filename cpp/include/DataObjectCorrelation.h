#ifndef DATAOBJECTCORRELATION_H
#define DATAOBJECTCORRELATION_H

#include "PythonObject.h"

#include <string>
#include <map>
#include <vector>

class DataObjectCorrelation : public PythonObject {

public:

    DataObjectCorrelation(PyObject* pyObject);

    std::map<std::string, std::vector<std::vector<double> > > get_correlation_matrices();
    std::vector<std::string> get_correlation_matrix_labels();
    std::vector<std::vector<double> > get_correlation_matrix(const std::string& label);
};

#endif