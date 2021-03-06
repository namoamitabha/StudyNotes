# A sample Makefile for building Google Test and using it in user
# tests.  Please tweak it to suit your environment and project.  You
# may want to move it to your project's root directory.
#
# SYNOPSIS:
#
#   make [all]  - makes everything.
#   make TARGET - makes the given target.
#   make clean  - removes all files generated by make.

# Please tweak the following variable definitions as needed by your
# project, except GTEST_HEADERS, which you can use in your own targets
# but shouldn't modify.

# Points to the root of Google Test, relative to where this file is.
# Remember to tweak this if you move this file.
GTEST_DIR = /home/angelo/bin/gtest

# Where to find user code.
USER_DIR = ../samples

# Flags passed to the preprocessor.
# Set Google Test's header directory as a system directory, such that
# the compiler doesn't generate warnings in Google Test headers.
CPPFLAGS += -isystem $(GTEST_DIR)/include

# Flags passed to the C++ compiler.
CXXFLAGS += -g -Wall -Wextra -pthread

# All tests produced by this Makefile.  Remember to add new tests you
# created to the list.
#TESTS = sample1_unittest unittest01
TESTS = ctype_tests.out

# All Google Test headers.  Usually you shouldn't change this
# definition.
GTEST_HEADERS = $(GTEST_DIR)/include/gtest/*.h \
                $(GTEST_DIR)/include/gtest/internal/*.h

CTYPEOBJ = xctype.o isdigit.o \
		isalnum.o isalpha.o iscntrl.o isgraph.o \
		islower.o isprint.o ispunct.o isspace.o \
		isupper.o isxdigit.o tolower.o toupper.o \
		xtolower.o xtoupper.o

# House-keeping build targets.

all : $(TESTS)

clean :
	rm -f $(TESTS) *.o

realclean :
	rm -f $(TESTS) *.o *.a

test :
	./$(TESTS)

# Builds gtest.a and gtest_main.a.

# Usually you shouldn't tweak such internal variables, indicated by a
# trailing _.
GTEST_SRCS_ = $(GTEST_DIR)/src/*.cc $(GTEST_DIR)/src/*.h $(GTEST_HEADERS)

# For simplicity and to avoid depending on Google Test's
# implementation details, the dependencies specified below are
# conservative and not optimized.  This is fine as Google Test
# compiles fast and for ordinary users its source rarely changes.
gtest-all.o : $(GTEST_SRCS_)
	$(CXX) $(CPPFLAGS) -I$(GTEST_DIR) $(CXXFLAGS) -c \
            $(GTEST_DIR)/src/gtest-all.cc

gtest_main.o : $(GTEST_SRCS_)
	$(CXX) $(CPPFLAGS) -I$(GTEST_DIR) $(CXXFLAGS) -c \
            $(GTEST_DIR)/src/gtest_main.cc

gtest.a : gtest-all.o
	$(AR) $(ARFLAGS) $@ $^

gtest_main.a : gtest-all.o gtest_main.o
	$(AR) $(ARFLAGS) $@ $^

# Builds a sample test.  A test should link with either gtest.a or
# gtest_main.a, depending on whether it defines its own main()
# function.

sample1.o : $(USER_DIR)/sample1.cc $(USER_DIR)/sample1.h $(GTEST_HEADERS)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $(USER_DIR)/sample1.cc

sample1_unittest.o : $(USER_DIR)/sample1_unittest.cc \
                     $(USER_DIR)/sample1.h $(GTEST_HEADERS)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $(USER_DIR)/sample1_unittest.cc

sample1_unittest : sample1.o sample1_unittest.o gtest_main.a
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -lpthread $^ -o $@

xctype.o : xctype.c ctype0.h
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c xctype.c

isdigit.o : isdigit.c ctype0.h
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c isdigit.c

isalnum.o : isalnum.c ctype0.h
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c isalnum.c

isalpha.o : isalpha.c ctype0.h
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c isalpha.c

iscntrl.o : iscntrl.c ctype0.h
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c iscntrl.c

isgraph.o : isgraph.c ctype0.h
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c isgraph.c

islower.o : islower.c ctype0.h
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c islower.c

isprint.o : isprint.c ctype0.h
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c isprint.c

ispunct.o : ispunct.c ctype0.h
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c ispunct.c

isspace.o : isspace.c ctype0.h
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c isspace.c

isupper.o : isupper.c ctype0.h
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c isupper.c

isxdigit.o : isxdigit.c ctype0.h
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c isxdigit.c

xtolower.o : xtolower.c ctype0.h
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c xtolower.c

tolower.o : tolower.c ctype0.h
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c tolower.c

xtoupper.o : xtoupper.c ctype0.h
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c xtoupper.c

toupper.o : toupper.c ctype0.h
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c toupper.c

ctype_tests.o : ctype_tests.c ctype0.h
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c ctype_tests.c

ctype_tests.out : ctype_tests.o $(CTYPEOBJ) gtest_main.a
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -lpthread $^ -o $@
