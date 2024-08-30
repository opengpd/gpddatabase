#include <Python.h>

#include <string>
#include <ctime>
#include <any>
#include <map>
#include <vector>
#include <memory>
#include <iostream>

namespace gpddatabase{

namespace utility{

	bool PyObjectToBool(PyObject* pObj, bool destroyOrigin = true);
	int PyObjectToInteger(PyObject* pObj, bool destroyOrigin = true);
	double PyObjectToDouble(PyObject* pObj, bool destroyOrigin = true);
	std::string PyObjectToString(PyObject* pObj, bool destroyOrigin = true);
	std::tm PyObjectToDate(PyObject* pObj, bool destroyOrigin = true);

	std::any PyObjectToAny(PyObject* pObj, bool destroyOrigin = true);

	std::map<std::string, std::any> PyDictToMapAny(PyObject* pObj, bool destroyOrigin = true);
	std::map<std::string, std::vector<std::vector<double> > > PyDictToMapMatrix(PyObject* pObj, bool destroyOrigin = true);
	std::vector<double> PyListToVectorDouble(PyObject* pObj, bool destroyOrigin = true);
	std::vector<std::string> PyListToVectorString(PyObject* pObj, bool destroyOrigin = true);
	std::vector<std::vector<double> > NumPyMatrixToMatrix(PyObject* pObj, bool destroyOrigin = true);

	PyObject* executeFunction(PyObject* pInstance, const std::string& methodName, PyObject* pArgs = nullptr);

	template<typename T>
	std::map<std::string, std::shared_ptr<T> > PyDictToMapPointer(PyObject* pObj, bool destroyOrigin = true){

		std::map<std::string, std::shared_ptr<T> > result;

	    if (PyDict_Check(pObj)) {

	        PyObject* pKey = nullptr;
	        PyObject* pValue = nullptr;
	        Py_ssize_t pos = 0;

	        while (PyDict_Next(pObj, &pos, &pKey, &pValue)) {
	            
	            std::string key = utility::PyObjectToString(pKey, false);
	            std::shared_ptr<T> value = std::shared_ptr<T>(new T(pValue));

	            result[key] = value;
	        }
	    } else {
	        std::cerr << "error: " << __func__ << ": provided PyObject is not a dictionary" << std::endl;
	        exit(0);
	    }

	    if(destroyOrigin) Py_DECREF(pObj);

	    return result;
	}

	template<typename T>
	std::vector<std::shared_ptr<T>> PyListToVectorPointer(PyObject* pObj, bool destroyOrigin = true){

	    std::vector<std::shared_ptr<T>> result;

	    if (PyList_Check(pObj)) {

	        Py_ssize_t size = PyList_Size(pObj);

	        for (Py_ssize_t i = 0; i < size; ++i) {
	            result.emplace_back(
	                std::shared_ptr<T>(new T(PyList_GetItem(pObj, i)))
	            );
	        }
	    } else {
	        std::cerr << "error: " << __func__ << ": provided PyObject is not a list" << std::endl;
	        exit(0);
	    }

	    if(destroyOrigin) Py_DECREF(pObj);

	    return result;	
	}

};

};