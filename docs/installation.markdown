# Installation 

The library can be used in both Python and C++ projects. Follow the instructions based on your choice.

## Python

For Python open a terminal and use `pip3` package manager:
```bash
pip3 install gpddatabase
```
Alternatively, you can clone the project with git and then update your $PYTHONPATH so that the related module can be found by your python interpreter:
```bash
# clone the project
git clone git@github.com:opengpd/gpddatabase.git

# install dependencies 
cd gpddatabase
pip3 install -r requirements.txt

# set $PYTHONPATH
# for bash-like shells:
export PYTHONPATH="$PWD:$PYTHONPATH" 
# for csh-like shells:
# setenv PYTHONPATH "$PWD:$PYTHONPATH" 
```
Other options, like using different protocols or downloading a zip package, are also possible. 

After installing the package, check if it works as expected. Open your python interpreter,
```
python3
```
and try to load the module, and print out the files available in the database:

```python
import gpddatabase
database = gpddatabase.ExclusiveDatabase()
print(database.get_uuids())
```

## C++

For C++, start by installing or cloning and setting up the python module as described above. Then, you need to compile the library responsible for wrapping the python code. The compilation is managed by CMake.
```bash
# clone the project (if not done so far)
git clone git@github.com:opengpd/gpddatabase.git

# go to the directory containing the wrapper library
cd gpddatabase/cpp

# build the library
cd build
cmake .. 
# if you want to install the library in a custom location
# cmake .. -DCMAKE_INSTALL_PREFIX=/your/install/prefix
make

# install the headers and library in a default location on your system (admin rights may be required), 
# or in a custom location (if you set CMAKE_INSTALL_PREFIX variable)
make install
``` 

To use the headers and library (the latter compiled in the previous step), you can again utilize CMake. The example C++ project demonstrates how this can be done:
```bash
# clone the project (if not done so far)
git clone git@github.com:opengpd/gpddatabase.git

# go to the directory containing example c++ project
cd gpddatabase/example/cpp

# build the project
cd build
cmake .. 
# if you installed the library in a custom location use
# cmake .. -DGPDDATABASE_INSTALATION=/your/install/prefix
make

# run 
cd ..
./bin/gpddatabase
```