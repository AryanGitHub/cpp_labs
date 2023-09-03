#!/bin/bash

currentBashFileDirectoryPath=$(dirname  "$0")
source "$currentBashFileDirectoryPath/globalVariables.sh" #importing globalVariables
source "$currentBashFileDirectoryPath/globalFunctions.sh" #importing globalFunctions

toBeForkedExperimentDirectory="$1"
newExperimentDirectoryPath="$(getNewExperimentDirectoryPath)"
cp -r "$toBeForkedExperimentDirectory" "$newExperimentDirectoryPath"

