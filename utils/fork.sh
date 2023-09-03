#!/bin/bash

# Filename: fork.sh 
# Description: This Bash script is used to fork (copy) the experiment to the "on_going" experiments directory. The forked experiment is automatically named.

# Usage: ./utils/fork.sh  ARGUMENTS
# Arguments:
#   $1 - the path to experiment directory to be forked.

currentBashFileDirectoryPath=$(dirname  "$0")
source "$currentBashFileDirectoryPath/globalVariables.sh" #importing globalVariables
source "$currentBashFileDirectoryPath/globalFunctions.sh" #importing globalFunctions

toBeForkedExperimentDirectory="$1"
newExperimentDirectoryPath="$(getNewExperimentDirectoryPath)"
cp -r "$toBeForkedExperimentDirectory" "$newExperimentDirectoryPath"

