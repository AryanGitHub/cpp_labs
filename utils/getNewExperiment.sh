#!/bin/bash

currentBashFileDirectoryPath=$(dirname  "$0")
source "$currentBashFileDirectoryPath/globalVariables.sh" #importing globalVariables
source "$currentBashFileDirectoryPath/globalFunctions.sh" #importing globalFunctions

newExperimentDirectoryPath="$(getNewExperimentDirectoryPath)"
mkdir "$newExperimentDirectoryPath"
cp "$layoutsDirectoryPath/basic_layout.cpp" "$newExperimentDirectoryPath/experiment.cpp"
