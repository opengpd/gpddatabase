#include "../include/Utility.h"

#include <iostream>
#include <datetime.h>
#include <numpy/arrayobject.h>

namespace gpddatabase{

namespace Utility{

bool PyObjectToBool(PyObject* pObj, bool destroyOrigin) {
    return bool(PyObjectToInteger(pObj, destroyOrigin));
}

int PyObjectToInteger(PyObject* pObj, bool destroyOrigin) {

    int result = 0;

    if (PyLong_Check(pObj)) {
        result = PyLong_AsLong(pObj);
    } else {
        std::cerr << "error: " << __func__ << ": provided PyObject is not an integer" << std::endl;
        PyErr_Print();
        exit(0);
    }

    if(destroyOrigin) Py_DECREF(pObj);

    return result;
}

double PyObjectToDouble(PyObject* pObj, bool destroyOrigin) {

    double result = 0.;

    if (PyFloat_Check(pObj)) {
        result = PyFloat_AsDouble(pObj);
    } else {
        std::cerr << "error: " << __func__ << ": provided PyObject is not a float" << std::endl;
        PyErr_Print();
        exit(0);
    }

    if(destroyOrigin) Py_DECREF(pObj);

    return result;
}

std::string PyObjectToString(PyObject* pObj, bool destroyOrigin) {

    std::string result;

    if (PyUnicode_Check(pObj)) {

        const char* cStr = PyUnicode_AsUTF8(pObj);

        if (cStr) {
            result = std::string(cStr);
        } else {
            PyErr_Print();
            std::cerr << "error: " << __func__ << ": failed to convert PyObject to string" << std::endl;
            exit(0);
        }
    } else {
        std::cerr << "error: " << __func__ << ": provided PyObject is not a string" << std::endl;
        exit(0);
    }

    if(destroyOrigin) Py_DECREF(pObj);

    return result;
}

std::tm PyObjectToDate(PyObject* pObj, bool destroyOrigin) {

    PyDateTime_IMPORT;

    std::tm date = {};

    if (PyDate_Check(pObj)) {

        int year = PyDateTime_GET_YEAR(pObj);
        int month = PyDateTime_GET_MONTH(pObj);
        int day = PyDateTime_GET_DAY(pObj);

        date.tm_year = year - 1900;  // tm_year is years since 1900
        date.tm_mon = month - 1;     // tm_mon is months since January [0-11]
        date.tm_mday = day;          // tm_mday is day of the month [1-31]
    } else {
        std::cerr << "error: " << __func__ << ": provided PyObject is not a date" << std::endl;
        exit(0);
    }

    if(destroyOrigin) Py_DECREF(pObj);

    return date;
}

std::any PyObjectToAny(PyObject* pObj, bool destroyOrigin){

    std::any result;

    if (PyLong_Check(pObj)) {
        result = PyLong_AsLong(pObj);
    }
    else if(PyFloat_Check(pObj)){
        result = PyFloat_AsDouble(pObj);
    }else if(PyUnicode_Check(pObj)){

        const char* cStr = PyUnicode_AsUTF8(pObj);

        if (cStr) {
            result = std::string(cStr);
        } else {
            PyErr_Print();
            std::cerr << "error: " << __func__ << ": failed to convert PyObject to string" << std::endl;
            exit(0);
        }
    } else {
        std::cerr << "error: " << __func__ << ": provided PyObject is not an integer, double nor string" << std::endl;
        PyErr_Print();
        exit(0);
    }

    if(destroyOrigin) Py_DECREF(pObj);

    return result;
}

std::vector<double> PyListToVectorDouble(PyObject* pObj, bool destroyOrigin) {

    std::vector<double> result;

    if (PyList_Check(pObj)) {

        Py_ssize_t size = PyList_Size(pObj);

        for (Py_ssize_t i = 0; i < size; ++i) {
            result.emplace_back(PyObjectToDouble(PyList_GetItem(pObj, i), false));
        }
    } else {
        std::cerr << "error: " << __func__ << ": provided PyObject is not a list" << std::endl;
        exit(0);
    }

    if(destroyOrigin) Py_DECREF(pObj);

    return result;
}

std::vector<std::string> PyListToVectorString(PyObject* pObj, bool destroyOrigin) {

    std::vector<std::string> result;

    if (PyList_Check(pObj)) {

        Py_ssize_t size = PyList_Size(pObj);

        for (Py_ssize_t i = 0; i < size; ++i) {
            result.emplace_back(PyObjectToString(PyList_GetItem(pObj, i), false));
        }
    } else {
        std::cerr << "error: " << __func__ << ": provided PyObject is not a list" << std::endl;
        exit(0);
    }

    if(destroyOrigin) Py_DECREF(pObj);

    return result;
}

std::map<std::string, std::any> PyDictToMapAny(PyObject* pObj, bool destroyOrigin) {

    std::map<std::string, std::any> result;

    if (PyDict_Check(pObj)) {

        PyObject* pKey = nullptr;
        PyObject* pValue = nullptr;
        Py_ssize_t pos = 0;

        while (PyDict_Next(pObj, &pos, &pKey, &pValue)) {
            
            std::string key = PyObjectToString(pKey, false);
            std::any value = PyObjectToAny(pValue, false);

            result[key] = value;
        }
    } else {
        std::cerr << "error: " << __func__ << ": provided PyObject is not a dictionary" << std::endl;
        exit(0);
    }

    if(destroyOrigin) Py_DECREF(pObj);

    return result;
}


std::map<std::string, std::vector<std::vector<double> > > PyDictToMapMatrix(PyObject* pObj, bool destroyOrigin){

    std::map<std::string, std::vector<std::vector<double> > > result;

    if (PyDict_Check(pObj)) {

        PyObject* pKey = nullptr;
        PyObject* pValue = nullptr;
        Py_ssize_t pos = 0;

        while (PyDict_Next(pObj, &pos, &pKey, &pValue)) {
            
            std::string key = Utility::PyObjectToString(pKey, false);
            std::vector<std::vector<double> > value = Utility::NumPyMatrixToMatrix(pValue, false);

            result[key] = value;
        }
    } else {
        std::cerr << "error: " << __func__ << ": provided PyObject is not a dictionary" << std::endl;
        exit(0);
    }

    if(destroyOrigin) Py_DECREF(pObj);

    return result;
}

std::vector<std::vector<double> > NumPyMatrixToMatrix(PyObject* pObj, bool destroyOrigin) {

    std::vector<std::vector<double> > result;

    _import_array();

    PyArrayObject* np_array = reinterpret_cast<PyArrayObject*>(PyArray_FROM_OF(pObj, NPY_ARRAY_C_CONTIGUOUS));

    if (! np_array) {
        PyErr_Print();
        std::cerr << "error: " << __func__ << ": provided PyObject is not a NumPyMatrix" << std::endl;
        exit(0);
    }

    double* data = static_cast<double*>(PyArray_DATA(np_array));
    int rows = PyArray_DIM(np_array, 0);
    int cols = PyArray_DIM(np_array, 1);

    result = std::vector<std::vector<double> >(rows, std::vector<double>(cols));

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            result[i][j] = data[i * cols + j];
        }
    }

    Py_DECREF(np_array);

    if(destroyOrigin) Py_DECREF(pObj);

    return result;
}


PyObject* executeFunction(PyObject* pInstance, const std::string& methodName, PyObject* pArgs){

    PyObject* pResult = nullptr;

    PyObject* pMethod = PyObject_GetAttrString(pInstance, methodName.c_str());

    if (pMethod && PyCallable_Check(pMethod)) {

        pResult = PyObject_CallObject(pMethod, pArgs);

        Py_DECREF(pMethod);

    } else {
        if (PyErr_Occurred()) PyErr_Print();
        std::cerr << "error: " << __func__ << ": cannot find method " << "get_uuids" << std::endl;
        exit(0);
    }

    return pResult;
}

};

};