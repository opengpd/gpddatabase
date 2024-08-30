#include "../include/gpddatabase/DataObjectDataPoint.h"

#include <iostream>

#include "../include/gpddatabase/Utility.h"

namespace gpddatabase{

DataObjectDataPoint::DataObjectDataPoint(PyObject* pyObject) : PythonObject(pyObject){
}

std::string DataObjectDataPoint::get_data_set_label(){
	return utility::PyObjectToString(utility::executeFunction(m_pPyObject, "get_data_set_label"));
}

std::vector<std::string> DataObjectDataPoint::get_observables_names(){
	return utility::PyListToVectorString(utility::executeFunction(m_pPyObject, "get_observables_names"));
}

std::vector<std::string> DataObjectDataPoint::get_observables_units(){
	return utility::PyListToVectorString(utility::executeFunction(m_pPyObject, "get_observables_units"));
}

std::vector<double> DataObjectDataPoint::get_observables_values(){
	return utility::PyListToVectorDouble(utility::executeFunction(m_pPyObject, "get_observables_values"));
}

std::shared_ptr<DataObjectUncertaintySet> DataObjectDataPoint::get_observables_stat_uncertainties(){
	return std::shared_ptr<DataObjectUncertaintySet>(new DataObjectUncertaintySet(utility::executeFunction(m_pPyObject, "get_observables_stat_uncertainties")));  
}

std::shared_ptr<DataObjectUncertaintySet> DataObjectDataPoint::get_observables_sys_uncertainties(){
	return std::shared_ptr<DataObjectUncertaintySet>(new DataObjectUncertaintySet(utility::executeFunction(m_pPyObject, "get_observables_sys_uncertainties")));  
}

std::vector<std::string> DataObjectDataPoint::get_observables_sys_uncertainties_contribution_labels(){
	return utility::PyListToVectorString(utility::executeFunction(m_pPyObject, "get_observables_sys_uncertainties_contribution_labels"));	
}

std::vector<std::shared_ptr<DataObjectUncertaintySet> > DataObjectDataPoint::get_observables_sys_uncertainties_contribution(){
	return utility::PyListToVectorPointer<DataObjectUncertaintySet>(utility::executeFunction(m_pPyObject, "get_observables_sys_uncertainties_contribution"));
}

std::shared_ptr<DataObjectUncertaintySet> DataObjectDataPoint::get_observables_norm_uncertainties(){
	return std::shared_ptr<DataObjectUncertaintySet>(new DataObjectUncertaintySet(utility::executeFunction(m_pPyObject, "get_observables_norm_uncertainties")));
}

std::vector<std::string> DataObjectDataPoint::get_observables_norm_uncertainties_contribution_labels(){
	return utility::PyListToVectorString(utility::executeFunction(m_pPyObject, "get_observables_norm_uncertainties_contribution_labels"));
}

std::vector<std::shared_ptr<DataObjectUncertaintySet> > DataObjectDataPoint::get_observables_norm_uncertainties_contribution(){
	return utility::PyListToVectorPointer<DataObjectUncertaintySet>(utility::executeFunction(m_pPyObject, "get_observables_norm_uncertainties_contribution"));
}

std::vector<std::shared_ptr<DataObjectReplicaSet> > DataObjectDataPoint::get_observables_replicas(){
	return utility::PyListToVectorPointer<DataObjectReplicaSet>(utility::executeFunction(m_pPyObject, "get_observables_replicas"));
}

std::vector<std::string> DataObjectDataPoint::get_kinematics_names(){
	return utility::PyListToVectorString(utility::executeFunction(m_pPyObject, "get_kinematics_names"));
}

std::vector<std::string> DataObjectDataPoint::kinematics_units(){
	return utility::PyListToVectorString(utility::executeFunction(m_pPyObject, "kinematics_units"));
}

std::vector<double> DataObjectDataPoint::get_kinematics_values(){
	return utility::PyListToVectorDouble(utility::executeFunction(m_pPyObject, "get_kinematics_values"));
}

std::shared_ptr<DataObjectUncertaintySet> DataObjectDataPoint::get_kinematics_uncertainties(){
	return std::shared_ptr<DataObjectUncertaintySet>(new DataObjectUncertaintySet(utility::executeFunction(m_pPyObject, "get_kinematics_uncertainties")));
}

std::vector<std::shared_ptr<DataObjectKinematicBin> > DataObjectDataPoint::get_kinematics_bins(){
	return utility::PyListToVectorPointer<DataObjectKinematicBin>(utility::executeFunction(m_pPyObject, "get_kinematics_bins"));	
}

std::vector<std::shared_ptr<DataObjectReplicaSet> > DataObjectDataPoint::get_kinematics_replicas(){
	return utility::PyListToVectorPointer<DataObjectReplicaSet>(utility::executeFunction(m_pPyObject, "get_kinematics_replicas"));
}

};
