#!/bin/bash

# Test code against pylint.

echo "[II] Testing pylint"

pylint --rcfile=../.pylintrc ../gpddatabase 

CODE=$?

echo "[II] Exit code by pylint is $CODE"

if [[ $(($CODE & 1)) == 1 ]] || [[ $(($CODE & 2)) == 2 ]]; then
	echo "[EE] Fatal or error detected"
	exit 1
else
	echo "[II] Test assumed successful"
	exit 0
fi 
