##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Debug
ProjectName            :=rehabilitation
ConfigurationName      :=Debug
WorkspacePath          :=D:/Project/rehabilitation
ProjectPath            :=D:/Project/rehabilitation
IntermediateDirectory  :=./Debug
OutDir                 := $(IntermediateDirectory)
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=cclee
Date                   :=03/09/2017
CodeLitePath           :="C:/Program Files/CodeLite"
LinkerName             :=C:/mingw-w64/x86_64-5.4.0-posix-seh/mingw64/bin/g++.exe
SharedObjectLinkerName :=C:/mingw-w64/x86_64-5.4.0-posix-seh/mingw64/bin/g++.exe -shared -fPIC
ObjectSuffix           :=.o
DependSuffix           :=.o.d
PreprocessSuffix       :=.i
DebugSwitch            :=-g 
IncludeSwitch          :=-I
LibrarySwitch          :=-l
OutputSwitch           :=-o 
LibraryPathSwitch      :=-L
PreprocessorSwitch     :=-D
SourceSwitch           :=-c 
OutputFile             :=$(IntermediateDirectory)/$(ProjectName)
Preprocessors          :=
ObjectSwitch           :=-o 
ArchiveOutputSwitch    := 
PreprocessOnlySwitch   :=-E
ObjectsFileList        :="rehabilitation.txt"
PCHCompileFlags        :=
MakeDirCommand         :=makedir
RcCmpOptions           := 
RcCompilerName         :=C:/mingw-w64/x86_64-5.4.0-posix-seh/mingw64/bin/windres.exe
LinkOptions            :=  
IncludePath            :=  $(IncludeSwitch). $(IncludeSwitch). $(IncludeSwitch)C:/opencv/build/x64/mingw/include 
IncludePCH             := 
RcIncludePath          := 
Libs                   := $(LibrarySwitch)opencv_core330.dll $(LibrarySwitch)opencv_highgui330.dll $(LibrarySwitch)opencv_imgproc330.dll 
ArLibs                 :=  "libopencv_core330.dll.a" "libopencv_highgui330.dll.a" "libopencv_imgproc330.dll.a" 
LibPath                := $(LibraryPathSwitch). $(LibraryPathSwitch)C:/opencv/build/x64/mingw/lib 

##
## Common variables
## AR, CXX, CC, AS, CXXFLAGS and CFLAGS can be overriden using an environment variables
##
AR       := C:/mingw-w64/x86_64-5.4.0-posix-seh/mingw64/bin/ar.exe rcu
CXX      := C:/mingw-w64/x86_64-5.4.0-posix-seh/mingw64/bin/g++.exe
CC       := C:/mingw-w64/x86_64-5.4.0-posix-seh/mingw64/bin/gcc.exe
CXXFLAGS :=  -g -O0 -Wall $(Preprocessors)
CFLAGS   :=  -g -O0 -Wall $(Preprocessors)
ASFLAGS  := 
AS       := C:/mingw-w64/x86_64-5.4.0-posix-seh/mingw64/bin/as.exe


##
## User defined environment variables
##
CodeLiteDir:=C:\Program Files\CodeLite
Objects0=$(IntermediateDirectory)/main.cpp$(ObjectSuffix) $(IntermediateDirectory)/gnuplot_i.cpp$(ObjectSuffix) 



Objects=$(Objects0) 

##
## Main Build Targets 
##
.PHONY: all clean PreBuild PrePreBuild PostBuild MakeIntermediateDirs
all: $(OutputFile)

$(OutputFile): $(IntermediateDirectory)/.d $(Objects) 
	@$(MakeDirCommand) $(@D)
	@echo "" > $(IntermediateDirectory)/.d
	@echo $(Objects0)  > $(ObjectsFileList)
	$(LinkerName) $(OutputSwitch)$(OutputFile) @$(ObjectsFileList) $(LibPath) $(Libs) $(LinkOptions)

MakeIntermediateDirs:
	@$(MakeDirCommand) "./Debug"


$(IntermediateDirectory)/.d:
	@$(MakeDirCommand) "./Debug"

PreBuild:


##
## Objects
##
$(IntermediateDirectory)/main.cpp$(ObjectSuffix): main.cpp $(IntermediateDirectory)/main.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "D:/Project/rehabilitation/main.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/main.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/main.cpp$(DependSuffix): main.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/main.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/main.cpp$(DependSuffix) -MM main.cpp

$(IntermediateDirectory)/main.cpp$(PreprocessSuffix): main.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/main.cpp$(PreprocessSuffix) main.cpp

$(IntermediateDirectory)/gnuplot_i.cpp$(ObjectSuffix): gnuplot_i.cpp $(IntermediateDirectory)/gnuplot_i.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "D:/Project/rehabilitation/gnuplot_i.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/gnuplot_i.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/gnuplot_i.cpp$(DependSuffix): gnuplot_i.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/gnuplot_i.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/gnuplot_i.cpp$(DependSuffix) -MM gnuplot_i.cpp

$(IntermediateDirectory)/gnuplot_i.cpp$(PreprocessSuffix): gnuplot_i.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/gnuplot_i.cpp$(PreprocessSuffix) gnuplot_i.cpp


-include $(IntermediateDirectory)/*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) -r ./Debug/


