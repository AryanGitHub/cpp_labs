srcFolder = .
fileName = $(srcFolder)/experiment

sourceCodeFiles = $(wildcard $(srcFolder)/*.cpp)
objFiles = $(patsubst $(srcFolder)/%.cpp,$(srcFolder)/%.o,$(sourceCodeFiles))
exeFile = $(fileName).exe
buildInfoFile =$(fileName)_buildInfo.txt

flags = -g -Wall
compiler = clang++

$(exeFile):$(objFiles)
	$(compiler) $(flags) $(objFiles) -o $(exeFile)

%.o:%.cpp
	$(compiler) $(flags) -c $< -o $@

printCompilerInfo:
	$(compiler) --version

printSourceCodeFiles: 
	@echo "$(sourceCodeFiles)"

printObjsFiles:
	@echo "$(objFiles)"

clean:
	rm $(objFiles) $(exeFile) $(buildInfoFile)

run:$(exeFile)
	@echo "----------------"
	@echo "compiler = $(compiler)" > $(buildInfoFile) #overwrite if already exist!
	@echo "flags = $(flags)" >> $(buildInfoFile)
	@echo "compilerInfo: " >> $(buildInfoFile)
	$(compiler) --version >> $(buildInfoFile)
	@echo "source_code files: $(sourceCodeFiles)">> $(buildInfoFile)
	@echo "obj files: $(objFiles)" >> $(buildInfoFile)
	@echo "exe file: $(exeFile)" >> $(buildInfoFile)
	@cat $(buildInfoFile)
	@echo "----------------"
	$(exeFile)
#dependency-chain
experiment.o:experiment.cpp
