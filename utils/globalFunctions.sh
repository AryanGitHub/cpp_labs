#!/bin/bash

# Filename: globalFunctions.sh
# Description: This Bash script is included in other scripts to provide global scope functions. It should be included after "globalVariable.sh" script, as this script uses it.


currentBashFileDirectoryPath=$(dirname  "$0")
source "$currentBashFileDirectoryPath/globalVariables.sh" #importing globalVariables

getNewExperimentDirectoryPath(){

    # Function: getNewExperimentDirectoryPath
    # Description: This function generates a random non repeating Directory Path and returns it. The Directory DO NOT EXISTS by calling this function, and the function does not create it. The path is inside the Directory in "$onGoingExperimentsDirectoryPath".
    # Arguments:
    #   NONE
    # Returns: Directory Path

    local unix_time="$(date +%s)"
    local newExperimentDirectoryPath="$onGoingExperimentsDirectoryPath/$unix_time"
    echo "$newExperimentDirectoryPath"
}
