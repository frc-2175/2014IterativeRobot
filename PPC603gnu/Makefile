# Wind River Workbench generated Makefile.
# Do not edit!!!
#
# The file ".wrmakefile" is the template used by the Wind River Workbench to
# generate the makefiles of this project. Add user-specific build targets and
# make rules only(!) in this project's ".wrmakefile" file. These will then be
# automatically dumped into the makefiles.

WIND_HOME := $(subst \,/,$(WIND_HOME))
WIND_BASE := $(subst \,/,$(WIND_BASE))
WIND_USR := $(subst \,/,$(WIND_USR))

all : pre_build main_all post_build

_clean ::
	@echo "make: removing targets and objects of `pwd`"

TRACE=0
TRACEON=$(TRACE:0=@)
TRACE_FLAG=$(TRACEON:1=)

MAKEFILE := Makefile

FLEXIBLE_BUILD := 1

BUILD_SPEC = PPC603gnu
DEBUG_MODE = 1
ifeq ($(DEBUG_MODE),1)
MODE_DIR := Debug
else
MODE_DIR := NonDebug
endif
OBJ_DIR := .
WS_ROOT_DIR := C:/WindRiver/workspace
PRJ_ROOT_DIR := $(WS_ROOT_DIR)/2014IterativeRobot



#Global Build Macros
PROJECT_TYPE = DKM
DEFINES = 
EXPAND_DBG = 0


#BuildSpec specific Build Macros
VX_CPU_FAMILY = ppc
CPU = PPC603
TOOL_FAMILY = gnu
TOOL = gnu
TOOL_PATH = 
CC_ARCH_SPEC = -mcpu=603 -mstrict-align -mno-implicit-fp -mlongcall
LIBPATH = 
LIBS = 

IDE_INCLUDES = -I$(WIND_BASE)/target/h -I$(WIND_BASE)/target/h/WPILib -I$(WIND_BASE)/target/h/wrn/coreip 

IDE_LIBRARIES = $(WIND_BASE)/target/lib/WPILib.a 

IDE_DEFINES = 



#BuildTool flags
ifeq ($(DEBUG_MODE),1)
DEBUGFLAGS_C-Compiler = -g
DEBUGFLAGS_C++-Compiler = -g
DEBUGFLAGS_Linker = -g
DEBUGFLAGS_Partial-Image-Linker = 
DEBUGFLAGS_Librarian = 
DEBUGFLAGS_Assembler = -g
else
DEBUGFLAGS_C-Compiler = -O2 -fstrength-reduce -fno-builtin
DEBUGFLAGS_C++-Compiler = -O2 -fstrength-reduce -fno-builtin
DEBUGFLAGS_Linker = -O2 -fstrength-reduce -fno-builtin
DEBUGFLAGS_Partial-Image-Linker = 
DEBUGFLAGS_Librarian = 
DEBUGFLAGS_Assembler = -O2 -fstrength-reduce -fno-builtin
endif


#Project Targets
PROJECT_TARGETS = 2014IterativeRobot/$(MODE_DIR)/2014IterativeRobot.out


#Rules

# 2014IterativeRobot
ifeq ($(DEBUG_MODE),1)
2014IterativeRobot/$(MODE_DIR)/% : DEBUGFLAGS_C-Compiler = -g
2014IterativeRobot/$(MODE_DIR)/% : DEBUGFLAGS_C++-Compiler = -g
2014IterativeRobot/$(MODE_DIR)/% : DEBUGFLAGS_Linker = -g
2014IterativeRobot/$(MODE_DIR)/% : DEBUGFLAGS_Partial-Image-Linker = 
2014IterativeRobot/$(MODE_DIR)/% : DEBUGFLAGS_Librarian = 
2014IterativeRobot/$(MODE_DIR)/% : DEBUGFLAGS_Assembler = -g
else
2014IterativeRobot/$(MODE_DIR)/% : DEBUGFLAGS_C-Compiler = -O2 -fstrength-reduce -fno-builtin
2014IterativeRobot/$(MODE_DIR)/% : DEBUGFLAGS_C++-Compiler = -O2 -fstrength-reduce -fno-builtin
2014IterativeRobot/$(MODE_DIR)/% : DEBUGFLAGS_Linker = -O2 -fstrength-reduce -fno-builtin
2014IterativeRobot/$(MODE_DIR)/% : DEBUGFLAGS_Partial-Image-Linker = 
2014IterativeRobot/$(MODE_DIR)/% : DEBUGFLAGS_Librarian = 
2014IterativeRobot/$(MODE_DIR)/% : DEBUGFLAGS_Assembler = -O2 -fstrength-reduce -fno-builtin
endif
2014IterativeRobot/$(MODE_DIR)/% : IDE_INCLUDES = -I$(WIND_BASE)/target/h -I$(WIND_BASE)/target/h/WPILib -I$(WIND_BASE)/target/h/wrn/coreip 
2014IterativeRobot/$(MODE_DIR)/% : IDE_LIBRARIES = $(WIND_BASE)/target/lib/WPILib.a 
2014IterativeRobot/$(MODE_DIR)/% : IDE_DEFINES = 
2014IterativeRobot/$(MODE_DIR)/% : PROJECT_TYPE = DKM
2014IterativeRobot/$(MODE_DIR)/% : DEFINES = 
2014IterativeRobot/$(MODE_DIR)/% : EXPAND_DBG = 0
2014IterativeRobot/$(MODE_DIR)/% : VX_CPU_FAMILY = ppc
2014IterativeRobot/$(MODE_DIR)/% : CPU = PPC603
2014IterativeRobot/$(MODE_DIR)/% : TOOL_FAMILY = gnu
2014IterativeRobot/$(MODE_DIR)/% : TOOL = gnu
2014IterativeRobot/$(MODE_DIR)/% : TOOL_PATH = 
2014IterativeRobot/$(MODE_DIR)/% : CC_ARCH_SPEC = -mcpu=603 -mstrict-align -mno-implicit-fp -mlongcall
2014IterativeRobot/$(MODE_DIR)/% : LIBPATH = 
2014IterativeRobot/$(MODE_DIR)/% : LIBS = 
2014IterativeRobot/$(MODE_DIR)/% : OBJ_DIR := 2014IterativeRobot/$(MODE_DIR)

2014IterativeRobot/$(MODE_DIR)/Objects/2014IterativeRobot/Atlas.o : $(PRJ_ROOT_DIR)/Atlas.cpp $(FORCE_FILE_BUILD)
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)ccppc $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -Wall  -MD -MP -mlongcall $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"


2014IterativeRobot/$(MODE_DIR)/Objects/2014IterativeRobot/Drive.o : $(PRJ_ROOT_DIR)/Drive.cpp $(FORCE_FILE_BUILD)
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)ccppc $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -Wall  -MD -MP -mlongcall $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"


2014IterativeRobot/$(MODE_DIR)/Objects/2014IterativeRobot/RollerBar.o : $(PRJ_ROOT_DIR)/RollerBar.cpp $(FORCE_FILE_BUILD)
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)ccppc $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -Wall  -MD -MP -mlongcall $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"


2014IterativeRobot/$(MODE_DIR)/Objects/2014IterativeRobot/Shooter.o : $(PRJ_ROOT_DIR)/Shooter.cpp $(FORCE_FILE_BUILD)
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)ccppc $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -Wall  -MD -MP -mlongcall $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"


OBJECTS_2014IterativeRobot = 2014IterativeRobot/$(MODE_DIR)/Objects/2014IterativeRobot/Atlas.o \
	 2014IterativeRobot/$(MODE_DIR)/Objects/2014IterativeRobot/Drive.o \
	 2014IterativeRobot/$(MODE_DIR)/Objects/2014IterativeRobot/RollerBar.o \
	 2014IterativeRobot/$(MODE_DIR)/Objects/2014IterativeRobot/Shooter.o

2014IterativeRobot/$(MODE_DIR)/2014IterativeRobot.out : $(OBJECTS_2014IterativeRobot)
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@";rm -f "$@";nmppc $(OBJECTS_2014IterativeRobot) $(IDE_LIBRARIES) | tclsh $(WIND_BASE)/host/resource/hutils/tcl/munch.tcl -c ppc > $(OBJ_DIR)/ctdt.c; $(TOOL_PATH)ccppc $(DEBUGFLAGS_Linker) $(CC_ARCH_SPEC) -fdollars-in-identifiers -Wall $(ADDED_CFLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES)  -o $(OBJ_DIR)/ctdt.o -c $(OBJ_DIR)/ctdt.c; $(TOOL_PATH)ccppc -r -nostdlib -Wl,-X -T $(WIND_BASE)/target/h/tool/gnu/ldscripts/link.OUT -o "$@" $(OBJ_DIR)/ctdt.o $(OBJECTS_2014IterativeRobot) $(IDE_LIBRARIES) $(LIBPATH) $(LIBS)  $(ADDED_LIBPATH) $(ADDED_LIBS) && if [ "$(EXPAND_DBG)" = "1" ]; then plink "$@";fi

2014IterativeRobot/$(MODE_DIR)/2014IterativeRobot_compile_file : $(FILE) ;

_clean :: 2014IterativeRobot/$(MODE_DIR)/2014IterativeRobot_clean

2014IterativeRobot/$(MODE_DIR)/2014IterativeRobot_clean : 
	$(TRACE_FLAG)if [ -d "2014IterativeRobot" ]; then cd "2014IterativeRobot"; rm -rf $(MODE_DIR); fi

force : 

DEP_FILES := 2014IterativeRobot/$(MODE_DIR)/Objects/2014IterativeRobot/Atlas.d 2014IterativeRobot/$(MODE_DIR)/Objects/2014IterativeRobot/Drive.d 2014IterativeRobot/$(MODE_DIR)/Objects/2014IterativeRobot/RollerBar.d \
	 2014IterativeRobot/$(MODE_DIR)/Objects/2014IterativeRobot/Shooter.d
-include $(DEP_FILES)



-include $(PRJ_ROOT_DIR)/*.makefile

-include *.makefile

main_all : external_build $(PROJECT_TARGETS)
	@echo "make: built targets of `pwd`"

# entry point for extending the build
external_build ::
	@echo ""

# main entry point for pre processing prior to the build
pre_build :: $(PRE_BUILD_STEP) generate_sources
	@echo ""

# entry point for generating sources prior to the build
generate_sources ::
	@echo ""

# main entry point for post processing after the build
post_build :: $(POST_BUILD_STEP) deploy_output
	@echo ""

# entry point for deploying output after the build
deploy_output ::
	@echo ""

clean :: external_clean $(CLEAN_STEP) _clean

# entry point for extending the build clean
external_clean ::
	@echo ""
