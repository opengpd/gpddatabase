# Adding new data 

Writing and then using your own data file requires knowing [the format used](data_format.html). In addition, you need to add your new data file to the collection of files already used by the library, or specify a new location that the library will consider.

The default location of the data files is the `data` directory. To find it, you need to know where the gpddatabase library has been installed on your system. If you installed it with pip3 (see [the installation instructions](installation.html)), you can check this by running:
```bash
pip3 show gpddatabase
```
If you cloned the project on your own, you probably specified the library location in `$PYTHONPATH`. Therefore, check:
```bash
echo $PYTHONPATH
```

Alternatively, you can specify a new location where the library will search for data files. In such a case, do this (see also [the bacis usage](basic_usage.html)):
```python

# import module
import gpddatabase

# make a reference to the database
db = gpddatabase.ExclusiveDatabase()

# append new location (locations are separated by ':')
db.set_path_to_databse(db.get_path_to_databse() + ":" + "/path/to/your/location")

```
The use of `set_path_to_database()` will trigger the reloading of the database so that new files can be discovered.

When writing a new data file, you may need to define a new type, such as an observable name. The types are defined via YAML files (which can be easily edited) and are also located in the aforementioned `data` directory. For instance, see `gpddatabase/data/types/observable_types.yaml` ([online version](https://github.com/opengpd/gpddatabase/blob/main/gpddatabase/data/types/observable_types.yaml)).

Alternatively, instead of modifying the default files, you can work on copies, specifying their location like this:
```python
# import module
import gpddatabase

# make a reference to the database
db = gpddatabase.ExclusiveDatabase()

# specify location
db.set_path_to_unit_group_types("/path/to/your/unit_group_types.yaml")
db.set_path_to_unit_types("/path/to/your/unit_types.yaml")
db.set_path_to_variable_types("/path/to/your/variable_types.yaml")
db.set_path_to_data_types("/path/to/your/data_types.yaml")
db.set_path_to_observable_types("/path/to/your/observable_types.yaml")

```

Validation of a new file should be performed in two steps. First, the general data format should be checked against the JSON schema available at `data/schema_datafile.json` ([online version](https://github.com/opengpd/gpddatabase/blob/main/test/schema_datafile.json)). For this purpose, it is convenient to use the `test/test_schema.py` script, for example as follows:
```bash
cd test
python3 test_schema.py your_new_data_file.yaml schema_datafile.json
```
The `test` directory also contains JSON schema files for the YAML files that define the aforementioned types. Additional validation is performed by the `gpddatabase` library itself, which specifically checks whether relevant strings can be translated into types and whether the stored data is consistent in terms of the number of values in interconnected fields. It is therefore important to check whether `gpddatabase` library can process (use) a new file, as described in [the basic usage](basic_usage.html). 

When your new data file(s) is ready and you would like to share it with others by adding it to the next official release of the library, create a new branch and pull request at [https://github.com/opengpd/gpddatabase](https://github.com/opengpd/gpddatabase).
