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

exclusiveDatabase = gpddatabase.ExclusiveDatabase()
#exclusiveDatabase2 = ExclusiveDatabase()

# print(ExclusiveDatabase().get_data_types().get_description('experiment'))

# print(ExclusiveDatabase().get_particle_types().get_description('pi0'))
# print(ExclusiveDatabase().get_particle_types().get_particle('pi0').pdgid)

# print(ExclusiveDatabase().get_data_types().get_required_type('DVMP'))

# print(ExclusiveDatabase().get_observable_types().get_description('ALL'))

print(exclusiveDatabase.get_uuids())

ob = exclusiveDatabase.get_data_object('9j7gof4d')
# print(ob.get_general_info().get_comment())
print(ob.get_general_info().get_conditions())

# print(ob.get_data().get_data_set_labels())
# print(ob.get_data().get_data_set('Q2_dep').get_number_of_data_points())
# print(ob.get_data().get_data_set('Q2_dep').get_data_point(0).
# 	get_observables_norm_uncertainties().get_uncertainty(0).get_unc_lower())
#print(ob.get_data().get_data_set('Q2_dep').get_data_point(2).
#	get_observables_sys_uncertainties_contribution()[0].get_uncertainties()[1].get_unc())
# exclusiveDatabase.convert_to_markdown('docs')

# print(ob.get_correlation().get_correlation_matrix('xx'))
# print(ob.get_correlation().get_correlation_matrices())

# print(ob.get_data().get_data_sets())
# print(ob.get_data().get_data_set('Q2_dep').get_kinematics().get_replicas()[0][0].get_values())
# print(ob.get_data().get_data_set('Q2_dep').get_kinematics().get_uncertainties()[1].get_correlation_matrix())
# print(ob.get_data().get_data_set('Q2_dep').get_observables().get_stat_uncertainties()[0].get_uncertainties()[0].get_unc_lower())
# print(ob.get_data().get_data_set('Q2_dep').get_observables().get_norm_uncertainties_contribution())
# print(ob.get_data().get_data_set('Q2_dep').get_observables().get_sys_uncertainties_contribution())
