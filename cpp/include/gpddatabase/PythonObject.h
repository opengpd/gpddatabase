#ifndef PYTHONOBJECT_H
#define PYTHONOBJECT_H

#include <Python.h>

namespace gpddatabase{

class PythonObject {

public:

    virtual ~PythonObject();

protected:

    PythonObject(PyObject* pyObject);

    PyObject* m_pPyObject;
};

};

#endif