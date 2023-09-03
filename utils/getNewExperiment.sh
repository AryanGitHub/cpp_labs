#!/bin/bash

currentBashFileDirectoryPath=$(dirname  "$0")
source "$currentBashFileDirectoryPath/globalVariables.sh" #importing globalVariables

unix_time="$(date +%s)"
newExperimentDirectoryPath="$onGoingExperimentsDirectoryPath/$unix_time"
mkdir "$newExperimentDirectoryPath"
cp "$layoutsDirectoryPath/basic_layout.cpp" "$newExperimentDirectoryPath/experiment.cpp"
