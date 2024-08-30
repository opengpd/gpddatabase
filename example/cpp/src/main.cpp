#include <gpddatabase/ExclusiveDatabase.h>

#include <iostream>

using namespace gpddatabase;

int main() {
    // Create an instance of the Python class
    ExclusiveDatabase* exclusiveDatabase = ExclusiveDatabase::getInstance();

    std::vector<std::string> uuids = exclusiveDatabase->get_uuids();

    for(size_t i = 0; i < uuids.size(); i++){
        std::cout << uuids.at(i) << std::endl;
    }

    std::shared_ptr<DataObject> dataObject = exclusiveDatabase->get_data_object("9j7gof4d");

    std::cout << dataObject->get_uuid()->get_uuid() << std::endl;
    
    std::tm date = dataObject->get_general_info()->get_date();
       std::cout << "Converted date: " 
              << (date.tm_year + 1900) << "-"
              << (date.tm_mon + 1) << "-"
              << date.tm_mday << std::endl;
    std::cout << dataObject->get_general_info()->get_data_type() << std::endl;
    std::cout << dataObject->get_general_info()->get_pseudodata() << std::endl;
    std::cout << dataObject->get_general_info()->get_collaboration() << std::endl;
    std::cout << dataObject->get_general_info()->get_reference() << std::endl;
    std::map<std::string, std::any> conditions = dataObject->get_general_info()->get_conditions();

    for (const auto& pair : conditions) {
        std::cout << pair.first << ": " << std::any_cast<double>(pair.second) << std::endl;
        break;
    }

    std::cout << dataObject->get_general_info()->get_comment() << std::endl;

    std::cout << dataObject->get_correlation()->get_correlation_matrix("corr_matrix1").size() << std::endl;
    std::cout << dataObject->get_correlation()->get_correlation_matrix_labels().at(0) << std::endl;
    std::cout << dataObject->get_correlation()->get_correlation_matrices().size() << std::endl;
    std::map<std::string, std::vector<std::vector<double> > > corrMat =  dataObject->get_correlation()->get_correlation_matrices();
    for(std::map<std::string, std::vector<std::vector<double> > >::const_iterator it = corrMat.begin(); it != corrMat.end(); it++){
        std::cout <<it->second.at(0).at(0) << ' ' << it->second.at(0).at(1) << ' ' << it->second.at(1).at(0) << ' ' << it->second.at(1).at(1) <<std::endl;
    }

    std::cout << dataObject->get_data()->get_data_set("Q2_dep")->get_data_point(0)->get_kinematics_replicas().at(0)->get_values().size() << std::endl;

    // std::cout << dataObject->get_data()->get_data_set_labels().at(0) << std::endl;
    // // std::cout << dataObject->get_data()->get_data_sets().find("Q2_dep")->second << std::endl;
    // std::cout << dataObject->get_data()->get_data_set("Q2_dep")->get_number_of_data_points() << std::endl;
    // std::cout << dataObject->get_data()->get_data_set("Q2_dep")->get_data_point(0)->get_observables_names().at(0) << std::endl;
    // // std::cout << dataObject->get_data()->get_data_set("Q2_dep")->get_data_point(2)->get_observables_sys_uncertainties()->get_uncertainties().size() << std::endl;
    // std::cout << dataObject->get_data()->get_data_set("Q2_dep")->get_data_point(2)->get_observables_sys_uncertainties()->get_uncertainty(0)->get_unc_upper() << std::endl;
    //  std::cout << dataObject->get_data()->get_data_set("Q2_dep")->get_data_point(2)->get_observables_stat_uncertainties()->get_correlation_matrix() << std::endl;
     // std::cout << dataObject->get_data()->get_data_set("Q2_dep")->get_data_point(0)->get_observables_sys_uncertainties_contribution().at(0)->get_number_of_uncertainties() << std::endl;
// std::cout << dataObject->get_data()->get_data_set("Q2_dep")->get_data_point(0)->get_observables_norm_uncertainties_contribution().at(0)->get_number_of_uncertainties() << std::endl;
    // Call the greet method
    // std::string result = wrapper.callMethod("greet");
    // std::cout << "Result from Python: " << result << std::endl;

    return 0;
}

