#!/bin/bash

# Filename: getNewExperiment.sh
# Description: This Bash script to generate new Experiment under experiments/on_going directory
# Usage: ./util/getNewExperiment.sh (no arguments are passed)

currentBashFileDirectoryPath=$(dirname  "$0")
source "$currentBashFileDirectoryPath/globalVariables.sh" #importing globalVariables
source "$currentBashFileDirectoryPath/globalFunctions.sh" #importing globalFunctions

newExperimentDirectoryPath="$(getNewExperimentDirectoryPath)"
mkdir "$newExperimentDirectoryPath"
cp "$layoutsDirectoryPath/basic_layout.cpp" "$newExperimentDirectoryPath/experiment.cpp"
