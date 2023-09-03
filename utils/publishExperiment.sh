#!/bin/bash

currentBashFileDirectoryPath=$(dirname  "$0")
source "$currentBashFileDirectoryPath/globalVariables.sh" #importing globalVariables

onGoingExperimentPath="$1"

getTotalNumberOfDirectories(){
    local ret="$(ls -l $1 | grep -c ^d)"
    echo "$ret"
}

newExperimentNumber="$(getTotalNumberOfDirectories $experimentsDirectoryPath)"
newPublishExperimentDirectoryPath="$experimentsDirectoryPath/experiment_$newExperimentNumber"
mv "$onGoingExperimentPath" "$newPublishExperimentDirectoryPath"
