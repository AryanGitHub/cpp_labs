#!/bin/bash

# Filename: publishExperiment.sh
# Description: This Bash script  used to move experiment from "on_going" to experiments folder. It is automatically named when its moved.

# Usage: ./utils/publishExperiment.sh  ARGUMENTS
# Arguments:
#   $1 - the path to experiment directory in the "on_going" folder.

currentBashFileDirectoryPath=$(dirname  "$0")
source "$currentBashFileDirectoryPath/globalVariables.sh" #importing globalVariables

onGoingExperimentPath="$1"

getTotalNumberOfDirectories(){

    # Function: getTotalNumberOfDirectories
    # Description: This function takes an existing Directory Path and returns number of Directories inside given Directory Path.
    # Arguments:
    #   $1 - Existing Directory Path
    # Returns: Number 

    local ret="$(ls -l $1 | grep -c ^d)"
    echo "$ret"
}

newExperimentNumber="$(getTotalNumberOfDirectories $experimentsDirectoryPath)"
newPublishExperimentDirectoryPath="$experimentsDirectoryPath/experiment_$newExperimentNumber"
mv "$onGoingExperimentPath" "$newPublishExperimentDirectoryPath"
