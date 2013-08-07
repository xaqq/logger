#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Environment
MKDIR=mkdir
CP=cp
GREP=grep
NM=nm
CCADMIN=CCadmin
RANLIB=ranlib
CC=gcc
CCC=g++
CXX=g++
FC=gfortran
AS=as

# Macros
CND_PLATFORM=GNU-Linux-x86
CND_DLIB_EXT=so
CND_CONF=Release
CND_DISTDIR=dist
CND_BUILDDIR=build

# Include project Makefile
include Makefile

# Object Directory
OBJECTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}

# Object Files
OBJECTFILES= \
	${OBJECTDIR}/_ext/56749130/ALogger.o \
	${OBJECTDIR}/_ext/56749130/DefaultFilter.o \
	${OBJECTDIR}/_ext/56749130/DefaultFormatter.o \
	${OBJECTDIR}/_ext/56749130/StdoutLogger.o


# C Compiler Flags
CFLAGS=

# CC Compiler Flags
CCFLAGS=
CXXFLAGS=

# Fortran Compiler Flags
FFLAGS=

# Assembler Flags
ASFLAGS=

# Link Libraries and Options
LDLIBSOPTIONS=

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/liblogger.a

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/liblogger.a: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${RM} ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/liblogger.a
	${AR} -rv ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/liblogger.a ${OBJECTFILES} 
	$(RANLIB) ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/liblogger.a

${OBJECTDIR}/_ext/56749130/ALogger.o: /home/xaqq/logger/logger/ALogger.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/56749130
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/56749130/ALogger.o /home/xaqq/logger/logger/ALogger.cpp

${OBJECTDIR}/_ext/56749130/DefaultFilter.o: /home/xaqq/logger/logger/DefaultFilter.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/56749130
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/56749130/DefaultFilter.o /home/xaqq/logger/logger/DefaultFilter.cpp

${OBJECTDIR}/_ext/56749130/DefaultFormatter.o: /home/xaqq/logger/logger/DefaultFormatter.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/56749130
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/56749130/DefaultFormatter.o /home/xaqq/logger/logger/DefaultFormatter.cpp

${OBJECTDIR}/_ext/56749130/StdoutLogger.o: /home/xaqq/logger/logger/StdoutLogger.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/56749130
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/56749130/StdoutLogger.o /home/xaqq/logger/logger/StdoutLogger.cpp

# Subprojects
.build-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}
	${RM} ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/liblogger.a

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
