#!/bin/bash

dirs=(arg aco)
counter=0

for dir in ${dirs[@]}
do
    files=$(find $dir -iname "*.o")
    for file in ${files[@]}
    do
        rm $file
        echo "REMOVED: " $file
        counter=$(($counter+1))
    done
done

if [ $counter -gt 0 ]; then
    echo "Removed $counter files."
else
    echo "No file removed."
fi
