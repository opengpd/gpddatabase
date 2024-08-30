#include "../include/PythonObject.h"

#include <iostream>

PythonObject::PythonObject(PyObject* pyObject){

	if(pyObject == nullptr){

		std::cerr << "error: " << __func__ << ": null pointer" << std::endl;
		exit(0);
	}

	m_pPyObject = pyObject;
}

PythonObject::~PythonObject(){

	if(m_pPyObject != nullptr){
	
		Py_DECREF(m_pPyObject);
		m_pPyObject = nullptr;
	}
}