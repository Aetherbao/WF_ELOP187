###########################################################################
## Makefile generated for component 'rtwshared'. 
## 
## Makefile     : rtwshared.mk
## Generated on : Wed Apr 02 08:54:31 2025
## Final product: ./rtwshared.lib
## Product type : static library
## 
###########################################################################

###########################################################################
## MACROS
###########################################################################

# Macro Descriptions:
# PRODUCT_NAME            Name of the system to build
# MAKEFILE                Name of this makefile
# COMPILER_COMMAND_FILE   Compiler command listing model reference header paths
# CMD_FILE                Command file
# MODELLIB                Static library target

PRODUCT_NAME              = rtwshared
MAKEFILE                  = rtwshared.mk
MATLAB_ROOT               = C:/PROGRA~1/MATLAB/R2023a
MATLAB_BIN                = C:/PROGRA~1/MATLAB/R2023a/bin
MATLAB_ARCH_BIN           = $(MATLAB_BIN)/win64
START_DIR                 = P:/work/01_Platform_Standard_Model_2023a_V2.2/01_Platform_Standard_Model_2023a_V2.2_13_5/foc_platform/releases/src_Temp/code
SOLVER                    = 
SOLVER_OBJ                = 
CLASSIC_INTERFACE         = 0
TGT_FCN_LIB               = None
MODEL_HAS_DYNAMICALLY_LOADED_SFCNS = 
RELATIVE_PATH_TO_ANCHOR   = ../../..
COMPILER_COMMAND_FILE     = rtwshared_comp.rsp
CMD_FILE                  = rtwshared.rsp
C_STANDARD_OPTS           = -fwrapv
CPP_STANDARD_OPTS         = -fwrapv
MODELLIB                  = rtwshared.lib

###########################################################################
## TOOLCHAIN SPECIFICATIONS
###########################################################################

# Toolchain Name:          MinGW64 | gmake (64-bit Windows)
# Supported Version(s):    6.x
# ToolchainInfo Version:   2023a
# Specification Revision:  1.0
# 
#-------------------------------------------
# Macros assumed to be defined elsewhere
#-------------------------------------------

# C_STANDARD_OPTS
# CPP_STANDARD_OPTS
# MINGW_ROOT
# MINGW_C_STANDARD_OPTS

#-----------
# MACROS
#-----------

WARN_FLAGS            = -Wall -W -Wwrite-strings -Winline -Wstrict-prototypes -Wnested-externs -Wpointer-arith -Wcast-align
WARN_FLAGS_MAX        = $(WARN_FLAGS) -Wcast-qual -Wshadow
CPP_WARN_FLAGS        = -Wall -W -Wwrite-strings -Winline -Wpointer-arith -Wcast-align
CPP_WARN_FLAGS_MAX    = $(CPP_WARN_FLAGS) -Wcast-qual -Wshadow
MW_EXTERNLIB_DIR      = $(MATLAB_ROOT)/extern/lib/win64/mingw64
SHELL                 = %SystemRoot%/system32/cmd.exe

TOOLCHAIN_SRCS = 
TOOLCHAIN_INCS = 
TOOLCHAIN_LIBS = -lws2_32

#------------------------
# BUILD TOOL COMMANDS
#------------------------

# C Compiler: GNU C Compiler
CC_PATH = $(MINGW_ROOT)
CC = "$(CC_PATH)/gcc"

# Linker: GNU Linker
LD_PATH = $(MINGW_ROOT)
LD = "$(LD_PATH)/g++"

# C++ Compiler: GNU C++ Compiler
CPP_PATH = $(MINGW_ROOT)
CPP = "$(CPP_PATH)/g++"

# C++ Linker: GNU C++ Linker
CPP_LD_PATH = $(MINGW_ROOT)
CPP_LD = "$(CPP_LD_PATH)/g++"

# Archiver: GNU Archiver
AR_PATH = $(MINGW_ROOT)
AR = "$(AR_PATH)/ar"

# MEX Tool: MEX Tool
MEX_PATH = $(MATLAB_ARCH_BIN)
MEX = "$(MEX_PATH)/mex"

# Download: Download
DOWNLOAD =

# Execute: Execute
EXECUTE = $(PRODUCT)

# Builder: GMAKE Utility
MAKE_PATH = $(MINGW_ROOT)
MAKE = "$(MAKE_PATH)/mingw32-make.exe"


#-------------------------
# Directives/Utilities
#-------------------------

CDEBUG              = -g
C_OUTPUT_FLAG       = -o
LDDEBUG             = -g
OUTPUT_FLAG         = -o
CPPDEBUG            = -g
CPP_OUTPUT_FLAG     = -o
CPPLDDEBUG          = -g
OUTPUT_FLAG         = -o
ARDEBUG             =
STATICLIB_OUTPUT_FLAG =
MEX_DEBUG           = -g
RM                  = @del
ECHO                = @echo
MV                  = @move
RUN                 =

#--------------------------------------
# "Faster Runs" Build Configuration
#--------------------------------------

ARFLAGS              = ruvs
CFLAGS               = -c $(MINGW_C_STANDARD_OPTS) -m64 \
                       -O3 -fno-loop-optimize -fno-aggressive-loop-optimizations
CPPFLAGS             = -c $(CPP_STANDARD_OPTS) -m64 \
                       -O3 -fno-loop-optimize -fno-aggressive-loop-optimizations
CPP_LDFLAGS          =  -static -m64
CPP_SHAREDLIB_LDFLAGS  = -shared -Wl,--no-undefined \
                         -Wl,--out-implib,$(notdir $(basename $(PRODUCT))).lib
DOWNLOAD_FLAGS       =
EXECUTE_FLAGS        =
LDFLAGS              =  -static -m64
MEX_CPPFLAGS         =
MEX_CPPLDFLAGS       =
MEX_CFLAGS           =
MEX_LDFLAGS          =
MAKE_FLAGS           = -f $(MAKEFILE)
SHAREDLIB_LDFLAGS    = -shared -Wl,--no-undefined \
                       -Wl,--out-implib,$(notdir $(basename $(PRODUCT))).lib



###########################################################################
## OUTPUT INFO
###########################################################################

PRODUCT = ./rtwshared.lib
PRODUCT_TYPE = "static library"
BUILD_TYPE = "Model Reference Library"

###########################################################################
## INCLUDE PATHS
###########################################################################

INCLUDES_BUILDINFO = 

INCLUDES = $(INCLUDES_BUILDINFO)

###########################################################################
## DEFINES
###########################################################################

DEFINES_BUILD_ARGS = -DINTEGER_CODE=1
DEFINES_CUSTOM = 

DEFINES = $(DEFINES_BUILD_ARGS) $(DEFINES_CUSTOM)

###########################################################################
## SOURCE FILES
###########################################################################

SRCS = $(START_DIR)/slprj/ert/_sharedutils/const_params.c $(START_DIR)/slprj/ert/_sharedutils/div_nde_s32_floor.c $(START_DIR)/slprj/ert/_sharedutils/look1_iu16lu32n16ts16D_2s4GBl96.c $(START_DIR)/slprj/ert/_sharedutils/look1_iu8lu32n16ts16Ds32_binlcs.c $(START_DIR)/slprj/ert/_sharedutils/look2_is16lu32n16tu16_binlcse.c $(START_DIR)/slprj/ert/_sharedutils/mul_ssu32_hiSR.c $(START_DIR)/slprj/ert/_sharedutils/mul_ssu32_loSR.c $(START_DIR)/slprj/ert/_sharedutils/mul_wide_su32.c $(START_DIR)/slprj/ert/_sharedutils/look2_iu8s16lu32n16tu16_binlcse.c $(START_DIR)/slprj/ert/_sharedutils/div_nzp_repeat_u32.c $(START_DIR)/slprj/ert/_sharedutils/look1_is16lu32n32ys16n_eAC3J1UD.c $(START_DIR)/slprj/ert/_sharedutils/look1_iu16lu32n16tu8_binlcse.c

ALL_SRCS = $(SRCS)

###########################################################################
## OBJECTS
###########################################################################

OBJS = const_params.obj div_nde_s32_floor.obj look1_iu16lu32n16ts16D_2s4GBl96.obj look1_iu8lu32n16ts16Ds32_binlcs.obj look2_is16lu32n16tu16_binlcse.obj mul_ssu32_hiSR.obj mul_ssu32_loSR.obj mul_wide_su32.obj look2_iu8s16lu32n16tu16_binlcse.obj div_nzp_repeat_u32.obj look1_is16lu32n32ys16n_eAC3J1UD.obj look1_iu16lu32n16tu8_binlcse.obj

ALL_OBJS = $(OBJS)

###########################################################################
## PREBUILT OBJECT FILES
###########################################################################

PREBUILT_OBJS = 

###########################################################################
## LIBRARIES
###########################################################################

LIBS = 

###########################################################################
## SYSTEM LIBRARIES
###########################################################################

SYSTEM_LIBS = 

###########################################################################
## ADDITIONAL TOOLCHAIN FLAGS
###########################################################################

#---------------
# C Compiler
#---------------

CFLAGS_BASIC = $(DEFINES) $(INCLUDES) @$(COMPILER_COMMAND_FILE)

CFLAGS += $(CFLAGS_BASIC)

#-----------------
# C++ Compiler
#-----------------

CPPFLAGS_BASIC = $(DEFINES) $(INCLUDES) @$(COMPILER_COMMAND_FILE)

CPPFLAGS += $(CPPFLAGS_BASIC)

#---------------------
# MEX C++ Compiler
#---------------------

MEX_CPP_Compiler_BASIC =  @$(COMPILER_COMMAND_FILE)

MEX_CPPFLAGS += $(MEX_CPP_Compiler_BASIC)

#-----------------
# MEX Compiler
#-----------------

MEX_Compiler_BASIC =  @$(COMPILER_COMMAND_FILE)

MEX_CFLAGS += $(MEX_Compiler_BASIC)

###########################################################################
## INLINED COMMANDS
###########################################################################


MINGW_C_STANDARD_OPTS = $(C_STANDARD_OPTS)


###########################################################################
## PHONY TARGETS
###########################################################################

.PHONY : all build clean info prebuild download execute


all : build
	@echo "### Successfully generated all binary outputs."


build : prebuild $(PRODUCT)


prebuild : 


download : $(PRODUCT)


execute : download


###########################################################################
## FINAL TARGET
###########################################################################

#---------------------------------
# Create a static library         
#---------------------------------

$(PRODUCT) : $(OBJS) $(PREBUILT_OBJS)
	@echo "### Creating static library "$(PRODUCT)" ..."
	$(AR) $(ARFLAGS)  $(PRODUCT) @$(CMD_FILE)
	@echo "### Created: $(PRODUCT)"


###########################################################################
## INTERMEDIATE TARGETS
###########################################################################

#---------------------
# SOURCE-TO-OBJECT
#---------------------

%.obj : %.c
	$(CC) $(CFLAGS) -o "$@" "$<"


%.obj : %.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.obj : $(RELATIVE_PATH_TO_ANCHOR)/%.c
	$(CC) $(CFLAGS) -o "$@" "$<"


%.obj : $(RELATIVE_PATH_TO_ANCHOR)/%.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.obj : $(START_DIR)/%.c
	$(CC) $(CFLAGS) -o "$@" "$<"


%.obj : $(START_DIR)/%.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


const_params.obj : $(START_DIR)/slprj/ert/_sharedutils/const_params.c
	$(CC) $(CFLAGS) -o "$@" "$<"


div_nde_s32_floor.obj : $(START_DIR)/slprj/ert/_sharedutils/div_nde_s32_floor.c
	$(CC) $(CFLAGS) -o "$@" "$<"


look1_iu16lu32n16ts16D_2s4GBl96.obj : $(START_DIR)/slprj/ert/_sharedutils/look1_iu16lu32n16ts16D_2s4GBl96.c
	$(CC) $(CFLAGS) -o "$@" "$<"


look1_iu8lu32n16ts16Ds32_binlcs.obj : $(START_DIR)/slprj/ert/_sharedutils/look1_iu8lu32n16ts16Ds32_binlcs.c
	$(CC) $(CFLAGS) -o "$@" "$<"


look2_is16lu32n16tu16_binlcse.obj : $(START_DIR)/slprj/ert/_sharedutils/look2_is16lu32n16tu16_binlcse.c
	$(CC) $(CFLAGS) -o "$@" "$<"


mul_ssu32_hiSR.obj : $(START_DIR)/slprj/ert/_sharedutils/mul_ssu32_hiSR.c
	$(CC) $(CFLAGS) -o "$@" "$<"


mul_ssu32_loSR.obj : $(START_DIR)/slprj/ert/_sharedutils/mul_ssu32_loSR.c
	$(CC) $(CFLAGS) -o "$@" "$<"


mul_wide_su32.obj : $(START_DIR)/slprj/ert/_sharedutils/mul_wide_su32.c
	$(CC) $(CFLAGS) -o "$@" "$<"


look2_iu8s16lu32n16tu16_binlcse.obj : $(START_DIR)/slprj/ert/_sharedutils/look2_iu8s16lu32n16tu16_binlcse.c
	$(CC) $(CFLAGS) -o "$@" "$<"


div_nzp_repeat_u32.obj : $(START_DIR)/slprj/ert/_sharedutils/div_nzp_repeat_u32.c
	$(CC) $(CFLAGS) -o "$@" "$<"


look1_is16lu32n32ys16n_eAC3J1UD.obj : $(START_DIR)/slprj/ert/_sharedutils/look1_is16lu32n32ys16n_eAC3J1UD.c
	$(CC) $(CFLAGS) -o "$@" "$<"


look1_iu16lu32n16tu8_binlcse.obj : $(START_DIR)/slprj/ert/_sharedutils/look1_iu16lu32n16tu8_binlcse.c
	$(CC) $(CFLAGS) -o "$@" "$<"


###########################################################################
## DEPENDENCIES
###########################################################################

$(ALL_OBJS) : rtw_proj.tmw


###########################################################################
## MISCELLANEOUS TARGETS
###########################################################################

info : 
	@echo "### PRODUCT = $(PRODUCT)"
	@echo "### PRODUCT_TYPE = $(PRODUCT_TYPE)"
	@echo "### BUILD_TYPE = $(BUILD_TYPE)"
	@echo "### INCLUDES = $(INCLUDES)"
	@echo "### DEFINES = $(DEFINES)"
	@echo "### ALL_SRCS = $(ALL_SRCS)"
	@echo "### ALL_OBJS = $(ALL_OBJS)"
	@echo "### LIBS = $(LIBS)"
	@echo "### MODELREF_LIBS = $(MODELREF_LIBS)"
	@echo "### SYSTEM_LIBS = $(SYSTEM_LIBS)"
	@echo "### TOOLCHAIN_LIBS = $(TOOLCHAIN_LIBS)"
	@echo "### CFLAGS = $(CFLAGS)"
	@echo "### LDFLAGS = $(LDFLAGS)"
	@echo "### SHAREDLIB_LDFLAGS = $(SHAREDLIB_LDFLAGS)"
	@echo "### CPPFLAGS = $(CPPFLAGS)"
	@echo "### CPP_LDFLAGS = $(CPP_LDFLAGS)"
	@echo "### CPP_SHAREDLIB_LDFLAGS = $(CPP_SHAREDLIB_LDFLAGS)"
	@echo "### ARFLAGS = $(ARFLAGS)"
	@echo "### MEX_CFLAGS = $(MEX_CFLAGS)"
	@echo "### MEX_CPPFLAGS = $(MEX_CPPFLAGS)"
	@echo "### MEX_LDFLAGS = $(MEX_LDFLAGS)"
	@echo "### MEX_CPPLDFLAGS = $(MEX_CPPLDFLAGS)"
	@echo "### DOWNLOAD_FLAGS = $(DOWNLOAD_FLAGS)"
	@echo "### EXECUTE_FLAGS = $(EXECUTE_FLAGS)"
	@echo "### MAKE_FLAGS = $(MAKE_FLAGS)"


clean : 
	$(ECHO) "### Deleting all derived files ..."
	$(RM) $(subst /,\,$(PRODUCT))
	$(RM) $(subst /,\,$(ALL_OBJS))
	$(ECHO) "### Deleted all derived files."


