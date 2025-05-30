#!/bin/bash

# Test all yaml files against json schema. 

echo "[II] Testing schema"

for i in `ls ../gpddatabase/data | grep -v types`
do

	for j in `find ../gpddatabase/data/$i -name *.yaml`
	do
		RESULT=`python3 test_schema.py $j schema_datafile.json`
		
		if [[ -z $RESULT ]]; then
			echo "[II] File: $j OK"
		else
			echo "[EE] File: $j WRONG"
			echo $RESULT
			exit 1
		fi
	done
done

for i in `find ../gpddatabase/data/types -name *.yaml`
do
	JSON_FILE=schema_`echo $i | sed -e "s/.*\///g" | sed -e "s/\.yaml$//g"`.json
	
	if ! [[ -e $JSON_FILE ]]; then
		echo "[EE] File $JSON_FILE is missing"
		exit 1
	fi

	RESULT=`python3 test_schema.py $i $JSON_FILE`

	if [[ -z $RESULT ]]; then
		echo "[II] File: $i OK"
	else
		echo "[EE] File: $i WRONG"
		echo $RESULT
		exit 1
	fi
done

exit 0
