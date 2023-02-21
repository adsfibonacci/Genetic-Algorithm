##
# Genetic Algorithm
#
# @file
# @version 0.1

EXECUTABLE = executable

PROJECTFILE = $(or $(wildcard project*.cpp $(EXECUTABLE).cpp), main.cpp)

PATH := /urs/um/gcc-6.2.0/bin:$(PATH)
LD_LIBRARY_PATH := /usr/um/gcc-6.2.0/lib64
LD_RUN_PATH := /usr/um/gcc-6.2.0/lib64

REMOTE_PAHT := eecs281_$(EXECUTABLE)_sync

CXX = g++
CXXFLAGS = -std=c++1z -Wconversion -Wall -Werror -Wextra -pedantic

TESTSOURCES = $(wildcard test*.cpp)
TESTS = $(TESTSOURCES:%.cpp=%)

#Source Files
SOURCES = $(wildcard *.cpp)
SOURCES = $(filter-out $(TESTSOURCES), $(SOURCES))

OBJECTS = $(SOURCES:%.cpp=%.o)

TARBALL = tared.tar.gz
EXCLUDE_FILES = getopt.\?
PERF_FILE = perf.data*

release: CXXFLAGS += -O3 -DNDEBUG
release: $(EXECUTABLE)

debug: CXXFLAGS += -g3 -DDEBUG
debug: $(CXX) $(CXXFLAGS) $(SOURCES) -o $(EXECUTABLE)_debug

profile: CXXFLAGS += -g3 -O3
profile: $(CXX) $(CXXFLAGS) $(SOURCES) -o $(EXECUTABLE)_profile

gprof: CXXFLAGS += -pg
gprof: $(CXXFLAGS) $(CXXFLAGS) $(SOURCES) -o $(EXECUTABLE)_gprof

all: release debug profile gprof

$(EXECUTABLE): $(OBJECTS)
ifeq ($(EXECUTABLE), executable)
	@echo EDIT EXECUTABLE IN MAKEFILE
	@echo create default a.out
	$(CXX) $(CXXFLAGS) $(OBJECTS)
else
	$(CXX) $(CXXFLAGS) $(OBJECTS) -o $(EXECUTABLE)
endif

define make_tests
	ifeq ($$(PROJECTFILE),)
		@echo EDIT PROJECTFILE IN MAKEFILE
		@exit 1
	endif
	SRC = $$(filter-out $$(PROJECTFILE), $$(SOURCES))
	OBJ = $$(SRC:%.cpp=%.o)
	HDR = $$(wildcard *.h *.hpp)
	$(1): CXXFLAGS += -g3 -DDEBUG
	$(1): $$(OBJ) $$(HDR) $(1).cpp
	$$(CXX) $$(CXXFLAGS) $$(OBJ) $(1).cpp -o $(1)
endef
$(foreach test, $(TESTS), $(eval $(call make_tests, $(test))))

alltests: $(TESTS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $*.cpp

clean:
	rm -f $(OBJECTS) $(EXECUTABLE) $(EXECUTABLE)_debug $(EXECUTABLE)_profile $(EXECUTABLE)_gprof
	rm -f $(TESTS) $(TARBALL) $(PERF_FILE)
	rm -Rf *dYSM

TARBALLS = $(filter-out $(TESTSOURCES), $(wildcard Makefile *.h *.hpp *.cpp test*.txt))
$(TARBALL): $(TARBALLS)
	COPYFILE_DISABLE=true tar --exclude=$(EXCLUDE_FILES) -vczf $(TARBALL) $(TARBALLS)
	@echo Tarball Prepared

tared: identifier $(TARBALL)

# end
