'''Main.'''

# from exclusive_database.ExclusiveDatabase import ExclusiveDatabase
import gpddatabase

# get reference
exclusiveDatabase = gpddatabase.ExclusiveDatabase()

# print uuids of availible datafiles
print(exclusiveDatabase.get_uuids())
