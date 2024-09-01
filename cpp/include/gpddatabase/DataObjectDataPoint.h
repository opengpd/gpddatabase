#ifndef DATAOBJECTDATAPOINT_H
#define DATAOBJECTDATAPOINT_H

#include "PythonObject.h"

#include <string>
#include <vector>
#include <memory>

#include "DataObjectUncertaintySet.h"
#include "DataObjectKinematicBin.h"
#include "DataObjectReplicaSet.h"

namespace gpddatabase{

class DataObjectDataPoint : public PythonObject {

public:

    DataObjectDataPoint(PyObject* pyObject);

    std::string get_data_set_label();

    std::vector<std::string> get_observables_names();
    std::vector<std::string> get_observables_units();
    std::vector<double> get_observables_values();
    std::shared_ptr<DataObjectUncertaintySet> get_observables_stat_uncertainties();
    std::shared_ptr<DataObjectUncertaintySet> get_observables_sys_uncertainties();
    std::vector<std::string> get_observables_sys_uncertainties_contribution_labels();
    std::vector<std::shared_ptr<DataObjectUncertaintySet> > get_observables_sys_uncertainties_contribution();
    std::shared_ptr<DataObjectUncertaintySet> get_observables_norm_uncertainties();
    std::vector<std::string> get_observables_norm_uncertainties_contribution_labels();
    std::vector<std::shared_ptr<DataObjectUncertaintySet> > get_observables_norm_uncertainties_contribution();
    std::vector<std::shared_ptr<DataObjectReplicaSet> > get_observables_replicas();

    std::vector<std::string> get_kinematics_names();
    std::vector<std::string> get_kinematics_units();
    std::vector<double> get_kinematics_values();
    std::shared_ptr<DataObjectUncertaintySet> get_kinematics_uncertainties();
    std::vector<std::shared_ptr<DataObjectKinematicBin> > get_kinematics_bins();
    std::vector<std::shared_ptr<DataObjectReplicaSet> > get_kinematics_replicas();
};

};

#endif
