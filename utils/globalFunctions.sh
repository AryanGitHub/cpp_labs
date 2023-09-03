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

getTotalNumberOfDirectories(){

    # Function: getTotalNumberOfDirectories
    # Description: This function takes an existing Directory Path and returns number of Directories inside given Directory Path.
    # Arguments:
    #   $1 - Existing Directory Path
    # Returns: Number 

    local ret="$(ls -l $1 | grep -c ^d)"
    echo "$ret"
}

applyClangFormatToAllCAndCPPFiles(){
    # Function: applyClangFormatToAllCAndCPPFiles
    # Description: This function takes an existing Directory Path of an experiment and make app c and cpp files in the given clang-format
    # Arguments:
    #   $1 - Existing Directory Path of Experiment
    # Returns: None

    local directoryPath="$1"
    find "$directoryPath" -type f -name "*.c" -o -name "*.cpp"  | while read fname
    do
        clang-format -style=Microsoft -i ${fname}
    done
    return 0
}

