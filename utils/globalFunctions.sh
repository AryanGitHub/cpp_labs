#!/bin/bash
currentBashFileDirectoryPath=$(dirname  "$0")
source "$currentBashFileDirectoryPath/globalVariables.sh" #importing globalVariables

getNewExperimentDirectoryPath(){
    local unix_time="$(date +%s)"
    local newExperimentDirectoryPath="$onGoingExperimentsDirectoryPath/$unix_time"
    echo "$newExperimentDirectoryPath"
}
