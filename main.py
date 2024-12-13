'''Main.'''

# import pylint

# from beans.UnitGroupTypes import UnitGroupTypes
# from beans.UnitTypes import UnitTypes
# from beans.ParticleTypes import ParticleTypes

# from exclusive_database.ExclusiveDatabase import ExclusiveDatabase
import gpddatabase

# genericType = GenericType("unit_group_type.yaml")
# unitGroupTypes = UnitGroupTypes('unit_group_types.yaml')
# unitTypes = UnitTypes('unit_types.yaml')

# unitGroupTypes.check_type('EV2')
# print(processTypes.get_paths())

#### get reference to the database
exclusiveDatabase = gpddatabase.ExclusiveDatabase()
#exclusiveDatabase2 = ExclusiveDatabase()

#print out the list of available data files (identified by uuids)
print("Availible data files are:")
print(exclusiveDatabase.get_uuids())

# print(ExclusiveDatabase().get_data_types().get_description('experiment'))

# print(ExclusiveDatabase().get_particle_types().get_description('pi0'))
# print(ExclusiveDatabase().get_particle_types().get_particle('pi0').pdgid)

# print(ExclusiveDatabase().get_data_types().get_required_type('DVMP'))

# print(ExclusiveDatabase().get_observable_types().get_description('ALL'))

# print(ExclusiveDatabase().get_uuids())

#### load a given data file
#ob = exclusiveDatabase.get_data_object('9j7gof4d')
#ob = exclusiveDatabase.get_data_object('aaabbb11')
#ob = exclusiveDatabase.get_data_object('9jggof4d')
#ob = exclusiveDatabase.get_data_object('y0va3bey') #GFFs Lattice
#ob = exclusiveDatabase.get_data_object('75ueQoQw') #COMPASS
#ob = exclusiveDatabase.get_data_object('6pDJMSey') #CLAS_4.25GeV
#ob = exclusiveDatabase.get_data_object('SYmZ5Qka') #CLAS_5.7GeV
#ob = exclusiveDatabase.get_data_object('RQncbKtk') #CLAS_5.75GeV 
#ob = exclusiveDatabase.get_data_object('AvF5daeP') #CLAS_5.77GeV_1 
#ob = exclusiveDatabase.get_data_object('A6Pgo5TE') #CLAS_5.77GeV_2 
ob = exclusiveDatabase.get_data_object('ob8hLTm2') #CLAS_5.88GeV 
#ob = exclusiveDatabase.get_data_object('vGAKAf7P') #CLAS_5.932GeV 
#ob = exclusiveDatabase.get_data_object('QfefWWW2') #CLAS_10.6GeV 
#ob = exclusiveDatabase.get_data_object('PusMstKs') #CLAS_10.2GeV 
#ob = exclusiveDatabase.get_data_object('TKhscLcB') #HallA_3.35GeV_1
#ob = exclusiveDatabase.get_data_object('EqbtDRkv') #HallA_3.35GeV_2
#ob = exclusiveDatabase.get_data_object('mJXCLi4G') #HallA_4.45GeV_1
#ob = exclusiveDatabase.get_data_object('nfPvTM2c') #HallA_4.45GeV_2
#ob = exclusiveDatabase.get_data_object('msa6dh9v') #HallA_5.55GeV 
#ob = exclusiveDatabase.get_data_object('EhPp8CP4') #HallA_5.55GeV 
#ob = exclusiveDatabase.get_data_object('BJ84iv8s') #HALLA_5.7572GeV_1
#ob = exclusiveDatabase.get_data_object('AtY8o7Ej') #HALLA_5.7572GeV_2
#ob = exclusiveDatabase.get_data_object('gzHYjVoV') #HALLA_5.7572GeV_3
#ob = exclusiveDatabase.get_data_object('5qKfNxjh') #HALLA_5.7572GeV_X2
#ob = exclusiveDatabase.get_data_object('j5LQNpkG') #HALLA_5.7572GeV_X3
#ob = exclusiveDatabase.get_data_object('Cb6meE7Q') #HallA_Neutron_4.45GeV
#ob = exclusiveDatabase.get_data_object('bmTzHHvg') #HallA_Neutron_5.55GeV
#ob = exclusiveDatabase.get_data_object('K66wYqfW') #HERA 2005
#ob = exclusiveDatabase.get_data_object('BKA7rRbD') #HERA 2008
#ob = exclusiveDatabase.get_data_object('TqukKh6n') #HERA 2009
#ob = exclusiveDatabase.get_data_object('NvMm42PD') #HERMES 2001
#ob = exclusiveDatabase.get_data_object('3gYp9R4P') #HERMES 2006
#ob = exclusiveDatabase.get_data_object('ux2MBpLG') #HERMES 2008
#ob = exclusiveDatabase.get_data_object('4J9Kdnpp') #HERMES 2009_1
#ob = exclusiveDatabase.get_data_object('6NAva8yz') #HERMES 2009_2
#ob = exclusiveDatabase.get_data_object('ZKVXNMBf') #HERMES 2010
#ob = exclusiveDatabase.get_data_object('uwTJg8RC') #HERMES 2011
#ob = exclusiveDatabase.get_data_object('PEdMnbi6') #HERMES 2012_1
#ob = exclusiveDatabase.get_data_object('MxfVfC9H') #HERMES 2012_2

# print(ob.get_general_info().get_comment())
# print(ob.get_general_info().get_conditions())

#### print out the list of available data sets (identified by labels)
print("Availible data sets in the selected data file are:")
print(ob.get_data().get_data_set_labels())


#### print out the number of kinematic points available in a given data set 
print("Availible number of points:")
#print(ob.get_data().get_data_set('Q2_dep').get_number_of_data_points())
#print(ob.get_data().get_data_set('Q2_dep').get_data_point(0).get_observables_norm_uncertainties().
#    get_uncertainty(0).get_unc_lower())
#print(ob.get_data().get_data_set('t_dep').get_number_of_data_points())
#print(ob.get_data().get_data_set('xB_dep').get_number_of_data_points())
print(ob.get_data().get_data_set('phi_dep').get_number_of_data_points())
#print(ob.get_data().get_data_set('none_dep').get_number_of_data_points())
#print(ob.get_data().get_data_set('none_dep').get_number_of_data_points())
#print(ob.get_data().get_data_set('GFF_E_skew_0_cut3').get_number_of_data_points())

#### make a reference to 0th kinematic point
#dataPoint = ob.get_data().get_data_set('Q2_dep').get_data_point(0)
#dataPoint = ob.get_data().get_data_set('t_dep').get_data_point(0)
#dataPoint = ob.get_data().get_data_set('xB_dep').get_data_point(0)
dataPoint = ob.get_data().get_data_set('phi_dep').get_data_point(0)
#dataPoint = ob.get_data().get_data_set('none_dep').get_data_point(0)
#dataPoint = ob.get_data().get_data_set('GFF_E_skew_0_cut3').get_data_point(0)

#### print out the names of kinematic variables and corresponding values for 0’th point
print("Kinematics in the selected point:")
print(dataPoint.get_kinematics_names())
print(dataPoint.get_kinematics_values())
print(dataPoint.get_kinematics_units())

#### print out the names of observables and corresponding values for 0’th point 
print("Observables in the selected point:")
print(dataPoint.get_observables_names())
print(dataPoint.get_observables_values())
print(dataPoint.get_observables_units())

#exclusiveDatabase.convert_to_markdown('website')

# print(ob.get_correlation().get_correlation_matrix('xx'))
# print(ob.get_correlation().get_correlation_matrices())

# print(ob.get_data().get_data_sets())
# print(ob.get_data().get_data_set('Q2_dep').get_kinematics().get_replicas()[0][0].get_values())
# print(ob.get_data().get_data_set('Q2_dep').get_kinematics().get_uncertainties()[1].get_correlation_matrix())
# print(ob.get_data().get_data_set('Q2_dep').get_observables().get_stat_uncertainties()[0].get_uncertainties()[0].get_unc_lower())
# print(ob.get_data().get_data_set('Q2_dep').get_observables().get_norm_uncertainties_contribution())
# print(ob.get_data().get_data_set('Q2_dep').get_observables().get_sys_uncertainties_contribution())
