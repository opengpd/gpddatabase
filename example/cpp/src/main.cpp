#include <gpddatabase/ExclusiveDatabase.h>

#include <iostream>

using namespace gpddatabase;

int main() {

    // make a pointer to the database
    ExclusiveDatabase* db = ExclusiveDatabase::getInstance();

    // print availible uuids
    std::vector<std::string> uuids = db->get_uuids();
    for(const auto& uuid : uuids) std::cout << uuid << std::endl;

    // load a given datafile
    std::shared_ptr<DataObject> ob = db->get_data_object("9j7gof4d");

    // =================================

    // make a pointer to general information (metadata)
    std::shared_ptr<DataObjectGeneralInfo> metadata = ob->get_general_info();

    // print:

    // date of insertion
    std::tm date = metadata->get_date();

    std::cout << (date.tm_year + 1900) << "-"
              << (date.tm_mon + 1) << "-"
              << date.tm_mday << std::endl;

    // data type
    std::cout << metadata->get_data_type() << std::endl;

    // check if pseudodata
    std::cout << metadata->get_pseudodata() << std::endl;

    // collaboration
    std::cout << metadata->get_collaboration() << std::endl;

    // reference
    std::cout << metadata->get_reference() << std::endl;

    // conditions
    std::map<std::string, std::any> conditions = metadata->get_conditions();

    for(const auto& pair : conditions) {
        if(pair.second.type() == typeid(double)){
            std::cout << pair.first << ": " << std::any_cast<double>(pair.second) << std::endl;
        }
        else if(pair.second.type() == typeid(std::string)){
            std::cout << pair.first << ": " << std::any_cast<std::string>(pair.second) << std::endl;
        }
        else{
            std::cerr << "error: " << __func__ << ": unknown type of std::any" << std::endl;
            exit(0);
        }
    }

    // comment
    std::cout << metadata->get_comment() << std::endl;

    // =================================

    // make a pointer to data
    std::shared_ptr<DataObjectData> data = ob->get_data();

    // print labels of availible datasets
    std::vector<std::string> dataSetLabels = data->get_data_set_labels();
    for(const auto& dataSetLabel : dataSetLabels) std::cout << dataSetLabel << std::endl;

    // make a pointer to a given data set
    std::shared_ptr<DataObjectDataSet> data_set = data->get_data_set("Q2_dep");

    // print the number of data points
    std::cout << data_set->get_number_of_data_points() << std::endl;

    // make a pointer to the first point
    std::shared_ptr<DataObjectDataPoint> point = data_set->get_data_point(0);

    // print:

    // names of kinematic variables
    std::vector<std::string> kinNames = point->get_kinematics_names();
    for(const auto& kinName : kinNames) std::cout << kinName << std::endl;

    // units associated to kinematic variables
    std::vector<std::string> kinUnits = point->get_kinematics_units();
    for(const auto& kinUnit : kinUnits) std::cout << kinUnit << std::endl;

    // values of kinematic variables
    std::vector<double> kinValues = point->get_kinematics_values();
    for(const auto& kinValue : kinValues) std::cout << kinValue << std::endl;

    // make a pointer to a set of statistical uncertainties related to kinematic variables
    std::shared_ptr<DataObjectUncertaintySet> kinUnc = point->get_kinematics_uncertainties();
    // print the number of uncertainties stored in the set
    // (here the same as the number of kinematic variables)
    std::cout << kinUnc->get_number_of_uncertainties() << std::endl;
    // print the correlation matrix between the uncertainties
    // std::vector<std::vector<double> > corrMatrix = kinUnc->get_correlation_matrix();
    // for (const auto& v1 : corrMatrix){
    //     for (const auto& v2 : v1){
    //         std::cout << v2 << std::endl;
    //     }
    // }
    // make a pointer to the first uncertainty in the set
    // (here corresponding to the first kinematic variable)
    std::shared_ptr<DataObjectUncertainty> kinUnc0 = kinUnc->get_uncertainty(0);
    // print info if uncertainty asymmetric
    std::cout << kinUnc0->is_asymmetric() << std::endl;
    // print uncertainty (will trigger error if uncertainty asymmetric)
    std::cout << kinUnc0->get_unc() << std::endl;
    // print 'lower' value of uncertainty
    std::cout << kinUnc0->get_unc_lower() << std::endl;
    // print 'upper' value of uncertainty
    std::cout << kinUnc0->get_unc_upper() << std::endl;

    // make a pointer to bins of kinematic variables
    std::vector<std::shared_ptr<DataObjectKinematicBin> > kinBins = point->get_kinematics_bins();
    // print bin limits corresponding to the first kinematic variable
    std::cout << "min:" << kinBins[0]->get_min() << " max: " << kinBins[0]->get_max() << std::endl;

    // make a pointer to a set of values of kinematic variables given by replicas
    // used in the related analysis
    std::vector<std::shared_ptr<DataObjectReplicaSet> > kinReplicas = point->get_kinematics_replicas();
    // print values corresponding to the first kinematic variable
    for(const auto& kinReplicaValue : kinReplicas[0]->get_values()) std::cout << kinReplicaValue << std::endl;

    // print:

    // names of observables
    std::vector<std::string> obsNames = point->get_observables_names();
    for(const auto& obsName : obsNames) std::cout << obsName << std::endl;

    // units of observables
    std::vector<std::string> obsUnits = point->get_observables_units();
    for(const auto& obsUnit : obsUnits) std::cout << obsUnit << std::endl;

    // values of observables
    std::vector<double> obsValues = point->get_observables_values();
    for(const auto& obsValue : obsValues) std::cout << obsValue << std::endl;

    // make a pointer to a set of statistical uncertainties related to observables
    // use this set as demonstrated for kinematics
    std::shared_ptr<DataObjectUncertaintySet> obsStatUnc = point->get_observables_stat_uncertainties();

    // make a pointer to a set of systematic uncertainties related to observables
    // use this set as demonstrated for kinematics
    std::shared_ptr<DataObjectUncertaintySet> obsSysUnc = point->get_observables_sys_uncertainties();

    // make a pointer to a set of normalisation uncertainties related to observables
    // use this set as demonstrated for kinematics
    std::shared_ptr<DataObjectUncertaintySet> obsNormUnc = point->get_observables_norm_uncertainties();

    // labels of contributions to systematic uncertainties of observables
    std::vector<std::string> obsSysUncLabels = point->get_observables_sys_uncertainties_contribution_labels();
    for(const auto& obsSysUncLabel : obsSysUncLabels) std::cout << obsSysUncLabel << std::endl;

    // make a pointer to a list of sets of contributions to systematic uncertainties
    // the lenght of this list corresponds to the number of contributions
    std::vector<std::shared_ptr<DataObjectUncertaintySet> > obsSysUncContrib = point->get_observables_sys_uncertainties_contribution();
    // print label and corresponding value of systematic uncertainty
    // corresponding to the first observable and the second contribution
    std::cout << 
        point->get_observables_sys_uncertainties_contribution_labels()[1] << ": " << 
        obsSysUncContrib[0]->get_uncertainty(1)->get_unc() << 
    std::endl;

    // labels of contributions to normalisation uncertainties of observables
    std::vector<std::string> obsNormUncLabels = point->get_observables_norm_uncertainties_contribution_labels();
    for(const auto& obsNormUncLabel : obsNormUncLabels) std::cout << obsNormUncLabel << std::endl;

    // make a pointer to a list of sets of contributions to normalisation uncertainties
    // the lenght of this list corresponds to the number of contributions
    std::vector<std::shared_ptr<DataObjectUncertaintySet> > obsNormUncContrib = point->get_observables_norm_uncertainties_contribution();

    // make a pointer to a set of values of observables given by replicas
    // used in the related analysis
    // use this set as demonstrated for kinematics
    std::vector<std::shared_ptr<DataObjectReplicaSet> > obsReplicas = point->get_observables_replicas();

    return 0;
}
