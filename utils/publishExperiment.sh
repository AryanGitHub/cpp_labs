#!/bin/bash

# Filename: publishExperiment.sh
# Description: This Bash script  used to move experiment from "on_going" to experiments folder. It is automatically named when its moved.

# Usage: ./utils/publishExperiment.sh  ARGUMENTS
# Arguments:
#   $1 - the path to experiment directory in the "on_going" folder.

currentBashFileDirectoryPath=$(dirname  "$0")
source "$currentBashFileDirectoryPath/globalVariables.sh" #importing globalVariables
source "$currentBashFileDirectoryPath/globalFunctions.sh" #importing globalFunctions

onGoingExperimentPath="$1"

newExperimentNumber="$(getTotalNumberOfDirectories $experimentsDirectoryPath)"
newPublishExperimentDirectoryPath="$experimentsDirectoryPath/experiment_$newExperimentNumber"
mv "$onGoingExperimentPath" "$newPublishExperimentDirectoryPath"
