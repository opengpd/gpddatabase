'''Basic usage of database'''

# =================================

# import module
import gpddatabase

# make a reference to the database
db = gpddatabase.ExclusiveDatabase()

# print availible uuids
print(db.get_uuids())

# load a given datafile
ob = db.get_data_object('9j7gof4d')

# =================================

# make a referenece to general information (metadata)
metadata = ob.get_general_info()

# print:

# date of insertion
print(metadata.get_date())

# data type
print(metadata.get_data_type())

# check if pseudodata
print(metadata.get_pseudodata())

# collaboration
print(metadata.get_collaboration())

# reference
print(metadata.get_reference())

# conditions
print(metadata.get_conditions())

# comment
print(metadata.get_comment())

# =================================

# make a referenece to data
data = ob.get_data()

# print labels of availible datasets
print(data.get_data_set_labels())

# make a referenece to a given data set
data_set = data.get_data_set('Q2_dep')

# print the number of data points
print(data_set.get_number_of_data_points())

# make a referenece to the first point
point = data_set.get_data_point(0)

# print:

# names of kinematic variables
print(point.get_kinematics_names())

# units associated to kinematic variables
print(point.get_kinematics_units())

# values of kinematic variables
print(point.get_kinematics_values())

# make a referenece to a set of statistical uncertainties related to kinematic variables
kinUnc = point.get_kinematics_uncertainties()
# print the number of uncertainties stored in the set
# (here the same as the number of kinematic variables)
print(kinUnc.get_number_of_uncertainties())
# print the correlation matrix between the uncertainties
print(kinUnc.get_correlation_matrix())
# make a referenece to the first uncertainty in the set
# (here corresponding to the first kinematic variable)
kinUnc0 = kinUnc.get_uncertainty(0)
# print info if uncertainty asymmetric
print(kinUnc0.is_asymmetric())
# print uncertainty (will trigger error if uncertainty asymmetric)
print(kinUnc0.get_unc())
# print 'lower' value of uncertainty
print(kinUnc0.get_unc_lower())
# print 'upper' value of uncertainty
print(kinUnc0.get_unc_upper())

# make a referenece to bins of kinematic variables
kinBins = point.get_kinematics_bins()
# print bin limits corresponding to the first kinematic variable
print("min:", kinBins[0].get_min(), " max: ", kinBins[0].get_max())

# make a referenece to a set of values of kinematic variables given by replicas
# used in the related analysis
kinReplicas = point.get_kinematics_replicas()
# print values corresponding to the first kinematic variable
print(kinReplicas[0].get_values())

# print:

# names of observables
print(point.get_observables_names())

# units of observables
print(point.get_observables_units())

# values of observables
print(point.get_observables_values())

# make a referenece to a set of statistical uncertainties related to observables
# use this set as demonstrated for kinematics
obsStatUnc = point.get_observables_stat_uncertainties()

# make a referenece to a set of systematic uncertainties related to observables
# use this set as demonstrated for kinematics
obsSysUnc = point.get_observables_sys_uncertainties()

# make a referenece to a set of normalisation uncertainties related to observables
# use this set as demonstrated for kinematics
obsNormUnc = point.get_observables_norm_uncertainties()

# labels of contributions to systematic uncertainties of observables
print(point.get_observables_sys_uncertainties_contribution_labels())

# make a referenece to a list of sets of contributions to systematic uncertainties
# the lenght of this list corresponds to the number of contributions
obsSysUncContrib = point.get_observables_sys_uncertainties_contribution()
# print label and corresponding value of systematic uncertainty
# corresponding to the first observable and the second contribution
print(
	point.get_observables_sys_uncertainties_contribution_labels()[1], ": ",
	obsSysUncContrib[0].get_uncertainty(1).get_unc()
)

# labels of contributions to normalisation uncertainties of observables
print(point.get_observables_norm_uncertainties_contribution_labels())

# make a referenece to a list of sets of contributions to normalisation uncertainties
# the lenght of this list corresponds to the number of contributions
obsNormUncContrib = point.get_observables_norm_uncertainties_contribution()

# make a referenece to a set of values of observables given by replicas
# used in the related analysis
# use this set as demonstrated for kinematics
obsReplicas = point.get_observables_replicas()
