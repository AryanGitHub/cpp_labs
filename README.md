# cpp_labs

This repo is for doing and storing small CPP experiments, it's like playing with CPP and storing its results, in a controlled and automated way.
I needed this because there there so many things to play with and witness in CPP!

### **How To Use?** 
There are 3 main commands as of now

> * getNewExperiment.sh To generate new Experiments under experiments/on_going folder.

> * publishExperiment.sh To move the experiment from "on_going" to the experiments folder. It is automatically named when it's moved.
~~It was earlier planned to commit it to git also.~~

> * fork.sh To fork (copy) the experiments to the "on_going" experiments directory. The forked experiment is automatically named.

#### **For ./utils/getNewExperiment.sh**

**SYNOPSIS**
    ./utils/getNewExperiment.sh (no arguments required)
    
----

    
#### **For ./utils/publishExperiment.sh**
**SYNOPSIS**
    ./utils/publishExperiment.sh <existing directory path to the "on_going" experiment.>
**DESCRIPTION**
To move the experiment from "on_going" to the experiments folder. It is automatically named when it's moved.



----

#### **For utils/fork.sh**
**SYNOPSIS**
    utils/fork.sh <existing directory path to the experiment.>
    
**DESCRIPTION**
To fork (copy) the experiment to the "on_going" experiments directory. The forked experiment is automatically named.

----

### **Coding Guidelines**

#### **For C/Cpp files**
Use clange-format Microsoft style.
For that use 
```clang-format -style=Microsoft <path to c/cpp file>```
and to write the change
```clang-format -style=Microsoft -i <path to c/cpp file>```
~~PublishExperiment.sh should automatically do that. Search for all c/cpp files and run this.~~
    
#### **For bash script files**
For every bash script add a comment block having this information.

```
#!/bin/bash
# Filename: my_script.sh
# Description: This Bash script performs a specific task.

# Usage: ./my_script.sh [OPTIONS] ARGUMENTS
# Options:
#   -h, --help     Show this help message and exit.
```

Every function definition adds a comment block having this information.

```
# Function: print_greeting
# Description: This function takes a name as an argument and prints a greeting message.
# Arguments:
#   $1 - The name to greet.
# Returns: None
```


### **Todo**
- [ ] PublishExperiment.sh have these things to
    - [ ] maintain clang-formate for the experiment to be published
    - [ ] add auto-commit feature once published with description extraction
- [ ] Add Make file and build folder for each experiment
- [ ] add Python script to extract tags and tasks for each experiment to be used later.
